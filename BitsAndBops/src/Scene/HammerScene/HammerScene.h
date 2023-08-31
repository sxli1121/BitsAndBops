#pragma once
#include "Core/Scene.h"
#include "Tools/Timer.h"
#include "Tools/TimerStampManage.h"
#include "StateMachine/StateMachine.h"
#include "Animation/FrameAnimation.h"
#include "Scene/HammerScene/GameModeHammerTime.h"
#include "OutPutAndInput/Camera.h"
#include <vector>


class TimerClock;
class CAudioManager;
class m_Audio;
class CHammer;
struct HammerLevel;

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
	//≥°æ∞π‹¿Ì
	StateMachine* GetStateMachine() { return m_StateMachine; }

private:
	StateMachine* m_StateMachine{ nullptr };

	Camera m_Camera;
	Vector2 m_CameraPosition;
	float m_CameraRotation{ 0.0f };
	float m_CameraScale{ 1.0f };

	HammerOpening* m_OpeningState{ nullptr };
	HammerTeaching* m_TeachingState{ nullptr };
	HammerConfirming* m_ConfirmState{ nullptr };
	HammerGaming* m_GameState{ nullptr };
	HammerSettlementing* m_SettlementState{ nullptr };
	
	friend class HammerOpening;
	friend class HammerTeaching;
	friend class HammerConfirming;
	friend class HammerGaming;
	friend class HammerSettlementing;

	GameModeHammerTime* m_gameModeHammerTime{ nullptr };
};


