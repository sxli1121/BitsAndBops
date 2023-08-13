#include "Tool.h"

CTool::CTool()
{
	m_alive = 1;
}

CTool::~CTool()
{
}

void CTool::SetAct(bool b)
{
	m_alive = b;
}

bool CTool::GetAct()
{
	return m_alive;
}

void CTool::SetPos(CVector v)
{
	m_pos = v;
}

void CTool::SetDirection(CVector v)
{
	m_direction = v;
}

CVector CTool::GetPos()
{
	return m_pos;
}


void CTool::Init()
{

}

void CTool::Run()
{

}

void CTool::End()
{
}

void CTool::ColliderFun(CHero* hero, int dir)
{

}
