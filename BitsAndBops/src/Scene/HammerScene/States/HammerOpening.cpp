#include "HammerOpening.h"
#include "OutputAndInput/GameOutput.h"
#include "OutputAndInput/GameInput.h"
#include "Audio/AudioManager.h"
#include "Math/Matrix.h"
#include "Scene/HammerScene/HammerScene.h"

void HammerOpening::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("JingleDraft");
	m_timer.Begin();
}

void HammerOpening::OnUpdate(float dt)
{
	CGameOutput* p = CGameOutput::GetGameOutput();
	Matrix33 m, sm;
	sm.Scale(0.55, 0.7);
	m.Translate(0, 0);
	m = sm * m;
	p->DrawPic("hammer_title",&m);
	CGameInput* gi = CGameInput::GetGameInput();

	double time = m_timer.GetTimerMilliSec();

	if(time >= 6000)
	{
		m_Scene->GetStateMachine()->Switch(STATE_HAMMER_TEACH);
	}
}

void HammerOpening::OnExit()
{

}
