#pragma once
#include "StateMachine/state.h"
#include "Tools/Timer.h"

class MobileStation;
class CHammerScene;

class HammerTeaching : public State
{
public:
	//构造的时候-自带所属的场景
	HammerTeaching(CHammerScene* scene)
		:m_Scene(scene) {}
	//继承项
	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:
	//HammerTeaching(CHammerScene* scene);
	//所属场景
	CHammerScene* m_Scene;
	//
	TimerClock m_timer;
	MobileStation* moblie;

	friend class CHammerScene;


};

