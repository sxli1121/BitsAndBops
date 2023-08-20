#pragma once
#include "StateMachine/state.h"

#include "Tools/Timer.h"

class Animation;


class MobileStation;
class CHammerScene;

class HammerTeaching : public State
{
public:
	HammerTeaching(CHammerScene* scene)
		:m_Scene(scene) {}
	//
	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:
	//HammerTeaching(CHammerScene* scene);
	//��������
	CHammerScene* m_Scene{ nullptr };
	//
	TimerClock m_timer;
	MobileStation* moblie{ nullptr };
	Animation* m_Animation{ nullptr };



	friend class CHammerScene;


};

