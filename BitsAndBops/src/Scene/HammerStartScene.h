#pragma once
#include "Core/Scene.h"

#define HAMMER_OPEN    0
#define HAMMER_TEACH   1
#define HAMMER_CONFIRM 2 
class CHammerStart :public CScene
{
	int m_State;
	CAudioManager audio;
public:
	void Init();
	void Run();
	void End();
};

