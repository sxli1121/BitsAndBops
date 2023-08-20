#pragma once
#include "GameObject/CObject.h"
#include "Audio/AudioManager.h"
#include <string>
#include <map>

class Animation;

class HammerEffect
{
	Animation* m_PerfectAmation{ nullptr };
	Animation* m_HitAmation{ nullptr };
	Animation* m_Almost1Amation{ nullptr };
	Animation* m_Almost2Amation{ nullptr };
public:
	void Init();
	void Run();
	void End();

	void Perfect_Play();
	void Hit_Play();
	void Almost_Play();
};


