#include "GameModeHammerTime.h"

#include "Renderer/Renderer.h"
#include "Core/Time.h"
#include "Audio/AudioManager.h"
#include "OutPutAndInput/Gameinput.h"

void GameModeHammerTime::Init()
{
	m_CurrentLevel = nullptr;

	m_AllNails.clear();
	m_AllMobile.clear();

	m_StartTime = 0;
	m_NextBlockIndex = 0;
	m_NextNailIndex = 0;
	m_LevelFinished = false;
	m_mobileSpeed = 0;
	m_Scor = 0;


	//手
	m_HandAnimation.Reset();
	m_HandAnimation.SetMode(AnimationMode::Once);
	float rotation = 15.0f;
	m_HandAnimation.AddFrame({
		0,"hand1",50,50,515.73,435,rotation,0.868f,0.927f });

	m_HandAnimation.AddFrame({
		0.05f,"hand2",100,230,359.67f,435,rotation,0.868f,0.927f });

	m_HandAnimation.AddFrame({
		0.1f,"hand3",185,270,361.33f,435,rotation,0.868f,0.927f});


	m_HandAnimation.AddFrame({
		0.20f,"hand2",185,270,361.33f,435,rotation,0.868f,0.927f});


	m_HandSmearAnimation.Reset();
	m_HandSmearAnimation.SetMode(AnimationMode::Once);
	m_HandSmearAnimation.AddFrame({
		0,
		"hand_smear",
		-80,
		-180,
		326,
		435,
		0,
		0,
		0
		});

	m_HandSmearAnimation.AddFrame({
	0.15f,
	"hand_smear",
		-80,
		-150,
	326,
	435,
	0,
	0,
	0
		});


	m_HammerAnimation.Reset();
	m_HammerAnimation.SetMode(AnimationMode::Once);
	m_HammerAnimation.AddFrame({
		0.0f,
		"hammer",
	1085.5f,
	-20,
		499,
		333.67f,
		90,
		1,
		0
		});

	m_HammerAnimation.AddFrame({
	0.08f,
	"hammer",
	1075.5f,
	-20,
		499,
		333.67f,
	0,
	1,
	0
		});
	m_HammerAnimation.AddFrame({
		0.2f,
		"hammer",
	1075.5f,
	-20,
		499,
		333.67f,
		0,
		1,
		0 
		});

	m_HammmerSmearAnimation.Reset();
	m_HammmerSmearAnimation.SetMode(AnimationMode::Once);
	m_HammmerSmearAnimation.AddFrame({
		0.0f,
		"hammer_smear",
		775,
		-60,
		143.67f,
		328.33,
		0,
		1,
		0
		});

	m_HammmerSmearAnimation.AddFrame({
	0.12f,
	"hammer_smear",
		775,
	-40,
	143.67f,
	328.33,
	0,
	1,
	0
		});

	m_HammerPerfectAnimation.Reset();
	m_HammerPerfectAnimation.SetMode(AnimationMode::Once);
	m_HammerPerfectAnimation.AddFrame({
		0.0f,
		"hammer_effect_perfect",
		550,
		290,
	136.33f,
	30.33,
	0,
	0,
	0
		});

	m_HammerPerfectAnimation.AddFrame({
	0.12f,
	"hammer_effect_perfect",
		550,
		290,
	136.33f,
	30.33,
	0,
	0,
	0
		});


	m_HammerAlmostAnimation.Reset();
	m_HammerAlmostAnimation.SetMode(AnimationMode::Once);
	m_HammerAlmostAnimation.AddFrame({
		0.0f,
		"hammer_effect_hit",
		550,
		290,
	136.33f,
	30.33,
	0,
	0,
	0
		});

	m_HammerAlmostAnimation.AddFrame({
	0.12f,
	"hammer_effect_hit",
		550,
		290,
	136.33f,
	30.33,
	0,
	0,
	0
		});


}

void GameModeHammerTime::Play(HammerLevel* lever)
{
	m_CurrentLevel = lever;
	m_StartTime = Time::GetRealtimeSinceStartup();

	float nailFromPosX = 120;
	float nailToPosX = 560;
	m_mobileSpeed = (nailToPosX - nailFromPosX) / ((60.0f / m_CurrentLevel->BPM) * 4.0f);

}

