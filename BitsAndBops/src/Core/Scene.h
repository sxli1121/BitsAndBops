#pragma once

class CScene
{
public:
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void End() = 0;
};