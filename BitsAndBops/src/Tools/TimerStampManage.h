#pragma once
#pragma once
#include <vector>
class TimerStampManage
{

public:
	TimerStampManage();
	void AddTimeStamp(float* p, int len);
	void SetTimeStamp_Act(int index, bool act);
	float GetTimeStamp();
	void EreaseTimeStamp();
private:
	void Clear();
private:
	struct TimeStamp
	{
		float time;
		bool act;
	};
	int m_Size;
	std::vector<TimeStamp*> m_TimeStamp;

};

