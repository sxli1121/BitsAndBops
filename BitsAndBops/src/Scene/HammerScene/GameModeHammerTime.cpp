#include "GameModeHammerTime.h"
#include "Renderer/Renderer.h"
#include "OutPutAndInput/Gameinput.h"
#include "Core/Time.h"
#include "Audio/AudioManager.h"

void GameModeHammerTime::Init()
{

	//��
	//m_HandAnimation.SetLength(0.2f);
	m_HandAnimation.SetMode(AnimationMode::Once);
	float rotation = 15.0f;
	m_HandAnimation.AddFrame({
		0,
		"hand1",
		150,
		295,
		267,
		326.25,
		rotation,
		0.868,
		0.927
		});

	m_HandAnimation.AddFrame({
		0.1f,
		"hand2",
		150,
		295,
		267,
		326.25,
		rotation,
		0.868,
		0.927
		});

	m_HandAnimation.AddFrame({
		0.2f,
		"hand3",
		160,
		320,
		267,
		326.25,
		rotation,
		0.868,
		0.927
		});

	m_HandAnimation.AddFrame({
		0.3f,
		"hand3",
		160,
		320,
		267,
		326.25,
		rotation,
		0.868,
		0.927
		});


	m_HammerAnimation.AddFrame({
		0.0f,
		"hammer",
		1000,
		0,
		374,
		250,
		90,
		1,
		0
		});
	m_HammerAnimation.AddFrame({
	0.08f,
	"hammer",
	1000,
	0,
		374,
		250,
	0,
	1,
	0
		});
	m_HammerAnimation.AddFrame({
		0.2f,
		"hammer",
		1000,
		0,
		374,
		250,
		0,
		1,
		0
		});
}

void GameModeHammerTime::Play(HammerLevel* lever)
{
	m_CurrentLevel = lever;
	m_StartTime = Time::GetRealtimeSinceStartup();

	float nailFromPosX = 150;
	float nailToPosX = 700;
	m_mobileSpeed = (nailToPosX - nailFromPosX) / ((60.0f / m_CurrentLevel->BPM) * 4.0f);
	//m_mobileSpeed = 100;
}

void GameModeHammerTime::Update(float dt)
{
	GenerateNails();

	//�����ж�
	CGameInput* input = CGameInput::GetGameInput();
	if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
	{
		//���Ŵ��ӵĶ���
		m_HammerAnimation.Play();

		//���Ŵ��ӵ���Ч
		//��������-�ҵ���һ��nomal ״̬�Ķ���
		for (NailObject& nail : m_AllNails)
		{
			if (nail.State == NailState::Normal)
			{
				float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
				float perfectTime = beatUnitTime * (nail.BornBetas + m_CurrentLevel->BeatsPerMeasure);
				float hitTime = Time::GetRealtimeSinceStartup() - m_StartTime;
				float diff = hitTime - perfectTime;
				float diffBeat = diff * beatUnitTime;
				if (abs(diffBeat) <= HitJudgmentTimePerfect)
				{
					nail.State = NailState::Perfect;
					CAudioManager::Get().PlayOnceAudio("SFX_HT_NailHammerHit");
					m_Scorer += 2;

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
					CAudioManager::Get().PlayOnceAudio("SFX_HT_NailPlace");
					m_Scorer += 1;
				}
				break;
			}
		}
	}


	UpdateNails(dt);

	m_HandAnimation.Update(dt);
	m_HammerAnimation.Update(dt);
}

void GameModeHammerTime::Render()
{
	Renderer::Clear(220.0f / 255.0f, 222.0f / 255.0f, 198 / 255.0f);
	DrawNails();

	if (m_HandAnimation.IsPlaying())
	{
		m_HandAnimation.Render();
	}
	CGameInput* input = CGameInput::GetGameInput();
	if (m_HammerAnimation.IsPlaying() || input->GetKeyState(_GI_K_SPACE) == _KS_DH)
	{
		m_HammerAnimation.Render();
	}

}

bool GameModeHammerTime::IsDone()
{
	return false;
}

float GameModeHammerTime::GetGrades()
{
	return CalculateGrades();
}

