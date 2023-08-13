#pragma once
#include "Scene.h"
class CFightScene : public CScene
{
	int x;
	int y;
public:
	void Init();
	void Run();
	void End();
};