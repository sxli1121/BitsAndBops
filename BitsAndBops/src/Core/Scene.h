#pragma once

class CScene
{
	//�����Ĵ�С
public:
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void End() = 0;
};