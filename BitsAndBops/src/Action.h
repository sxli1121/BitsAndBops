#pragma once
#include "Animation/Animation.h"
class CObject;

class CAction
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
	CAction();
	virtual ~CAction();
	virtual void SetTag(CObject* tag);
	virtual void Act_Begin();                            //��ȫ���¿�ʼ--�տ�ʼ��ʱ�����ɿ�ʼ����
	virtual void Act_Play();
	virtual void Act_Pause();
	virtual void Act_Stop();
	
	virtual void Init();
	virtual void Run();
	virtual void End();

	CRect* GetAttackRect();
	int GetAttackRectLen();
	CRect* GetDefenseRect();
	int GetDefenseRectLen();
	int GetPicLen();
};

