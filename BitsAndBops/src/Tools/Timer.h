#pragma once
//高精度时钟
#include <chrono>

class TimerClock
{
	std::chrono::steady_clock::time_point StartTime;

public:
	std::chrono::steady_clock::time_point GetNowTime();
	void Begin();
	double GetTimerMilliSec();
};

