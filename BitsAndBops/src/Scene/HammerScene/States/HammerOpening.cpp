#include "HammerOpening.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Scene/HammerScene/States/HammerConfirming.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"


void HammerOpening::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("JingleDraft");
	m_timer.Begin();

	m_Scene->m_CameraRotation = 0.0f;
	m_Scene->m_CameraScale = 1.0f;
}

void HammerOpening::OnUpdate(float dt)
{

	Renderer::DrawTexture("hammer_title_screen", 0, 0, 960, 540, 0, 0, 0);


	double time = m_timer.GetTimerMilliSec();
	if (time >= 6000)
	{
		Renderer::Clear(0, 0, 0);
	}
	if(time >= 6500)
	{
		m_Scene->m_ConfirmState->SetStateMark(ToState::STATE_TEACH);
		m_Scene->GetStateMachine()->Switch(STATE_HAMMER_CONFIRM);
	}
}

void HammerOpening::OnExit()
{
	CAudioManager::Get().StopLoopAudio("construction_ambience");
}
