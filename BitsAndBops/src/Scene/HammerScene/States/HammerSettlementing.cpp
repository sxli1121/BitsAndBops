#include "HammerSettlementing.h"
#include "Scene/HammerScene/GameModeHammerTime.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Core/FrameWork.h"
#include  "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "Tools/Timer.h"
#include "OutPutAndInput/GameInput.h"

void HammerSettlementing::OnEnter()
{
	m_timer.Begin();

	//float grades = m_Scene->m_gameModeHammerTime->GetGrades();
	float grades = 1.0f;
	if (grades > 0.9f)
	{
		m_Grades = GradesResule::GRADES_AMAZING;
	}
	else if (grades > 0.8f)
	{
		m_Grades = GradesResule::GRADES_COOL;
	}
	else
	{
		m_Grades = GradesResule::GRADES_TRYAGAIN;
	}

	CAudioManager::Get().PlayLoopAudio("construction_ambience");


	m_Scene->m_CameraRotation = 0.0f;
	m_Scene->m_CameraScale = 1.0f;

}

void HammerSettlementing::OnUpdate(float dt)
{
	double currentTime = m_timer.GetTimerMilliSec();

	Renderer(currentTime);
	PlayAudio(currentTime);


	if (m_Grades == GradesResule::GRADES_AMAZING)
	{
		if (m_IsAudioPlay == false && currentTime >= 1000)
		{
			CAudioManager::Get().PlayOnceAudio("AMAZING");
			m_IsAudioPlay = true;
		}
			
	}
	else if (m_Grades == GradesResule::GRADES_COOL)
	{
		if (m_IsAudioPlay == false && currentTime >= 3000)
		{
			CAudioManager::Get().PlayOnceAudio("COOL");
			m_IsAudioPlay = true;
		}
	}
	else
	{
		if (m_IsAudioPlay == false && currentTime >= 3000)
		{
			CAudioManager::Get().PlayOnceAudio("TRY AGAIN");
			m_IsAudioPlay = true;
		}
	}


	CGameInput* input = CGameInput::GetGameInput();

	if (currentTime >= 6000 && input->GetKeyState(_GI_K_SPACE) == _KS_UC)
	{
		OnExit();
		CFrameWork* frameWork = CFrameWork::GetFrameWork();
		frameWork->SetNextScene("Menu");
	}
}


void HammerSettlementing::OnExit()
{
	CAudioManager::Get().StopLoopAudio("construction_ambience");
}

void HammerSettlementing::Renderer(double currentTime)
{
	
	if (m_Grades == GradesResule::GRADES_AMAZING)
	{
		Renderer::DrawTexture("results_art_hammertime_amazing", 300, 30, 326.5f, 226.5f);
		if (currentTime >= 1000)
		{
			if (m_Scene->m_GameMode == GameMode::Mode_English)
				Renderer::DrawString("It looks just like the picture!", 320, 240, 400, 100);
			else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
				Renderer::DrawString(u8"看起来就像这张图片一样!", 320, 230, 400, 100 );
		}
		if (currentTime >= 2000)
		{
			Renderer::DrawTexture("amazing_sticker", 320, 350, 293, 158.5f);
		}

	}
	else if (m_Grades == GradesResule::GRADES_COOL)
	{
		Renderer::DrawTexture("results_art_hammertime_cool", 300, 30, 326.5f, 226.5f);
		if (currentTime >= 1000)
		{
			if (m_Scene->m_GameMode == GameMode::Mode_English)
				Renderer::DrawString("This looks like it will hold together!", 300, 240, 400, 100);
			else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
				Renderer::DrawString(u8"嗯 这看起来像粘在一起了一样.", 300, 230, 400, 100);
		}
		if (currentTime >= 2000)
		{
			Renderer::DrawTexture("cool_sticker", 340, 350, 241.5f, 152);
		}
	}
	else
	{
		Renderer::DrawTexture("results_art_hammertime_tryagain", 300, 30, 326.5f, 226.5f);
		if (currentTime >= 1000)
		{
			if (m_Scene->m_GameMode == GameMode::Mode_English)
				Renderer::DrawString("I hope this covered under warranty.", 300, 240, 400, 100);
			else if (m_Scene->m_GameMode == GameMode::Mode_Chinese)
				Renderer::DrawString(u8"希望还能保修.", 350, 230, 400, 100);
		}
		if (currentTime >= 2000)
		{
			Renderer::DrawTexture("tryagain_sticker", 340, 350, 214, 172);
		}
	}

}



void HammerSettlementing::PlayAudio(double currenttime)
{

	if (m_IsTextAudioPlay == false && currenttime >= 1000)
	{
		CAudioManager::Get().PlayOnceAudio("SFX_HT_NailHammerHit");
		m_IsTextAudioPlay = true;
	}

	if (m_Grades == GradesResule::GRADES_AMAZING)
	{
		
		if (m_IsAudioPlay == false && currenttime >= 2000)
		{
			CAudioManager::Get().PlayOnceAudio("AMAZING");
			m_IsAudioPlay = true;
		}
	}
	else if (m_Grades == GradesResule::GRADES_COOL)
	{
		if (m_IsAudioPlay == false && currenttime >= 2000)
		{
			CAudioManager::Get().PlayOnceAudio("COOL");
			m_IsAudioPlay = true;
		}
	}
	else
	{
		if (m_IsAudioPlay == false && currenttime >= 2000)
		{
			CAudioManager::Get().PlayOnceAudio("TRY AGAIN");
			m_IsAudioPlay = true;
		}
	}
}



