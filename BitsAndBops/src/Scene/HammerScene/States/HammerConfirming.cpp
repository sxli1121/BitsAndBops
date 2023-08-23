#include "HammerConfirming.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "OutPutAndInput/GameInput.h"



void HammerConfirming::OnEnter()
{
	CAudioManager::Get().PlayLoopAudio("construction_ambience");
	m_Mark = 0;


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

	//正式场景更新
	if (m_StateMark == ToState::STATE_GAME)
	{
		ToGameTextUpdate();
	}
	
}

void HammerConfirming::OnExit()
{


}

void HammerConfirming::ToTeachTextUpdate()
{
	CGameInput* input = CGameInput::GetGameInput();

	if (m_Mark == 0)
	{
		Renderer::DrawTex("Let's build something!", 50, 50, 800, 100, 0.0f, 0.0f, 0.0f);
		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
		}
	}
	else if (m_Mark == 1)
	{
		Renderer::DrawTex("I'll put the nail downs,and you hammer time in.", 50, 50, 800, 100, 0.0f, 0.0f, 0.0f);
		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
			//状态切换
		}
	}
}

void HammerConfirming::ToGameTextUpdate()
{
	CGameInput* input = CGameInput::GetGameInput();

	if (m_Mark == 0)
	{
		Renderer::DrawTex("Fantastic!", 50, 50, 800, 100, 0.0f, 0.0f, 0.0f);
		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
		}
	}
	else if (m_Mark == 1)
	{
		Renderer::DrawTex("There instructions get pretty complicated,so make sure you keep,an ear out for the change in rhythm.", 50, 50, 800, 100, 0.0f, 0.0f, 0.0f);
		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
		}
	}
	else if (m_Mark == 2)
	{
		Renderer::DrawTex("Let's build this!", 50, 50, 800, 100, 0.0f, 0.0f, 0.0f);
		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
			//状态切换
		}
	}
}

void HammerConfirming::PlayAudio()
{
	CAudioManager::Get().PlayOnceAudio("CatTurn");
}
