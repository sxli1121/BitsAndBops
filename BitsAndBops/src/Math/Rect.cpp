#include "Rect.h"

void CRect::operator=(const CRect& that)
{
	m_x= that.m_x;
	m_y= that.m_y;
	m_w= that.m_w;
	m_h= that.m_h;

	m_left = that.m_left;
	m_right = that.m_right;
	m_top = that.m_top;
	m_bottom = that.m_bottom;
}

CRect::CRect()
{
	m_x = -1;
	m_y = -1;
	m_w = 1;
	m_h = 1;

	m_left =-1;
	m_right = -1;
	m_top = -1;
	m_bottom = -1;
}

void CRect::SetPos(int x, int y)
{
	m_x = x;
	m_y = y;

	m_left = m_x - m_w / 2;
	m_right = m_left + m_w - 1;
	m_top = m_y - m_h / 2;
	m_bottom = m_top + m_h - 1;
}

void CRect::SetWH(int w, int h)
{
	if (w <= 0 || h <= 0)
		return;
	m_w = w;
	m_h = h;

	m_left = m_x - m_w / 2;
	m_right = m_left + m_w - 1;
	m_top = m_y - m_h / 2;
	m_bottom = m_top + m_h - 1;
}

void CRect::Set_Left(int left)
{
	m_x = left + m_w / 2;
	m_left = left;
	m_right = m_left + m_w - 1;

}

void CRect::Set_Right(int right)
{


	m_right = right;
	m_left = m_right - m_w + 1;
	m_x = m_left  + m_w/2;

}

void CRect::Set_Top(int top)
{
	m_y = top  + m_h /2;

	m_top = top;
	m_bottom = m_top + m_h - 1;
}

void CRect::Set_Bottom(int bottom)
{
	m_bottom = bottom;
	m_top = m_bottom - m_h +1;
	m_y = m_top + m_h / 2;

}
