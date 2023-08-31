#pragma once
#include "StateMachine/state.h"
#include "Tools/Timer.h"
#include "OutPutAndInput/Camera.h"

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
	Camera m_Camera;
	Vector2 m_CameraPosition;
	float m_CameraRotation{ 0.0f };
	float m_CameraScale{ 1.0f };

	friend class MeetTweetScene;
};

