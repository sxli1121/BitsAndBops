#pragma once
#include "StateMachine/State.h"

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
	CHammerScene* m_Scene;
	GradesResule m_Grades;
	double m_StartTime{ 0.0 };

	friend class CHammerScene;

};

