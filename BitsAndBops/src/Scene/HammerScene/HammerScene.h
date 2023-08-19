#pragma once
#include "Core/Scene.h"
//#include "Audio/AudioManager.h"
#include "Tools/Timer.h"
#include "Tools/TimerStampManage.h"
#include "StateMachine/StateMachine.h"
#include <vector>


class TimerClock;
class CAudioManager;
class m_Audio;

enum HammerStates
{
	STATE_HAMMER_OPEN,
	STATE_HAMMER_TEACH,
	STATE_HAMMER_CONFIRM,
	STATE_HAMMER_GAME,
	STATE_HAMMER_SETTLEMENT,
};

class HammerOpening;
class HammerTeaching;
class HammerConfirming;
class HammerGaming;
class HammerSettlementing;


class CHammerScene :public CScene
{
public:
	void Init();
	void Update(float dt);
	void End();
	//��������
	StateMachine* GetStateMachine() { return m_StateMachine; }

private:
	int m_State;
	//TimerClock m_Timer;
	//ʱ�����-��ѧ�ؿ���game�ؿ�
	TimerStampManage* m_TeachTimeManage{ nullptr };
	TimerStampManage* m_GameTimeManage{ nullptr };

	StateMachine* m_StateMachine{ nullptr };
	
	//����״̬
	HammerOpening* m_OpeningState{ nullptr };
	HammerTeaching* m_TeachingState{ nullptr };
	HammerConfirming* m_ConfirmState{ nullptr };
	HammerGaming* m_GameState{ nullptr };
	HammerSettlementing* m_SettlementState{ nullptr };
	//��Ԫ
	friend class HammerOpening;
	friend class HammerTeaching;
	friend class HammerConfirming;
	friend class HammerGaming;
	friend class HammerSettlementing;


};

