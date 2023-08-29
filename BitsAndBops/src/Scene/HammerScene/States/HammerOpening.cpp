#include "HammerOpening.h"
#include "Audio/AudioManager.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Renderer/Renderer.h"
#include "Scene/HammerScene/States/HammerConfirming.h"


void HammerOpening::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("JingleDraft");
	m_timer.Begin();
	
}

void HammerOpening::OnUpdate(float dt)
{
	Renderer::DrawTexture("hammer_title_screen",0,0,960,540);

	double time = m_timer.GetTimerMilliSec();
	if (time >= 6000)
	{
		Renderer::Clear(0, 0, 0);
	}
	if(time >= 6500)
	{
		m_Scene->m_ConfirmState->SetStateMark(ToState::STATE_TEACH);
		m_Scene->GetStateMachine()->Switch(STATE_HAMMER_TEACH);
	}

}

void HammerOpening::OnExit()
{

}
