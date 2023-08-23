#pragma once
#include "StateMachine/State.h"

class CHammerScene;

enum class ToState
{
	STATE_TEACH,
	STATE_GAME
};

class HammerConfirming : public State
{
public:
	HammerConfirming(CHammerScene* scene)
		: m_Scene(scene) {}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
	
	void SetStateMark(ToState stateId) { m_StateMark = stateId; }
private:

	void ToTeachTextUpdate();
	void ToGameTextUpdate();

	void PlayAudio();
private:

	CHammerScene* m_Scene{ nullptr };
	ToState m_StateMark{ ToState::STATE_GAME };
	int m_Mark{ 0 };
	friend class CHammerScene;
};

