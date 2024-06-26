﻿#include "HammerGaming.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "Math/Matrix.h"
#include "Tools/Timer.h"

void HammerGaming::OnEnter()
{
	CAudioManager::Get().PlayOnceAudio("HammerTime");
	m_timer.Begin();
	//配置关卡
	HammerLevel* CurrentLevel = new HammerLevel;
	CurrentLevel->levelName = LevelName::HAMMER_GAME;
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
	{104.0f, 104.5f, 105.0f, 106.5f, 107.0f, 107.5f }
				});
			CurrentLevel->Blocks.push_back({
	{112.0f, 113.0f, 114.5f, 115.5f   }
				});
			CurrentLevel->Blocks.push_back({
	{ 120.0f, 120.5f, 121.0f, 121.5f, 122.0f, 122.75f }
				});
	//缩小
			CurrentLevel->Blocks.push_back({
	{128.0f, 128.75f, 129.5f }
				});
	//旋转 左
			CurrentLevel->Blocks.push_back({
	{136.0f, 137.0f, 138.0f, 138.75f  }
				});
	//旋转 右 放大
			CurrentLevel->Blocks.push_back({
    {144.0f, 146.5f, 147.0f, 147.5f   }
    				});
	//缩小
    			CurrentLevel->Blocks.push_back({
    {152.0f, 152.5f, 153.0f, 153.5f, 154.5f, 155.5f    }
    				});
	//倒着
    			CurrentLevel->Blocks.push_back({
    {160.0f, 160.5f, 161.5f, 162.5f, 163.5f  }
    				});
	//右面旋转
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


	m_Scene->m_CameraRotation = 15;
	m_Scene->m_CameraScale = 1.2f;


	m_scorer = 0;
	mobile1x = 50;
	mobile2x = 620;

	m_Scene->m_gameModeHammerTime->Init();
	m_Scene->m_gameModeHammerTime->Play(CurrentLevel);

}

