#pragma once
#include "StateMachine/State.h"
#include "Tools/Timer.h"

class CHammerScene;

class HammerGaming : public State
{
public:
	HammerGaming(CHammerScene* scene)
		:m_Scene(scene) {}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:
	CHammerScene* m_Scene;
	int m_scorer {0};
	TimerClock m_timer;

	friend class CHammerScene;

};