void GameModeHammerTime::Update(float dt)
{
	GenerateNails();
	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;

	float nailFromPosX = 120;
	float nailToPosX = 560;
	if (currentTime >= ( 60.0f / m_CurrentLevel->BPM ) * 200.0f)
	{
		m_mobileSpeed = (nailToPosX - nailFromPosX) / ((60.0f / m_CurrentLevel->BPM) * 8.0f);
		m_CurrentLevel->BeatsPerMeasure = 8.0f;
	}
	

	//按键判断
	CGameInput* input = CGameInput::GetGameInput();
	if (input->GetKeyState(_GI_K_SPACE) == _KS_DC && 0x8001)
	{
		//播放锤子的动画
		m_HammerAnimation.Play();
		m_HammmerSmearAnimation.Play();


		//播放锤子的音效
		//遍历钉子-找到第一个nomal 状态的钉子
		for (NailObject& nail : m_AllNails)
		{
			if (nail.State == NailState::Normal)
			{
				float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
				float perfectTime = beatUnitTime * (nail.BornBetas + m_CurrentLevel->BeatsPerMeasure);
				double hitTime = Time::GetRealtimeSinceStartup() - m_StartTime;
				float diff = hitTime - perfectTime;
				float diffBeat = diff * beatUnitTime;
				if (abs(diffBeat) <= HitJudgmentTimePerfect)
				{
					nail.State = NailState::Perfect;
					m_HammerPerfectAnimation.Play();
					CAudioManager::Get().PlayOnceAudio("SFX_HT_NailHammerHit");
					m_Scor += 2;

				}
				else if (abs(diffBeat) <= HitJudgmentTimeAlmost)
				{
					if (diffBeat > 0)
					{
						nail.State = NailState::AlmostLate;
					}
					else
					{
						nail.State = NailState::AlmostEarly;
					}
					m_HammerAlmostAnimation.Play();
					CAudioManager::Get().PlayOnceAudio("SFX_HT_NailPlace");
					m_Scor += 1;
				}
				break;
			}
		}
	}


	UpdateNails(dt);

	m_HandAnimation.Update(dt);
	m_HandSmearAnimation.Update(dt);
	m_HammerAnimation.Update(dt);
	m_HammmerSmearAnimation.Update(dt);
	m_HammerPerfectAnimation.Update(dt);
	m_HammerAlmostAnimation.Update(dt);
}

void GameModeHammerTime::Render()
{

	Renderer::Clear(220.0f / 255.0f, 222.0f / 255.0f, 198 / 255.0f);

	DrawNails();


	if (m_HandAnimation.IsPlaying())
	{
		m_HandAnimation.Render();
	}
	if (m_HandSmearAnimation.IsPlaying())
	{
		m_HandSmearAnimation.Render();
	}

	CGameInput* input = CGameInput::GetGameInput();
	if (m_HammerAnimation.IsPlaying() || (input->GetKeyState(_GI_K_SPACE) == _KS_DH && m_HammerAnimation.GetTime() > 0))
	{
		m_HammerAnimation.Render();
	}
	if (m_HammmerSmearAnimation.IsPlaying())
	{
 		m_HammmerSmearAnimation.Render();
	}
	if (m_HammerPerfectAnimation.IsPlaying())
	{
		m_HammerPerfectAnimation.Render();
	}
	if (m_HammerAlmostAnimation.IsPlaying())
	{
		m_HammerAlmostAnimation.Render();
	}

	Renderer::DrawTexture("bg_texture", 480, 15, 2500, 579, 0, 0.5f, 1);
	Renderer::DrawTexture("bg_texture", 10, 10, 2500, 579, 0, 1, 0);
	Renderer::DrawTexture("bg_texture", 10, 590, 2500, 579, 0, 1, 0);
	Renderer::DrawTexture("bg_texture", 950, 10, 2500, 579, 0, 0, 0);
	Renderer::DrawTexture("bg_texture", 950, 590, 2500, 579, 0, 0, 0);

	if(m_CurrentLevel->levelName == LevelName::HAMMER_GAME)
	{  
		Renderer::DrawTexture("fg", 0, 0, 960, 960);
	}
	
}

bool GameModeHammerTime::IsDone()
{
	return false;
}

bool GameModeHammerTime::GetLevelFinished()
{
	return m_LevelFinished;
}


float GameModeHammerTime::GetGrades()
{
	return CalculateGrades();
}

