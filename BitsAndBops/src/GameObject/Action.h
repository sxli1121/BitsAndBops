#pragma once
#include "Animation/Animation.h"
class CObject;

class CAnimation
{
protected:
	PIC_InAnimation* m_pic;
	//对应动画
	Animation m_Am;
	//行为状态-play pause stop
	int m_state;
	//是否循环播放图片
	int m_LoopFram =-1;
public:
	CAnimation();
	virtual ~CAnimation();
	//virtual void SetTag(CObject* tag);
	virtual void Act_Begin();                            //完全重新开始--刚开始的时候生成开始动画
	virtual void Act_Play();
	virtual void Act_Pause();
	virtual void Act_Stop();
	
	virtual void Init();
	virtual void Run();
	virtual void End();

	int GetPicLen();
};

