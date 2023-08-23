#include "HammerOpening.h"

#include "OutputAndInput/GameInput.h"
#include "Audio/AudioManager.h"
#include "Math/Matrix.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Renderer/Renderer.h"

void HammerOpening::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("JingleDraft");
	m_timer.Begin();
	
}

void HammerOpening::OnUpdate(float dt)
{
	Matrix33 m, sm;
	sm.Scale(0.5, 0.4);
	m.Translate(-50, 0);
	m = sm * m;
	Renderer::DrawTexture("hammer_title",0,0,960,450);
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
