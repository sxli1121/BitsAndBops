#pragma once
#include "Animation/Animation.h"
class CObject;

class CAnimation
{
protected:
	PIC_InAnimation* m_pic;
	//��Ӧ����
	Animation m_Am;
	//��Ϊ״̬-play pause stop
	int m_state;
	//�Ƿ�ѭ������ͼƬ
	int m_LoopFram =-1;
public:
	CAnimation();
	virtual ~CAnimation();
	//virtual void SetTag(CObject* tag);
	virtual void Act_Begin();                            //��ȫ���¿�ʼ--�տ�ʼ��ʱ�����ɿ�ʼ����
	virtual void Act_Play();
	virtual void Act_Pause();
	virtual void Act_Stop();
	
	virtual void Init();
	virtual void Run();
	virtual void End();

	int GetPicLen();
};

