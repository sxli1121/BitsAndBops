#include "TweetTeachingOne.h"
#include "Scene/MeetTweet/MeetTweetScene.h"
#include "OutPutAndInput/Camera.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "Scene/HammerScene/States/HammerConfirming.h"

void TweetTeachingOne::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("Bits And Bops TUTORIAL 110");

	TweetLevel* CurrentLevel = new TweetLevel;
	CurrentLevel->Duration = 26.0f;
	CurrentLevel->BPM = 110;
	CurrentLevel->Blocks = { 8.0f,12.0f,16.0f,20.0f,24.0f,28.0f,32.0f,36.0f,40.0f,44.0f };
	for(int i = 0;i< 10;i++)
	{
		CurrentLevel->BeatsPerMeasure.push_back(2); 
	}
	m_Camera.SetOrtho(0, 0, 960, 540);

	m_Scene->g_gameModeMeetTweet->Init();
	m_Scene->g_gameModeMeetTweet->Play(CurrentLevel);


	

}

void TweetTeachingOne::OnUpdate(float dt)
{
	m_Camera.SetScale(m_CameraScale);
	m_Camera.SetRotation(m_CameraRotation);
	m_Camera.SetOrtho(m_CameraPosition.x, m_CameraPosition.y, 960, 540);

	Renderer::SetViewProjection(m_Camera.GetViewProjMatrix());

	m_Scene->g_gameModeMeetTweet->Update(dt);
	m_Scene->g_gameModeMeetTweet->Render();


	
	double time = m_timer.GetTimerMilliSec();

	if (time/1000 >= 26000.0)
	{
		Renderer::Clear(0, 0, 0);
	}

	if (time/1000 >= 27000.0)
	{
		//m_Scene->GetStateMachine()->Switch(STATE_TWEET_CONFIRM);
		//m_Scene->m_ConfirmState->SetStateMark(ToState::STATE_GAME);
	}


}

void TweetTeachingOne::OnExit()
{
	
}
