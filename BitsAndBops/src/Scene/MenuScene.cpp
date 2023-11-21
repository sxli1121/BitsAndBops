#include "MenuScene.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "Renderer/TextureManager.h"
#include "OutPutAndInput/GameInput.h"
#include "Core/FrameWork.h"

void MenuScene::Init()
{
	//¼ÓÔØ
	CAudioManager::Get().PushLoopAudio("Bits and Bops (STAGE SELECT) BAR 4 TO END", "Assets/Audios/Menu/Bits and Bops (STAGE SELECT) BAR 4 TO END.wav");
	CAudioManager::Get().PushOnceAudio("SFX_Menu_Splash_to_Menu", "Assets/Audios/Menu/SFX_Menu_Splash_to_Menu.wav");
	CAudioManager::Get().PushOnceAudio("SFX_Menu_Select", "Assets/Audios/Menu/SFX_Menu_Select.wav");

	TextureManager::Load("level_menu_bg", L"Assets/Textures/StartScreen/level_menu_bg.png");
	TextureManager::Load("level_menu_white_bg", L"Assets/Textures/StartScreen/level_menu_white_bg.png");
	TextureManager::Load("level_menu_cabinet_cover", L"Assets/Textures/StartScreen/level_menu_cabinet_cover.png");
	TextureManager::Load("level_menu_CD_hammertime", L"Assets/Textures/StartScreen/level_menu_CD_hammertime.png");
	TextureManager::Load("level_menu_CD_meetandtweet", L"Assets/Textures/StartScreen/level_menu_CD_meetandtweet.png");

	m_HammerEnterAnimayion.Reset();
	m_HammerEnterAnimayion.SetMode(AnimationMode::Once);
	m_HammerEnterAnimayion.AddFrame({0,"level_menu_white_bg",120, 10, 116, 115.5f,0,0,0 });
	m_HammerEnterAnimayion.AddFrame({ 0.05f,"level_menu_CD_hammertime",120, 10, 116, 115.5f,0,0,0});
	m_HammerEnterAnimayion.AddFrame({0.1f,"level_menu_white_bg",120, 10, 116, 115.5f,0,0,0});
	m_HammerEnterAnimayion.AddFrame({0.15f,"level_menu_CD_hammertime",120, 10, 116, 115.5f,0,0,0});
	m_HammerEnterAnimayion.AddFrame({0.2f,"level_menu_CD_hammertime",120, 10, 116, 115.5f,0,0,0});

	m_TweetEnterAnimayion.Reset();
	m_TweetEnterAnimayion.SetMode(AnimationMode::Once);
	m_TweetEnterAnimayion.AddFrame({ 0,"level_menu_white_bg", 260, 10, 116, 115.5f,0,0,0 });
	m_TweetEnterAnimayion.AddFrame({ 0.05f,"level_menu_CD_meetandtweet", 260, 10, 116, 115.5f,0,0,0 });
	m_TweetEnterAnimayion.AddFrame({ 0.1f,"level_menu_white_bg", 260, 10, 116, 115.5f,0,0,0 });
	m_TweetEnterAnimayion.AddFrame({ 0.15f,"level_menu_CD_meetandtweet", 260, 10, 116, 115.5f,0,0,0 });
	m_TweetEnterAnimayion.AddFrame({ 0.2f,"level_menu_CD_meetandtweet", 260, 10, 116, 115.5f,0,0,0 });
	
	m_Camera.SetOrtho(0, 0, 960, 540);
	m_levelName = MenuLevelName::HAMMER_TIME;
	m_ConfireLevel = MenuLevelName::NONE;

	CAudioManager::Get().PlayLoopAudio("Bits and Bops (STAGE SELECT) BAR 4 TO END");

	m_CameraRotation = 0.0f;
	m_CameraScale = 1.0f;

}

