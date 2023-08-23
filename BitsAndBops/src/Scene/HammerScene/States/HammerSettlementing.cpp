#include "HammerSettlementing.h"
#include "Scene/HammerScene/GameModeHammerTime.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Renderer/Renderer.h"
#include "Core/Time.h"

void HammerSettlementing::OnEnter()
{
	m_StartTime = Time::GetRealtimeSinceStartup();

	float grades = m_Scene->m_gameModeHammerTime->GetGrades();
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
}

void HammerSettlementing::OnUpdate(float dt)
{
	if (m_Grades == GradesResule::GRADES_AMAZING)
	{
		Renderer::DrawTexture("results_art_hammertime_amazing", 400, 100, 326.5f, 226.5f);
	}
	else if (m_Grades == GradesResule::GRADES_COOL)
	{
		Renderer::DrawTexture("results_art_hammertime_cool", 400, 100, 326.5f, 226.5f);
	}
	else
	{
		Renderer::DrawTexture("results_art_hammertime_tryagain", 400, 100, 326.5f, 226.5f);
	}

	float CurrentTime = Time::GetRealtimeSinceStartup() - m_StartTime;
	//if(CurrentTime > )
}

void HammerSettlementing::OnExit()
{
}
