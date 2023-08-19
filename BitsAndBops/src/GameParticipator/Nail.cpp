#include "Nail.h"

#include <cassert>

Nail::Nail()
{
	m_Size = 0;
}

void Nail::AddNail(int x, int y, int stste)
{
	sNail nail;
	nail.X = x;
	nail.Y = y;
	nail.PrecenceState = stste;
	m_Size += 1;
	m_nailList.push_back(nail);
}

void Nail::SetNailPos(int index, int x, int y)
{
	assert(index > 0);
	m_nailList[index].X = x;
	m_nailList[index].Y = y;
}

void Nail::SetNailState(int index, int State)
{
	assert(index > 0);
	m_nailList[index].PrecenceState = State;
}

int Nail::GetNailState(int index)
{
	return m_nailList[index].PrecenceState;
}

void Nail::EreaseNail()
{
	Clear();
}

void Nail::Clear()
{
	m_nailList.clear();
	m_Size = 0;
}
