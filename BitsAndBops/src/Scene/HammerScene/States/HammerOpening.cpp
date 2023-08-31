#include "HammerOpening.h"
#include "Audio/AudioManager.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Renderer/Renderer.h"
#include "Scene/HammerScene/States/HammerConfirming.h"
#include  "OutPutAndInput/GameInput.h"

void HammerOpening::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("JingleDraft");
	TextureManager::Load("Test", L"Assets/Textures/MeetTweet/bop.png");
	m_timer.Begin();
	//m_Camera.SetOrtho(0, 0, 960, 540);
}

void HammerOpening::OnUpdate(float dt)
{
	//m_Camera.SetScale(m_CameraScale);
	//m_Camera.SetRotation(m_CameraRotation);
	//m_Camera.SetOrtho(m_CameraPosition.x, m_CameraPosition.y, 960, 540);
	//Renderer::SetViewProjection(m_Camera.GetViewProjMatrix());

	Renderer::DrawTexture("hammer_title_screen", 0, 0, 960, 540, 0, 0, 0);


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
