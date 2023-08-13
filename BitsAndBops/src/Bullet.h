#pragma once
#include "Tool.h"

class Bullet : public CTool
{
public:

	void Init();
	void Run();
	void End();
	void ColliderFun(CTool* hero, int dir);
};

