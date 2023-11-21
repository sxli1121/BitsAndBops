#include "TweetTeachingTwo.h"
#include "Audio/AudioManager.h"
#include "Scene/MeetTweet/MeetTweetScene.h"
#include "Scene/MeetTweet/States/TweetConfirming.h"
#include "Renderer/Renderer.h"

void TweetTeachingTwo::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("Bits And Bops TUTORIAL 110");

	TweetLevel* CurrentLevel = new TweetLevel;
	CurrentLevel->levelName = TweetLevelName::TWEET_TEACH_TWO;
	CurrentLevel->Duration = 26.0f;
	CurrentLevel->BPM = 110;
	CurrentLevel->Blocks = { 8.0f,12.0f,16.0f,20.0f,24.0f,28.0f,32.0f,36.0f,40.0f,44.0f };
	for (int i = 0; i < 10; i++)
	{
		CurrentLevel->BeatsPerMeasure.push_back(3);
	}

	m_Scene->g_gameModeMeetTweet->Init();
	m_Scene->g_gameModeMeetTweet->Play(CurrentLevel);


	m_Scene->m_CameraRotation = 0.0f;
	m_Scene->m_CameraScale = 1.0f;
	m_timer.Begin();
}

void TweetTeachingTwo::OnUpdate(float dt)
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
		m_Scene->m_ConfirmingState->SetStateMark(ToState::STATE_GAME);
		m_Scene->GetStateMachine()->Switch(STATE_TWEET_CONFIRM);
	}
}

void TweetTeachingTwo::OnExit()
{

}
