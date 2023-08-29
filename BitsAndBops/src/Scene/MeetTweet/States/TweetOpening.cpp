#include "TweetOpening.h"

#include "TweetConfirming.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "Scene/MeetTweet/MeetTweetScene.h"

void TweetOpening::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("JingleDraft");
	m_timer.Begin();
}

void TweetOpening::OnUpdate(float dt)
{
	Renderer::DrawTexture("meet_and_tweet_title_screen", 0, 0, 960, 540);

	double time = m_timer.GetTimerMilliSec();
	if (time >= 6000)
	{
		Renderer::Clear(0, 0, 0);
	}
	if (time >= 6500)
	{
		m_Scene->m_ConfirmingState->SetStateMark(ToState::STATE_TEACHONE);
		m_Scene->GetStateMachine()->Switch(STATE_TWEET_CONFIRM);
	}
}

void TweetOpening::OnExit()
{
	
}
