#include "HammerGaming.h"
#include "Scene/HammerScene/HammerScene.h"

#include "OutputAndInput/GameInput.h"
#include "Audio/AudioManager.h"
#include "Math/Matrix.h"
#include "GameParticipator/MobileStation.h"
#include "Animation/Animation.h"
#include "Animation/HammerAnimation.h"


void HammerGaming::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("HammerTime");
	//ÅäÖÃ¹Ø¿¨
	HammerLevel* CurrentLevel = new HammerLevel;
	CurrentLevel->Duration = 108.0f;
	CurrentLevel->BPM = 130;
	CurrentLevel->BeatsPerMeasure = 4;

	CurrentLevel->Blocks.push_back({
		{16,17,18}
		});
	CurrentLevel->Blocks.push_back({
		{24,25,26}
		});
	CurrentLevel->Blocks.push_back({
		{32.0f, 33.0f, 34.0f, 34.75f}
		});
	CurrentLevel->Blocks.push_back({
	{40.0f, 40.5f, 41.0f, 41.5f, 42.0f, 42.75f }
		});
	CurrentLevel->Blocks.push_back({
	{48.0f, 49.0f, 50.0f, 50.75f }
		});
	CurrentLevel->Blocks.push_back({
	{57.5f, 58.0f, 58.75f, 59.5f }
		});
	CurrentLevel->Blocks.push_back({
	{64.0f, 65.5f, 66.0f }
			});
		CurrentLevel->Blocks.push_back({
	{72.0f, 72.5f, 73.0f, 73.5f}
			});
		CurrentLevel->Blocks.push_back({
	{80.0f, 80.5f, 81.0f, 81.5f, 82.0f }
			});
		CurrentLevel->Blocks.push_back({
	{88.0f, 90.5f, 91.5f  }
			});
		CurrentLevel->Blocks.push_back({
	{96.0f, 97.0f, 98.0f, 98.75f  }
		});
		CurrentLevel->Blocks.push_back({
	{104.0f, 104.5f, 105.0f, 106.5f, 107.0f, 107.5f  }
				});
			CurrentLevel->Blocks.push_back({
	{112.0f, 113.0f, 114.5f, 115.5f   }
				});
			CurrentLevel->Blocks.push_back({
	{ 120.0f, 120.5f, 121.0f, 121.5f, 122.0f, 122.75f   }
				});
			CurrentLevel->Blocks.push_back({
	{128.0f, 128.75f, 129.5f }
				});
			CurrentLevel->Blocks.push_back({
	{136.0f, 137.0f, 138.0f, 138.75f  }
				});
			CurrentLevel->Blocks.push_back({
    {144.0f, 146.5f, 147.0f, 147.5f   }
    				});
    			CurrentLevel->Blocks.push_back({
    {152.0f, 152.5f, 153.0f, 153.5f, 154.5f, 155.5f    }
    				});
    			CurrentLevel->Blocks.push_back({
    {160.0f, 160.5f, 161.5f, 162.5f, 163.5f  }
    				});
    			CurrentLevel->Blocks.push_back({
    {168.0f, 170.0f, 171.0f   }
    				});
    			CurrentLevel->Blocks.push_back({
    {176.5f, 177.5f, 178.5f, 179.5f  }
    				});
    			CurrentLevel->Blocks.push_back({
    {184.5f, 185.5f, 186.5f }
    				});
    			CurrentLevel->Blocks.push_back({
    {192.0f, 193.0f, 194.0f  }
    				});
    			CurrentLevel->Blocks.push_back({
    {200.0f, 202.0f, 202.5f, 203.5f, 204.5f }
    				});
    			CurrentLevel->Blocks.push_back({
    {216.0f, 218.5f, 219.5f, 220.5f }
    				});
    
    
	m_Scene->m_gameModeHammerTime->Init();
	m_Scene->m_gameModeHammerTime->Play(CurrentLevel);

}

void HammerGaming::OnUpdate(float dt)
{
	m_Scene->m_gameModeHammerTime->Update(dt);
	m_Scene->m_gameModeHammerTime->Render();
	


}

void HammerGaming::OnExit()
{

}
