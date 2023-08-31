#include "GameModeMeetTweet.h"
#include "Core/Time.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "OutPutAndInput/GameInput.h"

void GameModeMeetTweet::Init()
{
	m_NextBlockIndex = 0;
	m_HalfBeatIndex = 0;
	m_NextBeatIndex = 0;
	m_BeatPerMeasureIndex = 0;
	m_CaptionIndex = 0;

	m_LevelFinished = false;
	m_Scorer = 0;
	m_StartTime = 0;

	//½ðË¿È¸Õý³£Bop
	m_CanaryBopAnimation.Reset();
	m_CanaryBopAnimation.SetMode(AnimationMode::Loop);
	m_CanaryBopAnimation.AddFrame({
		0,
		"canary_bop_1",
		625,
		390,
		294.5f,
		275,
		0,
		0.219f,
		0.971f
		});

	m_CanaryBopAnimation.AddFrame({
		0.26666f,
		"canary_bop_2",
		625,
		390,
		293,
		275,
		0,
		0.203f,
		0.926f
		});

	m_CanaryBopAnimation.AddFrame({
		0.5333f,
		"canary_bop_2",
		625,
		390,
	    293,
		275,
		0,
		0.203f,
		0.926f
		});



	m_RadioAnimation.Reset();
	m_RadioAnimation.SetMode(AnimationMode::Once);
	m_RadioAnimation.AddFrame({
		0,
		"radio_noise_1",
		385,
		230,
		81,
		137,
		0,
		0,
		0
		});

	m_RadioAnimation.AddFrame({
		0.1f,
		"radio_noise_2",
		385,
		230,
		78,
		136.5f,
		0,
		0,
		0
		});

	m_RadioAnimation.AddFrame({
		0.2f,
		"radio_noise_3",
		385,
		230,
		79,
		134.5,
		0,
		0,
		0
		});

	m_RadioAnimation.AddFrame({
	0.3f,
	"radio_noise_3",
		385,
		230,
		79,
		134.5,
		0,
		0,
		0
		});


	
	m_CanaryPerfectAnimation.Reset();
	m_CanaryPerfectAnimation.SetMode(AnimationMode::Once);
	m_CanaryPerfectAnimation.AddFrame({
		0,
		"canary_tweet_1",
		625,
		390,
		334,
		314.5f,
		0,
		0.472f,
		0.934f
		});

	m_CanaryPerfectAnimation.AddFrame({
		0.25f,
		"canary_tweet_2",
		625,
		390,
		304.5f,
		300.5f,
		0,
		0.368f,
		0.932f
		});


	m_CanaryPerfectAnimation.AddFrame({
	0.4f,
	"canary_tweet_3",
		625,
		390,
	315.5f,
	278,
	0,
	0.206f,
	0.928f
	});

	m_CanaryPerfectAnimation.AddFrame({
	0.5f,
	"canary_tweet_3",
		625,
		390,
	315.5f,
	278,
	0,
	0.206f,
	0.928f
	});



	m_CanaryAlmostAnimation.Reset();
	m_CanaryAlmostAnimation.SetMode(AnimationMode::Once);
	m_CanaryAlmostAnimation.AddFrame({
		0,
		"canary_almost",
		625,
		390,
		334,
		314.5f,
		0,
		0.466f,
		0.929f
		});

	m_CanaryAlmostAnimation.AddFrame({
		0.25f,
		"canary_tweet_2",
		625,
		390,
		304.5f,
		300.5f,
		0,
		0.368f,
		0.932f
		});


	m_CanaryAlmostAnimation.AddFrame({
	0.4f,
	"canary_tweet_3",
		625,
		390,
	315.5f,
	278,
	0,
	0.206f,
	0.928f
		});

	m_CanaryAlmostAnimation.AddFrame({
	0.5f,
	"canary_tweet_3",
	625,
	390,
	315.5f,
	278,
	0,
	0.206f,
	0.928f
		});



	 m_CanaryMissAnimation.Reset();
	 m_CanaryMissAnimation.SetMode(AnimationMode::Once);
	 m_CanaryMissAnimation.AddFrame({
		0,
		"canary_screech_1",
		625,
		390,
		340,
		314.5f,
		0,
		0.478f,
		0.932f
		});

	 m_CanaryMissAnimation.AddFrame({
		0.25f,
		"canary_tweet_2",
		625,
		390,
		304.5f,
		300.5f,
		0,
		0.368f,
		0.932f
		});


	 m_CanaryMissAnimation.AddFrame({
	0.4f,
	"canary_tweet_3",
		625,
		390,
	315.5f,
	278,
	0,
	0.206f,
	0.928f
		});

	 m_CanaryMissAnimation.AddFrame({
	0.5f,
	"canary_tweet_3",
	625,
	390,
	315.5f,
	278,
	0,
	0.206f,
	0.928f
		});
}

void GameModeMeetTweet::Play(TweetLevel* lever)
{
	m_CurrentLevel = lever;
	m_StartTime = Time::GetRealtimeSinceStartup();

	//ÎªanswerBeats¸³Öµ
	int size = m_CurrentLevel->Blocks.size();
	int blockIndex = 0;
	int BeatPerMeasureIndex = 0;
	AnswerBeat answerBeat;
	for (int i = 0; i < size; i++)
	{
		answerBeat.Beat = m_CurrentLevel->Blocks[blockIndex] + m_CurrentLevel->BeatsPerMeasure[BeatPerMeasureIndex];
		answerBeat.State = KeystorkeAnswerState::Normal;
		blockIndex++;
		BeatPerMeasureIndex++;
		m_AnswerBeats.push_back(answerBeat);
	}
	m_CanaryBopAnimation.Play();
	
}

