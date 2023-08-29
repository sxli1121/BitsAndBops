#pragma once
#include "StateMachine/State.h"
#include "Tools/Timer.h"

class MeetTweetScene;

class TweetGaming : public State
{
public:
	TweetGaming(MeetTweetScene* scene)
		:m_Scene(scene) {}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:
	MeetTweetScene* m_Scene;
	TimerClock m_timer;
	int m_scorer{ 0 };

	friend class MeetTweetScene;
};

