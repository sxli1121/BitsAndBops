#include "CObject.h"

CObject::~CObject()
{
}

float CObject::GetX()  const
{
    return m_x;
}

void CObject::SetX(float x)
{
    m_x = x;
}

float CObject::GetY()const
{
    return m_y;
}

void CObject::SetY(float y)
{
    m_y = y;
}

CRect CObject::GetCollisionRect()
{
    return m_rect;
}

void CObject::SetColisionRect(CRect rect)
{
    m_rect = rect;
}
