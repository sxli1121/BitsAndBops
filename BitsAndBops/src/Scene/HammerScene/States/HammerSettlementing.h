#pragma once
#include "StateMachine/State.h"

class CHammerScene;

class HammerSettlementing : public State
{
public:
	HammerSettlementing(CHammerScene* scene)
		:m_Scene(scene){}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:
	CHammerScene* m_Scene;
	friend class CHammerScene;

};

