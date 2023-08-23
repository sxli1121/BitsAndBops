#pragma once
#include "Core/Scene.h"
class MenuScene : public CScene
{
public:
	void Init()override;
	void Update(float dt)override;
	void End() override;
};

