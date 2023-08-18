#pragma once
#include "StateMachine/State.h"

class CHammerScene;

class HammerConfirming : public State
{
public:
	HammerConfirming(CHammerScene* scene)
		: m_Scene(scene) {}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;

private:
	//HammerConfirming(CHammerScene* scene);

	CHammerScene* m_Scene;

	friend class CHammerScene;
};

