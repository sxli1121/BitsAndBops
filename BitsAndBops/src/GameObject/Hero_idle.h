#pragma once
#include "Action.h"
class CHero;
class CHero_idle 
{

//	PIC_InAnimation* m_pic;
//	//��Ӧ����
//	Animation m_Am;
//	//��Ϊ״̬-play pause stop
//	int m_state;
//public:
	//
//	CRect* GetAttackRect();
//	int GetAttackRectLen();
//	CRect* GetDefenseRect();
//	int GetDefenseRectLen();
//	int GetPicLen();

	//CHero* m_Hero;    //����
public:
	void SetTag(CObject* tag);
	void Act_Begin();                            
	void Act_Play();
	void Act_Pause();
	void Act_Stop();

	void Init();
	void Run();
	void End();
};

