#include "HammerTeaching.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Scene/HammerScene/States/HammerConfirming.h"

#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"

void HammerTeaching::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("Bits And Bops TUTORIAL 120");

	//m_Remainung = 3;

	HammerLevel* CurrentLevel = new HammerLevel;
	CurrentLevel->levelName = LevelName::HAMMER_TEACH;
	CurrentLevel->Duration = 24.0f;
	CurrentLevel->BPM = 120;
	CurrentLevel->BeatsPerMeasure = 4;

	CurrentLevel->Blocks.push_back({
		{0,1,2}
		});
	CurrentLevel->Blocks.push_back({
		{8,9,10}
		});
	CurrentLevel->Blocks.push_back({
		{16,17,18}
		});
	CurrentLevel->Blocks.push_back({
	{24,25,26}
		});
	CurrentLevel->Blocks.push_back({
	{32,33,34}
		});
	CurrentLevel->Blocks.push_back({
	{40,41,42}
		});

	m_Scene->m_gameModeHammerTime->Init();
	m_Scene->m_gameModeHammerTime->Play(CurrentLevel);

	m_timer.Begin();

	m_Scene->m_CameraRotation = 0;
	m_Scene->m_CameraScale = 0.9f;
}

void HammerTeaching::OnUpdate(float dt)
{
	m_Scene->m_gameModeHammerTime->Update(dt);
	m_Scene->m_gameModeHammerTime->Render();

	double time = m_timer.GetTimerMilliSec();

	if (time >=  25000)
	{
		Renderer::Clear(0, 0, 0);
	}

	if (time >= 26000 )
	{
		m_Scene->GetStateMachine()->Switch(STATE_HAMMER_CONFIRM);
		m_Scene->m_ConfirmState->SetStateMark(ToState::STATE_GAME);
	}

}

void HammerTeaching::OnExit()
{
 
}
