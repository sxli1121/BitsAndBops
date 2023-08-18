#pragma once

class Participator
{
public:
	virtual void Init() {}
	virtual void UpDate(float dt){}
	virtual void End() {}

	void SetXY(int x,int y) { m_x = x; m_y = y;}
	void SetAct(bool act) { m_Act = act; }
protected:
	//参与者的坐标
	int m_x;
	int m_y;
	//是否存在
	bool m_Act;
};

