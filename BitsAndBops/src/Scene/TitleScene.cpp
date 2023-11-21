#include "TitleScene.h"
#include "Audio/AudioManager.h"
#include "Core/FrameWork.h"
#include "Math/Math.h"
#include "OutputAndInput/GameInput.h"
#include "Renderer/Renderer.h"
#include "Renderer/TextureManager.h"

struct TitleDate
{
	Camera m_Camera;
	static constexpr int NumPatternsInRow = 8;
	Vector2 m_PatternPosition[NumPatternsInRow];
	const int PatternOffset = 3;
	const float PatternWidth = 326;
	const float PatternHeight = 311;

	GameMode m_ButtomMark;
};

//特殊单例方式
TitleDate titleScene;

void CTitleScene::Init()
{
	TextureManager::Load("title_screen_pattern", L"Assets/Textures/StartScreen/title_screen_pattern.png");
	TextureManager::Load("bg_sky", L"Assets/Textures/StartScreen/bg_sky.png");
	TextureManager::Load("cover_bg_logo_only_transparent", L"Assets/Textures/StartScreen/cover_bg_logo_only_transparent.png");
	CAudioManager::Get().PushOnceAudio("SFX_Menu_Splash_to_Menu", "Assets/Audios/Menu/SFX_Menu_Splash_to_Menu.wav");

	titleScene.m_Camera.SetOrtho(0, 0, 960, 540);
	for (int i = 0; i < titleScene.NumPatternsInRow; i++)
	{
		float x = (i - titleScene.PatternOffset) * titleScene.PatternWidth;
		titleScene.m_PatternPosition[i] = { x,0 };
	}


	titleScene.m_ButtomMark = GameMode::Mode_English;
}

void CTitleScene::End()
{
	CAudioManager::Get().StopLoopAudio("Bits and Bops Title (LOOP SEGMENT)");
}

GameMode CTitleScene::GetGameMode()
{
	return titleScene.m_ButtomMark;
}

void CTitleScene::Update(float dt)
{
	float speed = 200.0f;
	Vector2 v{ 1.0f,0.0f };
	float maxX = titleScene.PatternWidth * (titleScene.NumPatternsInRow - titleScene.PatternOffset);
	for (int i = 0; i < titleScene.NumPatternsInRow; i++)
	{
		titleScene.m_PatternPosition[i] += (v * speed * dt);
		
		if (titleScene.m_PatternPosition[i].x >= maxX)
		{
			titleScene.m_PatternPosition[i].x = -titleScene.PatternOffset * titleScene.PatternWidth + fmodf(titleScene.m_PatternPosition[i].x, maxX);
		}
	}

	OnRender();

	CGameInput* input = CGameInput::GetGameInput();

	if (input->GetKeyState(_GI_K_W) == _KS_UC || input->GetKeyState(_GI_K_S) == _KS_UC
		|| input->GetKeyState(_GI_K_UP) == _KS_UC || input->GetKeyState(_GI_K_DOWN) == _KS_UC)
	{
		CAudioManager::Get().PlayOnceAudio("SFX_Menu_Splash_to_Menu");

		if (titleScene.m_ButtomMark == GameMode::Mode_English)
			titleScene.m_ButtomMark = GameMode::Mode_Chinese;
		else
			titleScene.m_ButtomMark = GameMode::Mode_English;

	}
	

	if (input->GetKeyState(_GI_K_SPACE) == _KS_UC || input->GetKeyState(_GI_K_RETURN) == _KS_UC)
	{
		CFrameWork* frameWork = CFrameWork::GetFrameWork();
		frameWork->SetNextScene("Menu");
	}

}

void CTitleScene::OnRender()
{
	Renderer::SetViewProjection(titleScene.m_Camera.GetViewProjMatrix());
	Renderer::Clear(0.0f, 0.0f, 0.0f);
	Renderer::DrawTexture("bg_sky", 0,0, 960,540, 0.0f, 0.0f,0.0f);

	Matrix3f rm = Matrix3f::Rotate(Math::Deg2Rad(-20.0f));

	for (int i = 0; i < titleScene.NumPatternsInRow; i++)
	{

		for (int j = -3; j < 3; j++)
		{
			Renderer::DrawTexture("title_screen_pattern", titleScene.m_PatternPosition[i] + Vector2(j*300, 540 - titleScene.PatternHeight * j), { titleScene.PatternWidth,titleScene.PatternHeight}, 0, {0,0},rm);
		}
	}

	Renderer::DrawTexture("cover_bg_logo_only_transparent", 280, 20, 386, 244.5f, 0.0f, 0.0f, 0.0f);

	if (titleScene.m_ButtomMark == GameMode::Mode_English)
	{
		Renderer::DrawString("English", 380, 240, 300, 200, 1, 1, 1, 35,L"BAUHS93");
		Renderer::DrawString(u8"简体中文", 380, 320, 300, 200, 0, 14.0f / 255, 82.0f / 255, 32,L"STHUPO");
	}
	if (titleScene.m_ButtomMark == GameMode::Mode_Chinese)
	{
		Renderer::DrawString("English", 380, 240, 300, 200, 0,14.0f / 255, 82.0f / 255, 35,L"BAUHS93");
		Renderer::DrawString(u8"简体中文", 380, 320, 300, 200, 1, 1, 1,35, L"STHUPO");
	}


}