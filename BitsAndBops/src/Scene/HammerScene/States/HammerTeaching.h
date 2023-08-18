#pragma once
#include "StateMachine/state.h"
#include "Tools/Timer.h"

class MobileStation;
class CHammerScene;

class HammerTeaching : public State
{
public:
	//�����ʱ��-�Դ������ĳ���
	HammerTeaching(CHammerScene* scene)
		:m_Scene(scene) {}
	//�̳���
	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:
	//HammerTeaching(CHammerScene* scene);
	//��������
	CHammerScene* m_Scene;
	//
	TimerClock m_timer;
	MobileStation* moblie;

	friend class CHammerScene;


};

