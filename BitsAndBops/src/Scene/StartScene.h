#pragma once
#include "Core/Scene.h"
#include "Tools/Timer.h"
#include "OutPutAndInput/Camera.h"

class CStartScene : public CScene
{
	float m_small;
	float m_middle;
	float m_big;
public:
	void Init();
	void Update(float dt);
	void End();
private:
	TimerClock m_Timer;
	double m_StartTime{ 0 };
	bool m_IsLoopAudioPlay{ false };

	Camera m_Camera;
	Vector2 m_CameraPosition;
	float m_CameraRotation{ 0.0f };
	float m_CameraScale{ 1.0f };
};
