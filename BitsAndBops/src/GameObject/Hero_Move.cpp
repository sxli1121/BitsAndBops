#include "Hero_Move.h"
#include "Hero.h"
#include "OutputAndInput/GameinPut.h"

void Hero_Move::SetTag(CObject* tag)
{
	m_Hero = (CHero*)tag;
}

void Hero_Move::Act_Begin()
{
	m_Am.Animation_RePlay();
}

void Hero_Move::Act_Play()
{
	m_Am.Animation_Playing();
}

void Hero_Move::Act_Pause()
{
	m_Am.Animation_Pause();
}

void Hero_Move::Act_Stop()
{
	m_Am.Animation_Stop();
}

void Hero_Move::Init()
{
	//只加载动画-（不加载资源）
	m_Am.Init();
	m_Am.AddAnmiationPic("move0", -52, -134, 5);
	m_Am.AddAnmiationPic("move1", -53, -135, 5);
	m_Am.AddAnmiationPic("move2", -53, -136, 5);
	m_Am.AddAnmiationPic("move3", -53, -137, 5);
	m_Am.AddAnmiationPic("move4", -55, -136, 5);
	m_Am.AddAnmiationPic("move5", -49, -136, 5);
	m_Am.AddAnmiationPic("move6", -55, -134, 5);
	m_Am.AddAnmiationPic("move7", -57, -135, 5);
	m_Am.AddAnmiationPic("move8", -55, -136, 5);
	m_Am.AddAnmiationPic("move9", -53, -137, 5);
	m_Am.AddAnmiationPic("move10", -53, -136, 5);
	m_Am.AddAnmiationPic("move11", -46, -135, 5);
	m_Am.Animation_RePlay();
}

void Hero_Move::Run()
{
	int dir = m_Hero->GetDir();
	float x = m_Hero->GetX();
	float y = m_Hero->GetY();
	if (dir == 4)
		x -= 2;
	else if (dir == 6)
		x += 2;
	m_Hero->SetX(x);
	m_Hero->SetY(y);
	//碰撞

	CMatrix33 m;
	m.Translate(x, y);
	m_Am.SetMatrix(&m);
	m_Am.Run();
	if (m_Am.GetAnimationState() == AM_STOP)
		m_Am.Animation_RePlay();
	CGameInput* gi = CGameInput::GetGameInput();
	if (gi->GetKeyDown(_GI_K_D))
	{
		m_Hero->SetDir(6);
	}
	else if (gi->GetKeyDown(_GI_K_A))
	{
		m_Hero->SetDir(4);
	}
	else
	{
		m_Hero->SetNextAction("idle");
	}
	//下落
	//碰撞（成功-站立）（失败-下落）



}

void Hero_Move::End()
{

}

