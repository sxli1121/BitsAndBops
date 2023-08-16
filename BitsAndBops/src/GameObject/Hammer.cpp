#include "GameObject/Hammer.h"
#include "Hero_idle.h"
#include "Hero_Move.h"
#include "Action.h"

void CHammeer::Init()
{
	//´¸×Ó
	m_HammerAmation.Init();
	m_HammerAmation.AddAnmiationPic("hammer", 0, 0, 5);
	m_HammerAmation.Animation_RePlay();

	//ÊÖ
	m_HandAmation.Init();
	m_HandAmation.AddAnmiationPic("hand1", 0, 0, 5);
	m_HandAmation.AddAnmiationPic("hand2", 0, 0, 5);
	m_HandAmation.AddAnmiationPic("hand3", 0, 0, 5);
	m_HandAmation.AddAnmiationPic("hand_smear", 0, 0, 5);
	m_HandAmation.Animation_RePlay();
}

void CHammeer::Run()
{
}

void CHammeer::End()
{
}

void CHammeer::HandAmation_Play()
{
	m_HandAmation.Animation_RePlay();
}

void CHammeer::HammerAmation_Play()
{
	m_HammerAmation.Animation_RePlay();
}
