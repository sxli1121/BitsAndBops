#pragma once
#include "StateMachine/state.h"

#include "Tools/Timer.h"

class Animation;
class CHammerScene;

class HammerTeaching : public State
{
public:
	HammerTeaching(CHammerScene* scene)
		:m_Scene(scene) {}
	
	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:

	CHammerScene* m_Scene{ nullptr };

	friend class CHammerScene;


};

