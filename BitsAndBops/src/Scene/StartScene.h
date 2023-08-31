#pragma once
#include "Core/Scene.h"
class CStartScene : public CScene
{
	float m_small;
	float m_middle;
	float m_big;
public:
	void Init();
	void Update(float dt);
	void End();
private:
	double m_elapsedTime;;
};