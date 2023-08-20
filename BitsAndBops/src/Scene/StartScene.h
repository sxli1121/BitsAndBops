#pragma once
#include "Core/Scene.h"
#include "Math/vector.h"
class CStartScene : public CScene
{
	float off;
	int dtnum;
public:
	void Init();
	void Update(float dt);
	void End();
};