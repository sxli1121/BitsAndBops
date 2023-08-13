#pragma once
#include "Scene.h"
#include "GameObject/Hero.h"
#include "Timer.h"

class CTestScene3:public CScene
{
	CHero a;
	TimerClock itep;
public:
	void Init();
	void Run();
	void End();
};

