#include "Timer.h"

std::chrono::steady_clock::time_point TimerClock::GetNowTime()
{
	return std::chrono::high_resolution_clock::now();
}

void TimerClock::Begin()
{
	StartTime = std::chrono::high_resolution_clock::now();
}

double TimerClock::GetTimerMilliSec()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now - StartTime).count();
	return duration / 1000000.0f;
}
