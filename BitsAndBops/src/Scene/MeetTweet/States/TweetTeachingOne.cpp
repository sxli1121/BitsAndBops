#include "TweetTeachingOne.h"
#include "Scene/MeetTweet/MeetTweetScene.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "Scene/MeetTweet/States/TweetConfirming.h"


void TweetTeachingOne::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("Bits And Bops TUTORIAL 110");

	TweetLevel* CurrentLevel = new TweetLevel;
	CurrentLevel->levelName = TweetLevelName::TWEET_TEACH_ONE;
	CurrentLevel->Duration = 26.0f;
	CurrentLevel->BPM = 110;
	CurrentLevel->Blocks = { 8.0f,12.0f,16.0f,20.0f,24.0f,28.0f,32.0f,36.0f,40.0f,44.0f };
	for (int i = 0; i < 10; i++)
	{
		CurrentLevel->BeatsPerMeasure.push_back(2);
	}

	m_Scene->m_CameraRotation = 0.0f;
	m_Scene->m_CameraScale = 1.0f;



	m_timer.Begin();

	m_Scene->g_gameModeMeetTweet->Init();
	m_Scene->g_gameModeMeetTweet->Play(CurrentLevel);
}

void TweetTeachingOne::OnUpdate(float dt)
{

	m_Scene->g_gameModeMeetTweet->Update(dt);
	m_Scene->g_gameModeMeetTweet->Render();

	double time = m_timer.GetTimerMilliSec();

	if (time / 1000 >= 26.0f)
	{
		Renderer::Clear(0, 0, 0);
	}

	if (time / 1000 >= 27.0f)
	{
		m_Scene->m_ConfirmingState->SetStateMark(ToState::STATE_TEACHTWO);
		m_Scene->GetStateMachine()->Switch(STATE_TWEET_CONFIRM);
	}

}

void TweetTeachingOne::OnExit()
{

}
