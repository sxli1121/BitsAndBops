#pragma once
#include "CObject.h"
#include "Action.h"
#include "Hero_idle.h"
#include "Hero_Move.h"
#include "Audio/AudioManager.h"
#include <string>
#include <map>
class CAction;

class CHammerAnimation
{
	PIC_InAnimation* m_pic;
	//对应动画
	Animation m_HammerAmation;
	Animation m_HandAmation;
	Animation m_EffectAmation;
	//行为状态-play pause stop
	int m_state;
	//是否循环播放图片
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

