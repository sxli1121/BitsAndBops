#pragma once
#include "CObject.h"
#include "Action.h"
#include "Hero_idle.h"
#include "Hero_Move.h"
#include "Audio/AudioManager.h"
#include <string>
#include <map>
class CAction;

class CHammeer
{
	Animation m_HammerAmation;
	Animation m_HandAmation;
public:
	void Init();
	void Run();
	void End();

	void HandAmation_Play();
	void HammerAmation_Play();
};

