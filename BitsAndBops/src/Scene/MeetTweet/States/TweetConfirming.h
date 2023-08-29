#pragma once
#include "StateMachine/State.h"

class MeetTweetScene;

enum class ToState
{
	STATE_TEACHONE,
	STATE_TEACHTWO,
	STATE_GAME
};

class TweetConfirming : public State
{
public:
	TweetConfirming(MeetTweetScene* scene)
		: m_Scene(scene) {}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;

	void SetStateMark(ToState stateId) { m_StateMark = stateId; }
private:

	void ToTeachOneTextUpdate();
	void ToTeachTwoTextUpdate();
	void ToGameTextUpdate();

	void PlayAudio();
private:

	MeetTweetScene* m_Scene{ nullptr };
	ToState m_StateMark{ ToState::STATE_GAME };
	int m_Mark{ 0 };

	friend class MeetTweetScene;
};

