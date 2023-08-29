#pragma once
#include "StateMachine/state.h"
#include "Tools/Timer.h"

class MeetTweetScene;

class TweetTeachingOne : public State
{
public:
	TweetTeachingOne(MeetTweetScene* scene)
		:m_Scene(scene) {}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:

	MeetTweetScene* m_Scene{ nullptr };
	int m_Remainung;
	TimerClock m_timer;

	friend class MeetTweetScene;
};

