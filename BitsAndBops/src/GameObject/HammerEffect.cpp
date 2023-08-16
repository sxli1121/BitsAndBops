#include "HammerEffect.h"

void HammerEffect::Init()
{

	m_PerfectAmation.Init();
	m_PerfectAmation.AddAnmiationPic("hammer_perfect", 0, 0, 5);
	m_PerfectAmation.Animation_RePlay();

	m_HitAmation.Init();
	m_HitAmation.AddAnmiationPic("hammer_hit", 0, 0, 5);
	m_HitAmation.Animation_RePlay();

	m_Almost1Amation.Init();
	m_Almost1Amation.AddAnmiationPic("hammer_almost1", 0, 0, 5);
	m_Almost1Amation.Animation_RePlay();
	m_Almost2Amation.Init();
	m_Almost2Amation.AddAnmiationPic("hammer_almost2", 0, 0, 5);
	m_Almost2Amation.Animation_RePlay();

}

void HammerEffect::Run()
{

}

void HammerEffect::End()
{

}

void HammerEffect::Perfect_Play()
{
	m_PerfectAmation.Animation_RePlay();
}

void HammerEffect::Hit_Play()
{
	m_HitAmation.Animation_RePlay();
}

void HammerEffect::Almost_Play()
{
	m_Almost1Amation.Animation_RePlay();
	m_Almost2Amation.Animation_RePlay();
}
