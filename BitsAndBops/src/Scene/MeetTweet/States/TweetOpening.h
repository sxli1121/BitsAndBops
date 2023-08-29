#pragma once
#include "StateMachine/State.h"
#include "Tools/Timer.h"

class MeetTweetScene;

class TweetOpening : public State
{
public:
	TweetOpening(MeetTweetScene* scene)
		:m_Scene(scene) {}

	void OnEnter()override;
	void OnUpdate(float dt)override;
	void OnExit() override;

	
private:
	MeetTweetScene* m_Scene;
	TimerClock m_timer;
	
	friend class MeetTweetScene;

};

