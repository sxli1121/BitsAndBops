#pragma once
#include "Action.h"
class CHero;
class CHero_idle 
{

//	PIC_InAnimation* m_pic;
//	//对应动画
//	Animation m_Am;
//	//行为状态-play pause stop
//	int m_state;
//public:
	//
//	CRect* GetAttackRect();
//	int GetAttackRectLen();
//	CRect* GetDefenseRect();
//	int GetDefenseRectLen();
//	int GetPicLen();

	//CHero* m_Hero;    //挂载
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