void GameModeHammerTime::GenerateNails()
{
	if (m_LevelFinished) return;

	// ��������
	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;

	// ȡ�ö��ӵ�Ҫ���ĸ����ӳ���
	HammerBlock block = m_CurrentLevel->Blocks[m_NextBlockIndex];
	float nailBornBeats = block.Nails[m_NextNailIndex];
	float nailBornTime = (60.0f / m_CurrentLevel->BPM) * nailBornBeats;




	for (static int blockindex = 0; blockindex < m_CurrentLevel->Blocks.size();)
	{
		float mobileFromPosX = 0;
		float mobileToPosX = 260;

		float mobileArriveTime = (mobileToPosX - mobileFromPosX) / m_mobileSpeed;
		float mobileDistance = 0.3f * (mobileArriveTime * m_mobileSpeed) + mobileToPosX - mobileFromPosX;
		float mobileBronOffTime = mobileDistance / m_mobileSpeed;

		//ÿһ��block �ĵ�һ������ �ĳ���ʱ��
		float FristNailBron = (60.0f / m_CurrentLevel->BPM) * m_CurrentLevel->Blocks[blockindex].Nails[0];
		float mobileBronTime = FristNailBron - mobileBronOffTime;

		if (currentTime >= mobileBronTime)
		{
			//ÿ�����ĵ�ʱ��
			float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
			//�ܹ���Ҫ���ɶ��ٸ��������ߵ�·�̴�С ��ǰblock �е����һ������-��һ������ +1
			float distanceBreat = block.Nails[block.Nails.size() - 1] - block.Nails[0] + 0.5f;
			//�ƶ�̨�Ĵ�С
			float mobileLength = distanceBreat * (beatUnitTime * m_mobileSpeed);

			//�ƶ�̨���ɵ�ʱ��
			MobileStation mobile;
			mobile.x = -mobileLength -40;
			mobile.MobileLength = mobileLength;
			m_AllMobile.push_back(mobile);

			blockindex+=1;
			break;
		}
		break;
	}
	

	
	if (currentTime >= nailBornTime)
	{
		NailObject nail;
		nail.x = 150;
		nail.BornBetas = nailBornBeats;
		nail.State = NailState::Normal;

		m_AllNails.push_back(nail);
		//���Ŷ���-��
		m_HandAnimation.Play();

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

	//�����ƶ�̨��λ��

	for (MobileStation& mobile : m_AllMobile)
	{
		int i = m_mobileSpeed * dt;
		mobile.x += i;
	}
	for (auto it = m_AllMobile.begin(); it != m_AllMobile.end();)
	{
		if (it -> x >= 1000)
			it = m_AllMobile.erase(it);
		else 
			it++;
	}

	// ���¶���λ��
	{
		//m_mobileSpeed = (nailToPosX - nailFromPosX) / ((60.0f / m_CurrentLevel->BPM) * 4.0f);
		for (NailObject& nail : m_AllNails)
		{
			int i = m_mobileSpeed * dt;
			nail.x += i;

			if (nail.State == NailState::Normal)
			{
				//��ȡ������ʱ�� + 4+ 0.5 �����ӵ�ʱ��  �л����ӵ�״̬ miss  ����miss��Ч   ���ܱ�����
				float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
				float missTime = beatUnitTime * (nail.BornBetas + m_CurrentLevel->BeatsPerMeasure + HitJudgmentTimeMiss);

				if (currentTime > missTime)
				{
					nail.State = NailState::Miss;

					//��Ч
					CAudioManager::Get().PlayOnceAudio("SFX_HT_NailMissTilt");
				}
			}


			//if(nail.x )
		}
	}

	// ����Խ��Ķ���
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
	for (MobileStation& mobile : m_AllMobile)
	{
		float singleWeight = mobile.MobileLength * 0.1f;
		float centerWeight = mobile.MobileLength * 0.8f;
		Renderer::DrawTexture("wood_left", mobile.x, 300, singleWeight, 117, 0, 0, 0);
		Renderer::DrawTexture("wood_centre", mobile.x + singleWeight - 5, 300, centerWeight, 117, 0, 0, 0);
		Renderer::DrawTexture("wood_right", mobile.x + singleWeight+ centerWeight -10, 300, singleWeight, 117, 0, 0, 0);

	}


	for (NailObject& nail : m_AllNails)
	{
		if (nail.State == NailState::Normal)
		{
			Renderer::DrawTexture("nail_normal_1", nail.x, 400, 40.5f, 104.5f, 0, 0.5f, 1.0f);
		}
		else if (nail.State == NailState::Miss)
		{
			Renderer::DrawTexture("nail_normal_1", nail.x, 400, 40.5f, 104.5f, 15, 0.5f, 1.0f);
		}
		else if (nail.State == NailState::Perfect)
		{
			Renderer::DrawTexture("nail_normal_7", nail.x, 400, 43.0f, 12.5f, 0, 0.5f, 1.0f);
		}
		else if (nail.State == NailState::AlmostEarly)
		{
			Renderer::DrawTexture("nail_normal_3", nail.x, 400, 78.0f, 41.0f, 0, 0.5f, 1.0f);
		}
		else if (nail.State == NailState::AlmostLate)
		{
			Renderer::DrawTexture("nail_normal_6", nail.x, 400, 78.5f, 42.0f, 0, 0.5f, 1.0f);
		}
	}
}

float  GameModeHammerTime::CalculateGrades()
{
	//m_scoror / �ܳɼ��ı���
	float nailNum = m_AllNails.size();
	float grades = m_Scorer / nailNum * 2;
	return grades;
}

