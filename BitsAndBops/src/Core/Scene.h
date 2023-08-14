#pragma once

class CScene
{
	//场景的大小
public:
	virtual void Init() = 0;
	virtual void Run() = 0;
	virtual void End() = 0;
};