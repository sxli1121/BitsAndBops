#include "TimerStampManage.h"

#include <cassert>

void TimerStampManage::Clear()
{
	m_TimeStamp.clear();
	m_Size = 0;
}

TimerStampManage::TimerStampManage()
{
	m_Size = 0;
}

void TimerStampManage::AddTimeStamp(float* p, int len)
{
	assert(p != nullptr);
	assert(len > 0);

	TimeStamp* timer = new TimeStamp;
	for (int i = 0; i < len; i++)
	{
		timer->time = p[i];
		timer->act = true;
		m_Size += 1;
		m_TimeStamp.push_back(timer);
	}
	delete timer;
}

float TimerStampManage::GetTimeStamp()
{
	for (int i = 0; i <= m_Size; i++)
	{
		if (m_TimeStamp[i]->act == true)
			return m_TimeStamp[i]->time;
	}
}

void TimerStampManage::EreaseTimeStamp()
{
	Clear();
}


void TimerStampManage::SetTimeStamp_Act(int index, bool act)
{
	m_TimeStamp[index]->act = act;
}
