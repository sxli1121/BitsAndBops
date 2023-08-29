#pragma once
#include "StateMachine/State.h"
#include "Tools/Timer.h"

class MeetTweetScene;

enum class TweetGradesResule
{
	GRADES_PERFECT,
	GRADES_COOL,
	GRADES_TRYAGAIN,
};

class TweetSettlementing : public State
{
public:
	TweetSettlementing(MeetTweetScene* scene)
		:m_Scene(scene) {}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:
	void Renderer(double currentTime);
	void PlayAudio(double currentTime);
private:
	MeetTweetScene* m_Scene;
	TweetGradesResule m_Grades;
	TimerClock m_timer;

	bool m_IsAudioPlay{ false };
	bool m_IsTextAudioPlay{ false };

	friend class MeetTweetScene;
};

