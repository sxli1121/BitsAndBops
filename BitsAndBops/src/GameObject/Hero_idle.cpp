//#include "Hero_idle.h"
////#include "Hero.h"
//#include "OutputAndInput/GameinPut.h"
//
//void CHero_idle::SetTag(CObject* tag)
//{
//	m_Hero = (CHero*)tag;
//}
//
//void CHero_idle::Act_Begin()
//{
//	m_Am.Animation_RePlay();
//}
//
//void CHero_idle::Act_Play()
//{
//	m_Am.Animation_Playing();
//}
//
//void CHero_idle::Act_Pause()
//{
//	m_Am.Animation_Pause();
//}
//
//void CHero_idle::Act_Stop()
//{
//	m_Am.Animation_Stop();
//}
//
//void CHero_idle::Init()
//{
//	//只加载动画-（不加载资源）
//	m_Am.Init();
//	m_Am.AddAnmiationPic("idle0", -35, -134, 5);
//	m_Am.AddAnmiationPic("idle1", -35, -134, 5);
//	m_Am.AddAnmiationPic("idle2", -34, -135, 5);
//	m_Am.AddAnmiationPic("idle3", -34, -135, 5);
//	m_Am.AddAnmiationPic("idle4", -34, -136, 5);
//	m_Am.AddAnmiationPic("idle5", -35, -136, 5);
//	m_Am.AddAnmiationPic("idle6", -35, -136, 5);
//	m_Am.AddAnmiationPic("idle7", -35, -136, 5);
//	m_Am.AddAnmiationPic("idle8", -35, -136, 5);
//	m_Am.AddAnmiationPic("idle9", -35, -135, 5);
//	m_Am.AddAnmiationPic("idle10", -35, -135, 5);
//	m_Am.AddAnmiationPic("idle11", -35, -134, 5);
//	m_Am.Animation_RePlay();
//}
//
//void CHero_idle::Run()
//{
//	//Matrix33 m;
//	//m.Translate(m_Hero->GetX(), m_Hero->GetY());
//	//m_Am.SetMatrix(&m);
//	//m_Am.Run();
//	//if (m_Am.GetAnimationState() == AM_STOP)
//	//{
//	//	if (m_LoopFram > -1 )
//	//	{
//	//		//设置当前的循环图片-从这一张图片开始播放
//	//		m_Am.SetCurPic(m_LoopFram);
//	//	}
//	//	else
//	//	{
//	//		m_Am.Animation_RePlay();
//	//	}
//	//}
//	//	
//	//CGameInput* gi = CGameInput::GetGameInput();
//	//if (gi->GetKeyDown(_GI_K_D))
//	//{
//	//	m_Hero->SetNextAction("move");
//	//	m_Hero->SetDir(6);
//	//}
//	//else if (gi->GetKeyDown(_GI_K_A))
//	//{
//	//	m_Hero->SetNextAction("move");
//	//	m_Hero->SetDir(4);
//	//}
//	////下落
//	//碰撞（成功-站立）（失败-下落）
//}
//
//void CHero_idle::End()
//{
//
//}
