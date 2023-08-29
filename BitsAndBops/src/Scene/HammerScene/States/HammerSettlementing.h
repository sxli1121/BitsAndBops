#pragma once
#include "StateMachine/State.h"
#include "Tools/Timer.h"

class CHammerScene;

enum class GradesResule
{
	GRADES_AMAZING,
	GRADES_COOL,
	GRADES_TRYAGAIN,
};

class HammerSettlementing : public State
{
public:
	HammerSettlementing(CHammerScene* scene)
		:m_Scene(scene){}

	void OnEnter() override;
	void OnUpdate(float dt) override;
	void OnExit() override;
private:
	void Renderer(double currenttime);
	void PlayAudio(double currenttime);
private:
	CHammerScene* m_Scene;
	GradesResule m_Grades;
	TimerClock m_timer;

	bool m_IsAudioPlay{ false };
	bool m_IsTextAudioPlay{ false };


	friend class CHammerScene;

};

