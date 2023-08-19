#include "HammerTeaching.h"
#include "Scene/HammerScene/HammerScene.h"
#include "OutputAndInput/GameOutput.h"
#include "OutputAndInput/GameInput.h"
#include "Audio/AudioManager.h"
#include "Math/Matrix.h"
#include "GameParticipator/MobileStation.h"

#include "GameObject/Hammer.h"

void HammerTeaching::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("Bits And Bops TUTORIAL 110");
	m_timer.Begin();

	m_hammer = new CHammeer;
}

void HammerTeaching::OnUpdate(float dt)
{
	//����ʱ�������ƶ�̨(�ƶ�̨���ɵ�ʱ��������˶���-״̬��Ϊ������)-
	//����ʱ�䲥�Ŷ���-�ֵĶ�������ʱ ����״̬����Ϊ��ȫ״̬

	//���ݰ��������Ŷ���-���ӣ�ʱ�� ������Ч 

	//����ʱ�� ()

	double time = m_timer.GetTimerMilliSec();
	static bool i = true;
	if (/*time > 0.0f &&*/ i == true)
	{
		moblie = new MobileStation;
		moblie->SetXY(-100, 250);
		moblie->SetSpeed(200);
		moblie->SetStationLen(STATION_LONG);
		i = false;
		moblie->UpDate(dt);
	}
	else
	{
		moblie->UpDate(dt);
	}

	CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	Matrix33 m, sm;
	m.Translate(0, 0);
	sm.Scale(0.4, 0.4);
	m = sm * m;
	//����
	gameoutput->DrawPic("fg", &m);

	CGameInput* input = CGameInput::GetGameInput();

	if (input->GetKeyDown(_GI_K_E))
	{
		m_hammer->HandAmation_Play();
	}
	//���������붤�� ����ʱ��


}

void HammerTeaching::OnExit()
{
}
