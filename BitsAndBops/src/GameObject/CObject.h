#pragma once


class CObject
{
protected:
	float m_x;
	float m_y;

public:
	virtual ~CObject();
	float GetX()const;
	void SetX(float x) ;
	float GetY()const;
	void SetY(float y);
	////Åö×²Ìå»ý
	//CRect GetCollisionRect();
	//void SetColisionRect(CRect rect);

};

