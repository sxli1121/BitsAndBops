#pragma once
//�߾���ʱ��
#include <chrono>
#include <vector>


class TimerClock
{
	//��ʼʱ��-����ǰʱ��-epoch(ԭʼʱ���)��
	std::chrono::steady_clock::time_point StartTime;
	//������ʱʱ��
	//std::chrono::steady_clock::time_point EndTime;
	//���ʱ��ı���--�������жϣ�
	//float TimeInterval;
	//�༭��-����������ʱ�����-��������-��float��
	//���ڱ༭����
	//std::vector<float> m_TimeStamp;

public:
	//TimerClock();
	//~TimerClock();
	// //����ʱ��
	//std::chrono::time_point<std::chrono::nanoseconds> UpData();
	
	//��ʼ��ʱ
	 void Begin();
	//��ȡ����
	double GetTimerMilliSec();
};

