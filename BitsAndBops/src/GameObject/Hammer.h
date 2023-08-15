#pragma once
#include "CObject.h"
#include "Action.h"
#include "Hero_idle.h"
#include "Hero_Move.h"
#include <string>
#include <map>
class CAction;

class CHammerAnimation
{
	PIC_InAnimation* m_pic;
	//��Ӧ����
	Animation m_Amation;
	//��Ϊ״̬-play pause stop
	int m_state;
	//�Ƿ�ѭ������ͼƬ
	int m_LoopFram = -1;
public:
	void Init();
	void Run();
	void End();

	void Act_Begin();
	void Act_Play();
	void Act_Pause();
	void Act_Stop();
};