void HammerGaming::OnUpdate(float dt)
{

	m_Scene->m_gameModeHammerTime->Update(dt);
	m_Scene->m_gameModeHammerTime->Render();


	float UniteBeatTime = 60.0f / 130.0f;

	double OpenOffTime = 14.0f * UniteBeatTime;
	float targetRotation = 0;
	float targetScale = 0.8f;

	if(m_timer.GetTimerMilliSec()/1000.0f <= 14.0f * UniteBeatTime)
	{
		float speedTrasRotation = (15.0f - targetRotation) / OpenOffTime;
		float speedTrasScale = (1.2f - targetScale) / OpenOffTime;

		m_Scene->m_CameraRotation -=  speedTrasRotation * dt;
		m_Scene->m_CameraScale -= speedTrasScale * dt;

		if(m_Scene->m_CameraRotation <= 0 && m_Scene->m_CameraScale <= 0.7f)
		{
			m_Scene->m_CameraRotation = 0;
			m_Scene->m_CameraScale = targetScale;
		}

		if(m_timer.GetTimerMilliSec() / 1000.0f <= 12.0f * UniteBeatTime)
		{

			Renderer::DrawTexture("nail_normal_7", 685, 320, 28.57f, 8.33f, 0, 0.5f, 1.0f);
			Renderer::DrawTexture("hammer", 1145.5f, -20, 499, 333.67f, 0, 1, 0);

			Renderer::DrawTexture("hand2", 185, 270, 361.33f, 435, 15.0f, 0.868f, 0.927f);
			Renderer::DrawTexture("nail_normal_1", 185, 320, 27, 69.67f, 0, 0.5f, 1.0f);

			Renderer::DrawTexture("wood_centre", 50, 318, 215, 78, 0, 0, 0);
			Renderer::DrawTexture("wood_right", 255, 318, 31.5f, 78, 0, 0, 0);

			Renderer::DrawTexture("wood_left", 620, 318, 31.5f, 78, 0, 0, 0);
			Renderer::DrawTexture("wood_centre", 645.5f, 318, 280, 78, 0, 0, 0);
		}
		else
		{
			float speedMobileMove = 4.0f * UniteBeatTime;

			mobile1x -= speedMobileMove * dt;
			mobile2x += speedMobileMove * dt;

			Renderer::DrawTexture("wood_centre", mobile1x, 318, 215, 78, 0, 0, 0);
			Renderer::DrawTexture("wood_right", mobile1x + 195, 318, 31.5f, 78, 0, 0, 0);

			Renderer::DrawTexture("wood_left", mobile2x, 318, 31.5f, 78, 0, 0, 0);
			Renderer::DrawTexture("wood_centre", mobile2x + 25.5f, 318, 280, 78, 0, 0, 0);

		}
		Renderer::DrawTexture("bg_texture", 480, 15, 2500, 579, 0, 0.5f, 1);
		Renderer::DrawTexture("bg_texture", 10, 10, 2500, 579, 0, 1, 0);
		Renderer::DrawTexture("bg_texture", 10, 590, 2500, 579, 0, 1, 0);
		Renderer::DrawTexture("bg_texture", 950, 10, 2500, 579, 0, 0, 0);
		Renderer::DrawTexture("bg_texture", 950, 590, 2500, 579, 0, 0, 0);


		Renderer::DrawTexture("fg", 0, 0, 960, 960);
		Renderer::DrawTexture("fg_numbers", 320, 100, 540, 486.277f);


	}
	else if(m_timer.GetTimerMilliSec()/1000.0f >= OpenOffTime)
	{
		m_Scene->m_CameraRotation = 0;
		m_Scene->m_CameraScale = targetScale;
	}


	double time = m_timer.GetTimerMilliSec();
	//镜头的变换
	if (time / 1000 >= UniteBeatTime * 64.0f)
	{
		m_Scene->m_CameraScale = 1.2f;
	}
	if ((time / 1000 >= UniteBeatTime * 80.0f && time / 1000 < UniteBeatTime * 84.0f)
		|| (time / 1000 >= UniteBeatTime * 88.0f && time / 1000 < UniteBeatTime * 92.0f)
		|| (time / 1000 >= UniteBeatTime * 96.0f && time / 1000 < UniteBeatTime * 100.0f)
		|| (time / 1000 >= UniteBeatTime * 104.0f && time / 1000 < UniteBeatTime * 108.0f)
		|| (time / 1000 >= UniteBeatTime * 112.0f && time / 1000 < UniteBeatTime * 116.0f)
		|| (time / 1000 >= UniteBeatTime * 120.0f && time / 1000 < UniteBeatTime * 124.0f))
	{
		m_Scene->m_CameraScale = 0.5f;
		m_Scene->m_CameraPosition = { -150,-30 };
	}
	if ((time / 1000 >= UniteBeatTime * 84.0f && time / 1000 < UniteBeatTime * 88.0f)
			|| (time / 1000 >= UniteBeatTime * 92.0f && time / 1000 < UniteBeatTime * 96.0f)
			|| (time / 1000 >= UniteBeatTime * 100.0f && time / 1000 < UniteBeatTime * 104.0f)
			|| (time / 1000 >= UniteBeatTime * 108.0f && time / 1000 < UniteBeatTime * 112.0f)
			|| (time / 1000 >= UniteBeatTime * 116.0f && time / 1000 < UniteBeatTime * 120.0f)
			|| (time / 1000 >= UniteBeatTime * 124.0f && time / 1000 < UniteBeatTime * 128.0f))
	{
		m_Scene->m_CameraScale = 0.5f;
		m_Scene->m_CameraPosition = { 100,-30 };
	}


	if (time / 1000 >= UniteBeatTime * 128.0f)
	{
		m_Scene->m_CameraScale = 0.7f;
		m_Scene->m_CameraPosition = {0,0};
	}
	if (time / 1000 >= UniteBeatTime * 128.75)
	{
		m_Scene->m_CameraScale = 0.9f;
		m_Scene->m_CameraPosition = { 0,0 };
	}
	if (time / 1000 >= UniteBeatTime * 129.5f)
	{
		m_Scene->m_CameraScale = 1.1f;
		m_Scene->m_CameraPosition = { 0,0 };
	}


	if (time / 1000 >= UniteBeatTime * 132.0f)
	{
		m_Scene->m_CameraScale = 1.2f;
		m_Scene->m_CameraPosition = { 0,0 };
	}
	if (time / 1000 >= UniteBeatTime * 132.75)
	{
		m_Scene->m_CameraScale = 1.4f;
		m_Scene->m_CameraPosition = { 0,0 };
	}
	if (time / 1000 >= UniteBeatTime * 133.5f)
	{
		m_Scene->m_CameraScale = 1.5f;
		m_Scene->m_CameraPosition = { 0,0 };
	}

	
	if (time / 1000 >= UniteBeatTime * 136.0f)
	{
		m_Scene->m_CameraScale = 1.2f;
		m_Scene->m_CameraRotation = 10;
	}
	if (time / 1000 >= UniteBeatTime * 144.0f)
	{
		m_Scene->m_CameraScale = 0.8f;
		m_Scene->m_CameraRotation = -10;
	}
	if (time / 1000 >= UniteBeatTime * 152.0f)
	{
		m_Scene->m_CameraScale = 1.1f;
		m_Scene->m_CameraRotation = -10;
	}
	if (time / 1000 >= UniteBeatTime * 160.0f)
	{
		m_Scene->m_CameraScale = 1.1f;
		m_Scene->m_CameraRotation = -170;
	}

	if (time / 1000 >= UniteBeatTime * 168.0f)
	{
		m_Scene->m_CameraScale = 0.8f;
		m_Scene->m_CameraRotation = 20;
	}

	if (time / 1000 >= UniteBeatTime * 200)
	{
		m_Scene->m_CameraScale = 0.8f;
		m_Scene->m_CameraRotation = 0;
	}




	if (time >= 108000)
	{
		Renderer::Clear(0, 0, 0);
	}
	if (time >= 108500)
	{
		m_Scene->GetStateMachine()->Switch(STATE_HAMMER_SETTLEMENT);
	}
}

void HammerGaming::OnExit()
{

}
