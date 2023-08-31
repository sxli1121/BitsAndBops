#pragma once
#include "StateMachine/State.h"
#include "Tools/Timer.h"
//#include "OutPutAndInput/Camera.h"
class CHammerScene;

class HammerOpening  : public State
{
public:
	HammerOpening(CHammerScene* scene)
		:m_Scene(scene) {}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;

private:
	TimerClock m_timer;
	CHammerScene* m_Scene;
	friend class CHammerScene;

};

