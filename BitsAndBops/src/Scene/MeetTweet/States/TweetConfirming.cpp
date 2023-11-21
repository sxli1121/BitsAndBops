#include "TweetConfirming.h"
#include "Scene/MeetTweet/MeetTweetScene.h"
#include "OutPutAndInput/GameInput.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"

void TweetConfirming::OnEnter()
{
	CAudioManager::Get().PlayLoopAudio("SFX_MT_Ambience");
	m_Mark = 0;

	m_Scene->m_CameraRotation = 0;
	m_Scene->m_CameraScale = 1.0f;
}

void TweetConfirming::OnUpdate(float dt)
{
	Renderer::DrawTexture("bg_outside", 0, -150, 960, 690);
	Renderer::DrawTexture("bg_inside", 0, -150, 960, 690);
	Renderer::DrawTexture("radio", 90, 56, 279.5f, 276);
	Renderer::DrawTexture("canary_perch", 550, 340, 174, 200.5f);
	Renderer::DrawTexture("canary_bop_1", 625, 340, 294.5f, 275, 0, 0.205f, 0.925f);

	Renderer::DrawTexture("tutorial_textbox", 50, 380, 871, 136, 0, 0, 0);

	if (m_StateMark == ToState::STATE_TEACHONE)
	{
		ToTeachOneTextUpdate();
	}

	if (m_StateMark == ToState::STATE_TEACHTWO)
	{
		ToTeachTwoTextUpdate();
	}

	//正式场景更新
	if (m_StateMark == ToState::STATE_GAME)
	{
		ToGameTextUpdate();
	}
}

void TweetConfirming::OnExit()
{
	CAudioManager::Get().StopLoopAudio("SFX_MT_Ambience");

}

void TweetConfirming::ToTeachOneTextUpdate()
{
	CGameInput* input = CGameInput::GetGameInput();

	if (m_Mark == 0)
	{
		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("Canary loves to chat!", 60, 370, 800, 100, 0.0f, 0.0f, 0.0f);
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"金丝雀喜欢聊天。", 60, 370, 800, 100, 0.0f, 0.0f, 0.0f);


		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
		}
	}
	else if (m_Mark >= 1)
	{
		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("Listen for the question, then tap Space to respond.", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"仔细听问题，然后用空格键作出回应。", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);

		
		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
			//状态切换
			m_Scene->m_StateMachine->Switch(STATE_TWEET_TEACH1);
		}
	}
}

void TweetConfirming::ToTeachTwoTextUpdate()
{

	CGameInput* input = CGameInput::GetGameInput();

	if (m_Mark == 0)
	{
		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("Canary thinks carefully about complicated questions.", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"对于复杂的问题，金丝雀要认真思考。", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);

		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
		}
	}
	else if (m_Mark >= 1)
	{
		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("Tap Space to respond after a short delay. ", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"稍等一会，再按下空格键回应。", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);

		
		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;

			m_Scene->m_StateMachine->Switch(STATE_TWEET_TEACH2);
		}
	}

}

void TweetConfirming::ToGameTextUpdate()
{
	CGameInput* input = CGameInput::GetGameInput();

	if (m_Mark == 0)
	{
		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("Fantastic!You're a natural!", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"太棒了，你天生就是一只优秀的鸟儿", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);


		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;
		}
	}
	else if (m_Mark >= 1)
	{
		if (m_Scene->m_GameMode == GameMode::Mode_English)
			Renderer::DrawString("Now if only there were someone to talk to... ", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);
		else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
			Renderer::DrawString(u8"要是现在真有可以聊天的鸟儿就好了... ", 65, 370, 800, 100, 0.0f, 0.0f, 0.0f);

		
		if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
		{
			PlayAudio();
			m_Mark += 1;

			m_Scene->m_StateMachine->Switch(STATE_TWEET_GAME);
		}
	}

}

void TweetConfirming::PlayAudio()
{
	CAudioManager::Get().PlayOnceAudio("CatTurn");
}