void MenuScene::Update(float dt)
{
	//»æÖÆ
	m_Camera.SetScale(m_CameraScale);
	m_Camera.SetRotation(m_CameraRotation);
	m_Camera.SetOrtho(m_CameraPosition.x, m_CameraPosition.y, 960, 540);
	Renderer::SetViewProjection(m_Camera.GetViewProjMatrix());

	Renderer::DrawTexture("level_menu_bg", 0, 0, 960, 540,0,0,0);
	Renderer::DrawTexture("level_menu_cabinet_cover", 686, 9, 172.5f, 127.5f);
	Renderer::DrawTexture("level_menu_cabinet_cover", 686, 138, 172.5f, 127.5f);
	Renderer::DrawTexture("level_menu_cabinet_cover", 686, 268, 172.5f, 127.5f);
	Renderer::DrawTexture("level_menu_cabinet_cover", 686, 399, 172.5f, 127.5f);

	CGameInput* input = CGameInput::GetGameInput();
	if(input->GetKeyState(_GI_K_A)== _KS_UC || input->GetKeyState(_GI_K_D) == _KS_UC
		|| input->GetKeyState(_GI_K_LEFT) == _KS_UC || input->GetKeyState(_GI_K_RIGHT) == _KS_UC)
	{
		CAudioManager::Get().PlayOnceAudio("SFX_Menu_Select");

		if (m_levelName == MenuLevelName::HAMMER_TIME)
			m_levelName = MenuLevelName::METTE_TWETTE;
		else
			m_levelName = MenuLevelName::HAMMER_TIME;
	}


	if (m_levelName == MenuLevelName::HAMMER_TIME)
	{
		Renderer::DrawTexture("level_menu_CD_hammertime", 120, 10, 116, 115.5f);
		Renderer::DrawTexture("level_menu_CD_meetandtweet", 260, 20, 116, 115.5f);

		if(input->GetKeyState(_GI_K_SPACE) == _KS_UC  || input->GetKeyState(_GI_K_RETURN) == _KS_UC)
		{
			m_HammerEnterAnimayion.Play();
			CAudioManager::Get().PlayOnceAudio("SFX_Menu_Splash_to_Menu");

			m_Timer.Begin();
			m_ConfireLevel = MenuLevelName::HAMMER_TIME;

		}
	}
	else 	if (m_levelName == MenuLevelName::METTE_TWETTE)
	{
		Renderer::DrawTexture("level_menu_CD_hammertime", 120, 20, 116, 115.5f);
		Renderer::DrawTexture("level_menu_CD_meetandtweet", 260, 10, 116, 115.5f);

		if (input->GetKeyState(_GI_K_SPACE) == _KS_UC || input->GetKeyState(_GI_K_RETURN) == _KS_UC)
		{
			m_TweetEnterAnimayion.Play();
			CAudioManager::Get().PlayOnceAudio("SFX_Menu_Splash_to_Menu");

			m_Timer.Begin();
			m_ConfireLevel = MenuLevelName::METTE_TWETTE;
		}
	}


	m_HammerEnterAnimayion.Update(dt);
	m_TweetEnterAnimayion.Update(dt);
	if(m_HammerEnterAnimayion.IsPlaying())
	{
		m_HammerEnterAnimayion.Render();
	}
	if (m_TweetEnterAnimayion.IsPlaying())
	{
		m_TweetEnterAnimayion.Render();
	}


	if(m_Timer.GetTimerMilliSec() / 1000 >= 1)
	{
		if(m_ConfireLevel ==  MenuLevelName::HAMMER_TIME )
		{
			CFrameWork* frameWork = CFrameWork::GetFrameWork();
			frameWork->SetNextScene("Hammer");
		}
		else if (m_ConfireLevel == MenuLevelName::METTE_TWETTE)
		{
			CFrameWork* frameWork = CFrameWork::GetFrameWork();
			frameWork->SetNextScene("MeetTweet");
		}
	}

}

void MenuScene::End()
{
	CAudioManager::Get().StopLoopAudio("Bits and Bops (STAGE SELECT) BAR 4 TO END");
}
