#include "Time.h"
#include <chrono>

using namespace std::chrono;

struct TimeData
{
	high_resolution_clock::time_point StartTime;
};

TimeData s_TimeData;

void Time::Init()
{
	s_TimeData.StartTime = high_resolution_clock::now();
}

double Time::GetRealtimeSinceStartup()
{
	duration<double> timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - s_TimeData.StartTime);
	return timeSpan.count();
}
