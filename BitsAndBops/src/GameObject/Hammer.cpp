#include "GameObject/Hammer.h"
#include "Hero_idle.h"
#include "Hero_Move.h"
#include "Action.h"

void CHammerAnimation::Init()
{
	m_HammerAmation.Init();
	m_HammerAmation.AddAnmiationPic("idle0", -35, -134, 5);
	m_HammerAmation.AddAnmiationPic("idle1", -35, -134, 5);
	m_HammerAmation.AddAnmiationPic("idle2", -34, -135, 5);
	m_HammerAmation.AddAnmiationPic("idle3", -34, -135, 5);
	m_HammerAmation.AddAnmiationPic("idle4", -34, -136, 5);
	m_HammerAmation.AddAnmiationPic("idle5", -35, -136, 5);
	m_HammerAmation.AddAnmiationPic("idle6", -35, -136, 5);
	m_HammerAmation.AddAnmiationPic("idle7", -35, -136, 5);
	m_HammerAmation.AddAnmiationPic("idle8", -35, -136, 5);
	m_HammerAmation.AddAnmiationPic("idle9", -35, -135, 5);
	m_HammerAmation.AddAnmiationPic("idle10", -35, -135, 5);
	m_HammerAmation.AddAnmiationPic("idle11", -35, -134, 5);
	m_HammerAmation.Animation_RePlay();
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