void GameModeHammerTime::GenerateNails()
{
	if (m_LevelFinished) return;

	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;

	float nailFromPosX = 120;
	float nailToPosX = 560;

	float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
	HammerBlock block = m_CurrentLevel->Blocks[m_NextBlockIndex];
	float nailBornBeats = block.Nails[m_NextNailIndex];
	float nailBornTime = beatUnitTime * nailBornBeats;

	// 生成平台
	if (m_NextNailIndex == 0 && m_AllMobile.size() == m_NextBlockIndex)
	{
		float mobileFromPosX = 0;
		float mobileToPosX = 120;

		float mobileArriveTime = nailBornTime - (mobileToPosX - mobileFromPosX) / m_mobileSpeed;

		if (currentTime >= (60.0f / m_CurrentLevel->BPM) * 194.0f)
		{
			float m_SecondmobileSpeed = (nailToPosX - nailFromPosX) / ((60.0f / m_CurrentLevel->BPM) * 8.0f);
			mobileArriveTime = nailBornTime - (mobileToPosX - mobileFromPosX) / m_SecondmobileSpeed;
		}

		double elapsedTime = currentTime - mobileArriveTime;
		if (currentTime >= mobileArriveTime)
		{
			float distanceBreat = block.Nails[block.Nails.size() - 1] - block.Nails[0];
		
			float mobileWidth = distanceBreat * beatUnitTime * m_mobileSpeed;

			MobileStation mobile;
			mobile.x = elapsedTime * m_mobileSpeed;
			mobile.MobileWidth = mobileWidth;
			m_AllMobile.push_back(mobile);
		}
	}

	if (currentTime >= nailBornTime)
	{
		NailObject nail;
		nail.x = 120;
		nail.BornBetas = nailBornBeats;
		nail.State = NailState::Normal;

		m_AllNails.push_back(nail);
		//播放动画-手
		m_HandAnimation.Play();
		m_HandSmearAnimation.Play();

		m_NextNailIndex++;
		if (m_NextNailIndex == block.Nails.size())
		{
			m_NextBlockIndex++;
			m_NextNailIndex = 0;
		}

		if (m_NextBlockIndex == m_CurrentLevel->Blocks.size())
		{
			m_LevelFinished = true;
		}
	}
}

void GameModeHammerTime::UpdateNails(float dt)
{

	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;

	//更新移动台的位置

	for (MobileStation& mobile : m_AllMobile)
	{
		mobile.x += m_mobileSpeed * dt;
	}

	// 更新钉子位置
	{
		
		for (NailObject& nail : m_AllNails)
		{
			nail.x += m_mobileSpeed * dt;

			if (nail.State == NailState::Normal)
			{
				float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
			
				float missTime = beatUnitTime * (nail.BornBetas + m_CurrentLevel->BeatsPerMeasure  + HitJudgmentTimeMiss);

				if (currentTime > missTime)
				{
					nail.State = NailState::Miss;

					//音效
					CAudioManager::Get().PlayOnceAudio("SFX_HT_NailMissTilt");
				}
			}
		}
	}

	// 销毁越界的钉子
	for (auto it = m_AllNails.begin(); it != m_AllNails.end(); )
	{
		if (it->x >= 1000)
			it = m_AllNails.erase(it);
		else
			it++;
	}

}

void GameModeHammerTime::DrawNails()
{
	float xOffset = 25.0f;
	float yOffset = 318;    
	for (MobileStation& mobile : m_AllMobile)
	{
		Renderer::DrawTexture("wood_left", mobile.x- mobile.MobileWidth-24 + xOffset, yOffset, 31.5f, 78, 0, 1, 0);
		Renderer::DrawTexture("wood_centre", mobile.x + xOffset - 27, yOffset, mobile.MobileWidth, 78, 0, 1, 0);
		Renderer::DrawTexture("wood_right", mobile.x + xOffset, yOffset, 31.5f, 78, 0, 1, 0);
	}


	for (NailObject& nail : m_AllNails)
	{
		if (nail.State == NailState::Normal)
		{
			Renderer::DrawTexture("nail_normal_1", nail.x, 320, 27, 69.67f, 0, 0.5f, 1.0f);
		}
		else if (nail.State == NailState::Miss)
		{
			Renderer::DrawTexture("nail_normal_1", nail.x, 320, 27, 69.67f, 15, 0.5f, 1.0f);
		}
		else if (nail.State == NailState::Perfect)
		{
			Renderer::DrawTexture("nail_normal_7", nail.x, 320, 28.57f, 8.33f, 0, 0.5f, 1.0f);
		}
		else if (nail.State == NailState::AlmostEarly)
		{
			Renderer::DrawTexture("nail_normal_3", nail.x, 325, 53, 27.33f, 0, 0.88f, 1.0f);
		}
		else if (nail.State == NailState::AlmostLate)
		{
			Renderer::DrawTexture("nail_normal_6", nail.x, 325, 52.33f, 28, 0, 0.13f, 1.0f);
		}
	}
}

float  GameModeHammerTime::CalculateGrades()
{
	float numNails =0;
	for(auto& block : m_CurrentLevel->Blocks)
	{
		numNails += block.Nails.size();
	}
	//m_scoror / 总成绩的比例
	float grades = m_Scor / (numNails * 2);
	return grades;
}

