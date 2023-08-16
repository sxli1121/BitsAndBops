#pragma once
#include "CObject.h"
#include "Action.h"
#include "Audio/AudioManager.h"
#include <string>
#include <map>
class CAction;

class HammerEffect
{
	Animation m_PerfectAmation;
	Animation m_HitAmation;
	Animation m_Almost1Amation;
	Animation m_Almost2Amation;
public:
	void Init();
	void Run();
	void End();

	void Perfect_Play();
	void Hit_Play();
	void Almost_Play();
};


