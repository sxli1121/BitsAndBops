#pragma once
#include "Math/Rect.h"

//位置--碰撞体积
class CObject
{
protected:
	float m_x;
	float m_y;
	CRect m_rect;
public:
	virtual ~CObject();
	float GetX()const;
	void SetX(float x) ;
	float GetY()const;
	void SetY(float y);
	//碰撞体积
	CRect GetCollisionRect();
	void SetColisionRect(CRect rect);

};

