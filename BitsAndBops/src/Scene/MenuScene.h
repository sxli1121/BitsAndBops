#pragma once
#include "Animation/FrameAnimation.h"
#include "Core/Scene.h"
#include "OutPutAndInput/Camera.h"
#include "Tools/Timer.h"

enum  class MenuLevelName
{
	NONE,
	HAMMER_TIME,
	METTE_TWETTE,
};

class MenuScene : public CScene
{
public:
	void Init()override;
	void Update(float dt)override;
	void End() override;
private:
	MenuLevelName m_levelName;
	MenuLevelName m_ConfireLevel{MenuLevelName::NONE };
	TimerClock m_Timer;

	Camera m_Camera;
	Vector2 m_CameraPosition;
	float m_CameraRotation{ 0.0f };
	float m_CameraScale{ 1.0f };
	

	FrameAnimation m_HammerEnterAnimayion;
	FrameAnimation m_TweetEnterAnimayion;

};

