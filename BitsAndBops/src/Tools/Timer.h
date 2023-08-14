#pragma once
//高精度时钟
#include <chrono>
#include <vector>


class TimerClock
{
	//开始时间-（当前时间-epoch(原始时间戳)）
	std::chrono::steady_clock::time_point StartTime;
	//结束计时时间
	//std::chrono::steady_clock::time_point EndTime;
	//间隔时间的变量--（用来判断）
	//float TimeInterval;
	//编辑器-（用来储存时间戳）-数据类型-（float）
	//加在编辑器中
	//std::vector<float> m_TimeStamp;

public:
	//TimerClock();
	//~TimerClock();
	// //更新时间
	//std::chrono::time_point<std::chrono::nanoseconds> UpData();
	
	//开始计时
	 void Begin();
	//获取毫秒
	double GetTimerMilliSec();
};

