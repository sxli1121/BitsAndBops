#pragma once


class CRect
{
	int m_x;
	int m_y;
	int m_w;
	int m_h;

	int m_left;
	int m_right;
	int m_top;
	int m_bottom;
public:
	const int& x = m_x;
	const int& y = m_y;
	const int& w = m_w;
	const int& h = m_h;
	const int& left =  m_left;
	const int& right = m_right;;
	const int& top = m_top;
	const int& bottom = m_bottom; 

	void operator=(const CRect& taht);
	CRect();

	void SetPos(int x,int y);
	void SetWH(int w,int h);
	void Set_Left(int left);
	void Set_Right(int right);
	void Set_Top(int top);
	void Set_Bottom(int bottom);

};

