#include "Animation/HammerAnimation.h"
#include "Animation/Animation.h"
#include "OutPutAndInput/GameOutput.h"
#include "Math/Matrix.h"

void CHammer::Init()
{
	m_HammerAmation1 = new Animation;
	m_HammerAmation2 = new Animation;
	m_HammerAmation3 = new Animation;
	m_HandAmation = new Animation;
	//´¸×Ó

	m_HammerAmation1->Init();
	m_HammerAmation2->Init();
	m_HammerAmation3->Init();
	Matrix33 tm, sm,rm, m;
	tm.Translate(0, 100);
	sm.Scale(0.3, 0.3);
	m = sm * tm;
	m_HammerAmation1->SetMatrix(&m);
	m_HammerAmation1->AddAnmiationPic("hammer", 0, 0, 5);
	rm.Rotate_A(-30);
	m = m * rm;
	m_HammerAmation2->SetMatrix(&m);
	m_HammerAmation2->AddAnmiationPic("hammer", 0, 0, 5);
	rm.Rotate_A(-60);
	m = m * rm;
	m_HammerAmation3->SetMatrix(&m);
	m_HammerAmation3->AddAnmiationPic("hammer", 0, 0, 5);

	m_HammerAmation1->Animation_RePlay();
	m_HammerAmation2->Animation_RePlay();
	m_HammerAmation3->Animation_RePlay();

	//ÊÖ
	m_HandAmation->Init();
	m_HandAmation->AddAnmiationPic("hand1", 0, 0, 5);
	m_HandAmation->AddAnmiationPic("hand2", 0, 0, 5);
	m_HandAmation->AddAnmiationPic("hand3", 0, 0, 5);
	m_HandAmation->AddAnmiationPic("hand_smear", 0, 0, 5);
	m_HandAmation->Animation_RePlay();
}

void CHammer::Update(float dt)
{
	if (m_IsPlaying)
	{
		m_AnimationTime += dt;
		if (m_AnimationTime > m_AnimationDuration)
		{
			m_IsPlaying = false;
			return;
		}

		m_CurrentRotation = m_RotationFrom + (m_AnimationTime/m_AnimationDuration) * (m_RotationTo - m_RotationFrom);
		CGameOutput* output = CGameOutput::GetGameOutput();

		float right = 1497;
		auto rm = Matrix33::T(-right, 0)
			* Matrix33::RA(m_CurrentRotation) 
			* Matrix33::T(right,0);

		auto transform = rm * Matrix33::S(0.1f, 0.1f) * Matrix33::T(100, 100);
		output->DrawPic("hammer", &transform);
	}


}

void CHammer::End()
{
}

void CHammer::HandAmation_Play()
{
	//m_HandAmation->Animation_RePlay();
	
}

void CHammer::HammerAmation_Play()
{
	m_IsPlaying = true;
	m_AnimationTime = 0.0f;
	//m_HammerAmation1->Animation_RePlay();
	//m_HammerAmation1->Run();
	//m_HammerAmation2->Animation_RePlay();
	//m_HammerAmation2->Run();
	//m_HammerAmation3->Animation_RePlay();
	//m_HammerAmation3->Run();
}
