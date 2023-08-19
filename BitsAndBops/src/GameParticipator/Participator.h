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
	//�����ߵ�����
	float m_x;
	float m_y;
	//�Ƿ����
	bool m_Act;
};

