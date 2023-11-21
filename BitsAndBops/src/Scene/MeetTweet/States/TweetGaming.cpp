#include "TweetGaming.h"
#include "Audio/AudioManager.h"
#include "Scene/MeetTweet/MeetTweetScene.h"
#include "Renderer/Renderer.h"

void TweetGaming::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("Meet and Tweet (BITS AND BOPS) 220");

	TweetLevel* CurrentLevel = new TweetLevel;
	CurrentLevel->levelName = TweetLevelName::TWEET_GAME;
	CurrentLevel->Duration = 89.0f;
	CurrentLevel->BPM = 110;
	CurrentLevel->Blocks = {
		17.0f,21.0f,24.0f,28.0f,
		32.0f,36.0f,40.0f,44.0f,
		48.0f,52.0f,56.0f,60.0f,
		65.0f,69.0f,72.0f,76.0f,
		81.0f,85.0f,88.0f,92.0f,
		96.0f,100.0f,104.0f,107.0f,
		112.0f,116.0f,120.0f,124.0f,
		128.5f,132.5f,136.5f,140.0f,
		144.5f,148.5f,152.5f,155.0f,
	};
	int PerInterval[36] = { 2,2,3,2, 3,3,3,2, 3,3,3,2, 2,2,3,2, 2,2,3,2, 2,2,3,3, 2,2,3,2, 2,2,2,2, 2,2,2,3};
	for (int i = 0; i < 36; i++)
	{
		PerInterval[i];
		CurrentLevel->BeatsPerMeasure.push_back(PerInterval[i]);
	}

	m_Scene->m_CameraRotation = 0.0f;
	m_Scene->m_CameraScale = 1.0f;

	m_timer.Begin();
	m_scorer = 0;
	m_BlindY = 340;
	m_blindAudioPlay = false;


	m_Scene->g_gameModeMeetTweet->Init();
	m_Scene->g_gameModeMeetTweet->Play(CurrentLevel);
}

void TweetGaming::OnUpdate(float dt)
{
	//正式关卡前面的动画

	m_Scene->g_gameModeMeetTweet->Update(dt);
	m_Scene->g_gameModeMeetTweet->Render();
	double time = m_timer.GetTimerMilliSec();

	//窗帘的移动  3
	float UniteBeatTime = 60.0f / 110.0f;
	float CurtainFrom = 300;
	float CurtainTo = 0;
	float speedCurtain = (CurtainFrom - CurtainTo) / (UniteBeatTime * 2);
	if(time/1000 <= UniteBeatTime * 12)
	{
		Renderer::DrawTexture("bg_blind", 0, m_BlindY, 456.5f, 485.5, 0, 0, 1);
		if(time/1000 >= UniteBeatTime * 9)
		{
			m_BlindY -= speedCurtain * dt;
			if(m_blindAudioPlay == false)
			{
				CAudioManager::Get().PlayOnceAudio("SFX_MT_Blinds");
				m_blindAudioPlay = true;
			}
		}
	}

	//摄像机的移动
	float CameraFrom = 0;
	float CameraTo = -150;
	float speedCamera = (CameraFrom - CameraTo) / (UniteBeatTime * 2);

	if (time/1000 >= UniteBeatTime * 29  && time / 1000 <= UniteBeatTime * 31)
	{
		m_Scene->m_CameraPosition.y -= speedCamera * dt;
	}



	if (time / 1000 >= 89.0f)
	{
		Renderer::Clear(0, 0, 0);
	}

	if (time / 1000 >= 89.5f)
	{
		m_Scene->GetStateMachine()->Switch(STATE_TWEET_SETTLEMENT);
	}
}

void TweetGaming::OnExit()
{

}