void GameModeMeetTweet::Update(float dt)
{
	GeneratePromptAudio();
	
	//°´¼üÅÐ¶Ï
	CGameInput* input = CGameInput::GetGameInput();

	if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
	{
		for (AnswerBeat& answerBeat : m_AnswerBeats)
		{
			if (answerBeat.State == KeystorkeAnswerState::Normal)
			{
				float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
				float perfectTime = beatUnitTime * answerBeat.Beat;

				double hitTime = Time::GetRealtimeSinceStartup() - m_StartTime;
				float diff = hitTime - perfectTime;
				float diffBeat = diff * beatUnitTime;

				if (abs(diffBeat) <= HitJudgmentTimePerfect)
				{
					answerBeat.State = KeystorkeAnswerState::Perfect;
					m_CanaryPerfectAnimation.Play();

				}
				else if (abs(diffBeat) <= HitJudgmentTimeAlmost)
				{
					answerBeat.State = KeystorkeAnswerState::Almost;
					m_CanaryAlmostAnimation.Play();
				}
				else
				{
					m_CanaryMissAnimation.Play();
				}
				break;
			}
		}
	}

	UpdateAnswerBeats(dt);
	
	
	m_CanaryPerfectAnimation.Update(dt);
	m_CanaryAlmostAnimation.Update(dt);
	m_CanaryMissAnimation.Update(dt);
	m_CanaryBopAnimation.Update(dt);
	m_RadioAnimation.Update(dt);
}

void GameModeMeetTweet::Render()
{
	//±³¾°
	Renderer::DrawTexture("bg_outside", 0, 0, 960, 540);
	Renderer::DrawTexture("bg_inside", 0, 0, 960, 540);

	Renderer::DrawTexture("radio", 90, 105, 279.5f, 276);
	Renderer::DrawTexture("canary_perch", 550, 380, 174, 200.5f);

	//Renderer::

	if (m_CanaryPerfectAnimation.IsPlaying())
	{
		m_CanaryPerfectAnimation.Render();
	}
	else if (m_CanaryAlmostAnimation.IsPlaying())
	{
		m_CanaryAlmostAnimation.Render();
	}
	else if (m_CanaryMissAnimation.IsPlaying())
	{
		m_CanaryMissAnimation.Render();
	}
	else if(m_CanaryBopAnimation.IsPlaying())
	{
		m_CanaryBopAnimation.Render();
	}



	if (m_RadioAnimation.IsPlaying())
	{
		m_RadioAnimation.Render();
	}
}

bool GameModeMeetTweet::IsDone()
{
	return false;
}

float GameModeMeetTweet::GetGrades()
{
	return 1.0f;
}

void GameModeMeetTweet::GeneratePromptAudio()
{
	if (m_LevelFinished) return;

	float beatUnitTime = 60.0f / m_CurrentLevel->BPM;
	float FirstBeatTime = beatUnitTime * m_CurrentLevel->Blocks[m_NextBlockIndex];
	float HalfBeatTime = beatUnitTime * m_CurrentLevel->Blocks[m_HalfBeatIndex] + (beatUnitTime * 0.5f);
	float NextBeatTime = beatUnitTime * m_CurrentLevel->Blocks[m_NextBeatIndex] + beatUnitTime;

	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;
	int size = m_CurrentLevel->Blocks.size();

	if (currentTime >= FirstBeatTime)
	{
		if (m_NextBlockIndex < size)
		{
			PromoptObject();
			m_NextBlockIndex++;
		}
	}
	if (currentTime >= HalfBeatTime)
	{
		if (m_HalfBeatIndex < size && m_CurrentLevel->BeatsPerMeasure[m_BeatPerMeasureIndex] == 3)
		{
			PromoptObject();

		}
		m_HalfBeatIndex++;
		m_BeatPerMeasureIndex++;
	}
	if (currentTime >= NextBeatTime)
	{
		if (m_BeatPerMeasureIndex < size)
		{
			PromoptObject();;
			
			m_NextBeatIndex += 1;
		}
	}

	//×ÖÄ»
	if (m_CurrentLevel->BeatsPerMeasure[m_CaptionIndex] == 2)
	{

	}
	else if (m_CurrentLevel->BeatsPerMeasure[m_CaptionIndex] == 3)
	{

	}




	if (m_NextBlockIndex == m_CurrentLevel->Blocks.size())
	{
		m_LevelFinished = true;
	}

}

void GameModeMeetTweet::UpdateAnswerBeats(float dt)
{
	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;

	for (AnswerBeat& answerBeat : m_AnswerBeats)
	{
		if (answerBeat.State == KeystorkeAnswerState::Normal)
		{
			float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
			float missTime = beatUnitTime * ( answerBeat.Beat + HitJudgmentTimeMiss);

			if (currentTime > missTime)
			{
				answerBeat.State = KeystorkeAnswerState::Miss;
		
			}
		}
	}
}

void GameModeMeetTweet::PromoptObject()
{
	CAudioManager::Get().PlayOnceAudio("tweet");
	m_RadioAnimation.Play();
}
