#include "HammerTeaching.h"
#include "Scene/HammerScene/HammerScene.h"

#include "OutputAndInput/GameInput.h"
#include "Audio/AudioManager.h"
#include "Math/Matrix.h"
#include "GameParticipator/MobileStation.h"
#include "Animation/Animation.h"
#include "Animation/HammerAnimation.h"



void HammerTeaching::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("Bits And Bops TUTORIAL 120");


	HammerLevel* CurrentLevel = new HammerLevel;
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

}

void HammerTeaching::OnUpdate(float dt)
{
	m_Scene->m_gameModeHammerTime->Update(dt);
	m_Scene->m_gameModeHammerTime->Render();


}

void HammerTeaching::OnExit()
{
}
