#include "GameObject/Hammer.h"
#include "Hero_idle.h"
#include "Hero_Move.h"
#include "Action.h"

void CHammerAnimation::Init()
{

}

void CHammerAnimation::Run()
{
}

void CHammerAnimation::End()
{

}

void CHammerAnimation::Act_Begin()
{
	m_Amation.Animation_RePlay();
}

void CHammerAnimation::Act_Play()
{
	m_Amation.Animation_Playing();
}

void CHammerAnimation::Act_Pause()
{

	m_Amation.Animation_Pause();
}

void CHammerAnimation::Act_Stop()
{
	m_Amation.Animation_Stop();
}


