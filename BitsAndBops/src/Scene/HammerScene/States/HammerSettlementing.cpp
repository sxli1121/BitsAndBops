#include "HammerSettlementing.h"
#include "Scene/HammerScene/GameModeHammerTime.h"
#include "Scene/HammerScene/HammerScene.h"
#include  "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "Core/Time.h"
#include "Tools/Timer.h"

void HammerSettlementing::OnEnter()
{
	m_timer.Begin();

	float grades = m_Scene->m_gameModeHammerTime->GetGrades();

	//grades = 0.5;

	if (grades > 0.9)
	{
		m_Grades = GradesResule::GRADES_AMAZING;
	}
	else if (grades > 0.75)
	{
		m_Grades = GradesResule::GRADES_COOL;
	}
	else
	{
		m_Grades = GradesResule::GRADES_TRYAGAIN;
	}

	CAudioManager::Get().PlayLoopAudio("construction_ambience");
}

void HammerSettlementing::OnUpdate(float dt)
{
	//结果图 文字 音效与效果图
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
			Renderer::DrawTex(u8"It looks just like the picture!", 350, 270, 400, 100);
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
			Renderer::DrawTex("This looks like it will hold together!", 330, 270, 400, 100);
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
			Renderer::DrawTex("I hope this covered under warranty.", 325, 270, 400, 100);
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



