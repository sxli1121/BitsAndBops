#pragma once

class CScene
{
	//�����Ĵ�С
public:
	virtual void Init() = 0;
	virtual void Run() = 0;
	virtual void End() = 0;
};