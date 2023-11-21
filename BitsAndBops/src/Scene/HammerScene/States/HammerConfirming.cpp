#include "HammerConfirming.h"
#include "Scene/HammerScene/HammerScene.h"

#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "OutPutAndInput/GameInput.h"
#include "Scene/TitleScene.h"

void HammerConfirming::OnEnter()
{
	CAudioManager::Get().PlayLoopAudio("construction_ambience");
	m_Mark = 0;

	m_Scene->m_CameraRotation = 0;
	m_Scene->m_CameraScale = 1.0f;
}

void HammerConfirming::OnUpdate(float dt)
{

	Renderer::Clear(220.0f / 255.0f, 222.0f / 255.0f, 198 / 255.0f);

	Renderer::DrawTexture("wood_centre", 0, 385, 235, 117, 0, 0, 0);
	Renderer::DrawTexture("wood_right", 225, 385, 31.5f, 117, 0, 0, 0);

	Renderer::DrawTexture("wood_left", 620, 385, 31.5f, 117, 0, 0, 0);
	Renderer::DrawTexture("wood_centre", 645.5f, 385, 350, 117, 0, 0, 0);

	Renderer::DrawTexture("nail_normal_7", 685, 378, 43, 12.5f, 0, 0, 0);
	Renderer::DrawTexture("hammer", 650, -115, 748.5f, 500.5f, 0, 0, 0);

	Renderer::DrawTexture("tutorial_textbox", 50, 50, 871, 136, 0, 0, 0);


	if (m_StateMark == ToState::STATE_TEACH)
	{
		ToTeachTextUpdate();
	}

	if (m_StateMark == ToState::STATE_GAME)
	{
		ToGameTextUpdate();
	}
	
}

void HammerConfirming::OnExit()
{

	CAudioManager::Get().StopLoopAudio("construction_ambience");
}

void HammerConfirming::ToTeachTextUpdate()
{
	CGameInput* input = CGameInput::GetGameInput();

	if (m_Mark == 0)
	{
		if(m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("Let's build something!", 60, 50, 800, 100, 0.0f, 0.0f, 0.0f,22, L"l_10646");
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"我们来打造一些东西吧!", 60, 0, 800, 200, 0.0f, 0.0f, 0.0f,22);

		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC) 
		{
			 
			PlayAudio();
			m_Mark += 1;
		}
	}
	else if (m_Mark >= 1)
	{

		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("I'll put the nail downs,and you hammer time in.", 60, 50, 800, 100, 0.0f, 0.0f, 0.0f, 22, L"l_10646");
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"我负责放钉子,你负责用锤子将他们敲进去.", 60, 0, 800, 200, 0.0f, 0.0f, 0.0f);

		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			//状态切换
			m_Scene->m_StateMachine->Switch(STATE_HAMMER_TEACH);
		}
	}
}

void HammerConfirming::ToGameTextUpdate()
{
	CGameInput* input = CGameInput::GetGameInput();

	if (m_Mark == 0)
	{
		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("Fantastic!", 60, 60, 800, 100, 0.0f, 0.0f, 0.0f, 22, L"l_10646");
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"太棒了!", 60, 40, 800, 100, 0.0f, 0.0f, 0.0f);

		
		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
		}
	}
	else if (m_Mark == 1)
	{

		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("There instructions get pretty complicated,so make sure you keep,an ear out for the change in rhythm.", 60, 60, 800, 100, 0.0f, 0.0f, 0.0f, 22, L"l_10646");
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"接下来会变得复杂一些,请一定注意节奏的变化.", 60, 40, 800, 100, 0.0f, 0.0f, 0.0f);

		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
		}
	}
	else if (m_Mark >= 2)
	{

		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("Let's build this!", 60, 60, 800, 100, 0.0f, 0.0f, 0.0f, 22, L"l_10646");
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"我们开始吧.", 60, 40, 800, 100, 0.0f, 0.0f, 0.0f);

		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();

			m_Scene->m_StateMachine->Switch(STATE_HAMMER_GAME);
		}
	}
}

void HammerConfirming::PlayAudio()
{
	CAudioManager::Get().PlayOnceAudio("CatTurn");
}
