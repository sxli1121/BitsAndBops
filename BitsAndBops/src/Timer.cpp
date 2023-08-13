#include "Timer.h"

void TimerClock::Begin()
{
	//��ȡ�տ�ʼ��ʱ��
	
	StartTime = std::chrono::high_resolution_clock::now();
}

//std::chrono::time_point<high_resolution_clock> TimerClock::UpData()
//{
//	//����ʱ������
//	return std::chrono::high_resolution_clock::now();
//}
double TimerClock::GetTimerMilliSec()
{
	//��ȡʱ����
	auto now = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now - StartTime).count();
	return duration / 1000000.0f;
}
