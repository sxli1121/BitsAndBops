#include "HammerTeaching.h"
#include "Scene/HammerScene/HammerScene.h"
#include "OutputAndInput/GameOutput.h"
#include "OutputAndInput/GameInput.h"
#include "Audio/AudioManager.h"
#include "Math/Matrix.h"
#include "GameParticipator/MobileStation.h"

void HammerTeaching::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("Bits And Bops TUTORIAL 110");
	m_timer.Begin();
}

void HammerTeaching::OnUpdate(float dt)
{


	//Matrix33 m1,sm1,m2,sm2,m3,sm3;
	//m1.Translate(100, 250);
	//sm1.Scale(0.5, 0.3);
	//m1 = sm1 * m1;
	//m2.Translate(90, 250);
	//sm2.Scale(1, 0.3);
	//m2 = sm2 * m2;
	//m3.Translate(320, 250);
	//sm3.Scale(1, 0.3);
	//m3 = sm3 * m3;
	//gameoutput->DrawPic("wood_centre", &m1);
	//gameoutput->DrawPic("wood_left", &m2);
	//gameoutput->DrawPic("wood_right", &m3);
	double time = m_timer.GetTimerMilliSec();
	static bool i = true;
	if (time > 0.0f && i == true)
	{
		moblie = new MobileStation;
		moblie->SetXY(-100, 250);
		moblie->SetSpeed(20);
		moblie->SetStationLen(STATION_LONG);
		i = false;
		moblie->UpDate(dt);
	}
	else
	{
		moblie->UpDate(dt);
	}

	//
	CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	Matrix33 m, sm;
	m.Translate(0, 0);
	sm.Scale(0.4, 0.4);
	m = sm * m;
	//背景
	gameoutput->DrawPic("fg", &m);


	//生成箱子与钉子 按照时间


}

void HammerTeaching::OnExit()
{
}
