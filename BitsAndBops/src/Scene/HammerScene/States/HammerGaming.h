#pragma once
#include "StateMachine/State.h"

class Animation;
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

	friend class CHammerScene;

};

