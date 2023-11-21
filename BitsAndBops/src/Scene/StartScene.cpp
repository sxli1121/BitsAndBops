#include "StartScene.h"
#include "OutputAndInput/GameInput.h"
#include "Audio/AudioManager.h"
#include "Core/FrameWork.h"

#include "Scene/HammerScene/HammerScene.h"
#include "Renderer/Renderer.h"
#include  "Core/Time.h"
#include "Renderer/TextureManager.h"

void CStartScene::Init()
{
	// 背景
	TextureManager::Load("Background", L"Assets/Textures/StartScreen/Opening/cover_bg.png");
	//logo
	TextureManager::Load("Logo", L"Assets/Textures/StartScreen/Opening/cover_bg_logo_only_transparent.png");
	//动漫人物
	TextureManager::Load("cover_birbs", L"Assets/Textures/StartScreen/Opening/cover_birbs.png");
	TextureManager::Load("cover_boybear", L"Assets/Textures/StartScreen/Opening/cover_boybear.png");
	TextureManager::Load("cover_catto", L"Assets/Textures/StartScreen/Opening/cover_catto.png");
	TextureManager::Load("cover_dancer", L"Assets/Textures/StartScreen/Opening/cover_dancer.png");
	TextureManager::Load("cover_girlbear", L"Assets/Textures/StartScreen/Opening/cover_girlbear.png");
	TextureManager::Load("cover_mascots", L"Assets/Textures/StartScreen/Opening/cover_mascots.png");
	TextureManager::Load("cover_moleleft", L"Assets/Textures/StartScreen/Opening/cover_moleleft.png");
	TextureManager::Load("cover_moleright", L"Assets/Textures/StartScreen/Opening/cover_moleright.png");
	TextureManager::Load("cover_monke", L"Assets/Textures/StartScreen/Opening/cover_monke.png");
	TextureManager::Load("cover_robot", L"Assets/Textures/StartScreen/Opening/cover_robot.png");
	TextureManager::Load("cover_snakecharmer", L"Assets/Textures/StartScreen/Opening/cover_snakecharmer.png");

	//音效
	CAudioManager::Get().PushLoopAudio("Bits and Bops Title (LOOP SEGMENT)","Assets/Audios/Screen/Bits and Bops Title (LOOP SEGMENT).wav");
	CAudioManager::Get().PushOnceAudio("Bits and Bops Title (TWO BAR INTRO)", "Assets/Audios/Screen/Bits and Bops Title (TWO BAR INTRO).wav");
	CAudioManager::Get().PlayOnceAudio("Bits and Bops Title (TWO BAR INTRO)");

	m_Timer.Begin();
	m_StartTime = 0;
	m_IsLoopAudioPlay = false;

	m_CameraRotation = 0;
	m_CameraScale = 1.0f;
	m_Camera.SetOrtho(0, 0, 960, 540);

	m_small = 1.0f;
	m_middle = 2.0f;
	m_big = 3.0f;
}

void CStartScene::Update(float dt)
{

	m_Camera.SetScale(m_CameraScale);
	m_Camera.SetRotation(m_CameraRotation);
	m_Camera.SetOrtho(m_CameraPosition.x, m_CameraPosition.y, 960, 540);
	Renderer::SetViewProjection(m_Camera.GetViewProjMatrix());

	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;
	if(currentTime >= 3.8f && m_IsLoopAudioPlay==false)
	{
		CAudioManager::Get().PlayLoopAudio("Bits and Bops Title (LOOP SEGMENT)");
		m_IsLoopAudioPlay = true;
	}


	float uniteBeatTime = 60.0f / 480.0f;
	double time = m_Timer.GetTimerMilliSec();
	if(time/1000 > uniteBeatTime * 4)
	{
		m_Timer.Begin();
	}

	if(time/1000 >= 0 || time/1000 >= uniteBeatTime * 2)
	{
		Renderer::DrawTexture("Background", 0, 0, 1024, 576);

		Renderer::DrawTexture("Logo", 287, 10, 386, 244.5f);
		Renderer::DrawTexture("cover_mascots", 350, 290, 250.4, 207.6);
		//left
		Renderer::DrawTexture("cover_snakecharmer", 0, 100, 189.5f, 236);
		Renderer::DrawTexture("cover_monke", 20, 20, 131, 135.5);
		Renderer::DrawTexture("cover_moleleft", 20, 20, 264.5f, 130.5f);
		Renderer::DrawTexture("cover_dancer", 10, 20, 349.5f, 521.5f);
		Renderer::DrawTexture("cover_robot", 0, 170, 206.5f, 341);
		//right
		Renderer::DrawTexture("cover_birbs", 680, 20, 108.5f, 73);
		Renderer::DrawTexture("cover_moleright", 780, 20, 131.2, 133.6f);
		Renderer::DrawTexture("cover_girlbear", 590, 200, 293.5f, 353.5f);
		Renderer::DrawTexture("cover_boybear", 750, 100, 225, 286.5f);
		Renderer::DrawTexture("cover_catto", 700, 170, 270.5f, 390.5f);
	}
	if (time/1000 >= 1 || time/1000 >= uniteBeatTime * 3)
	{
		Renderer::DrawTexture("Background", 0, 0, 1024, 576);

		Renderer::DrawTexture("Logo", 287, 10, 386, 244.5f + m_small);
		Renderer::DrawTexture("cover_mascots", 350, 290, 250.4, 207.6 + m_big);
		//left- x-  y+
		Renderer::DrawTexture("cover_snakecharmer", 0, 100, 189.5f - m_middle, 236 + m_middle);
		Renderer::DrawTexture("cover_monke", 20, 20, 131 - m_small, 135.5 + m_small);            //猴子
		Renderer::DrawTexture("cover_moleleft", 20, 20, 264.5f - m_middle, 130.5f + m_small);     //老鼠
		Renderer::DrawTexture("cover_dancer", 10, 20, 349.5f - m_big, 521.5f + m_big);
		Renderer::DrawTexture("cover_robot", 0, 170, 206.5f - m_big, 341 + m_big);
		//right  x+ y+
		Renderer::DrawTexture("cover_birbs", 680, 20, 108.5f + m_small, 73 + m_small);
		Renderer::DrawTexture("cover_moleright", 780, 20, 131.2 + m_small, 133.6f + m_small);    //老鼠
		Renderer::DrawTexture("cover_girlbear", 590, 200, 293.5f + m_big, 353.5f + m_big);   //紫色熊
		Renderer::DrawTexture("cover_boybear", 750, 100, 225 + m_middle, 286.5f + m_middle);       //蓝色熊
		Renderer::DrawTexture("cover_catto", 700, 170, 270.5f + m_big, 390.5f + m_big);
	}

	
	CGameInput* input = CGameInput::GetGameInput();


	if(currentTime >= 5.0f)
	{
		Renderer::DrawString("Start Play...", 605, 350, 400, 200, 1,1, 1, 60, L"BAUHS93");

		if (input->GetKeyState(_GI_K_SPACE) == _KS_UC)
		{
			CFrameWork* frameWork = CFrameWork::GetFrameWork();
			frameWork->SetNextScene("Title");
		}
	}
}

void CStartScene::End()
{

}
