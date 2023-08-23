#include "HammerScene.h"

#include "Audio/AudioManager.h"
#include "Math/Matrix.h"
#include "Tools/Timer.h"
#include "States/HammerOpening.h"
#include "States/hammerTeaching.h"
#include "States/hammerConfirming.h"
#include "States/hammerGaming.h"
#include "States/hammerSettlementing.h"
#include "Animation/HammerAnimation.h"
#include "OutPutAndInput/Gameinput.h"
#include "Scene/HammerScene/GameModeHammerTime.h"

#include "Renderer/Renderer.h"
#include "Renderer/TextureManager.h"
#include "Animation/FrameAnimation.h"
#include "Core/Time.h"

//#include "Tools/TimerStamp.h"

void CHammerScene::Init()
{	
	////进场
	TextureManager::Load("hammer_title_screen", L"Assets/Textures/FristRound/Pic/hammer_time_title_screen.png");
	////gameoutput->AddPic("hammer_title", "hammer_title_screen", 0, 0, 1920, 1080);
	////进场
	//CAudioManager::Get().PushOnceAudio("JingleDraft", "Assets/Audios/FristRound/JingleDraft.wav");
	//等待对话框时背景音
	CAudioManager::Get().PushLoopAudio("construction_ambience", "Assets/Audios/FristRound/construction_ambience.wav");
	//对话框确认
	CAudioManager::Get().PushOnceAudio("CatTurn","Assets/Audios/FristRound/SFX_FS_CatTurn.wav");
	////教程
	//CAudioManager::Get().PushOnceAudio("Bits And Bops TUTORIAL 110", "Assets/Audios/FristRound/Bits And Bops TUTORIAL 110.wav");
	////钉子效果音效-击中
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailHammerHit", "Assets/Audios/FristRound/SFX_HT_NailHammerHit.wav");
	////错过倾斜
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailMissTilt", "Assets/Audios/FristRound/SFX_HT_NailMissTilt.wav");
	////稍微偏差
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailPlace", "Assets/Audios/FristRound/SFX_HT_NailPlace.wav");


	////游戏环节图片与音效
	////手
	TextureManager::Load("hand1", L"Assets/Textures/FristRound/Pic/hand_1.png");
	TextureManager::Load("hand2", L"Assets/Textures/FristRound/Pic/hand_2.png");
	TextureManager::Load("hand3", L"Assets/Textures/FristRound/Pic/hand_3.png");
	//TextureManager::Load("hand_smear",L"Assets/Textures/FristRound/Pic/hand_smear.png");
	//////gameoutput->AddPic("hand_smear", "hand_smear", 0, 0, 978, 1305);


	//对话框
	TextureManager::Load("tutorial_textbox", L"Assets/Textures/FristRound/Pic/tutorial_textbox.png");
	//
	////锤子
	TextureManager::Load("hammer", L"Assets/Textures/FristRound/Pic/hammer.png");
	////gameoutput->AddPic("hammer", "hammer", 0, 0, 1479, 1001);
	////锤子效果
	//TextureManager::Load("hammer_effect_almost_1", L"Assets/Textures/FristRound/Pic/hammer_effect_almost_1.png");
	////gameoutput->AddPic("hammer_almost1", "hammer_effect_almost_1", 0, 0, 46, 125);
	//TextureManager::Load("hammer_effect_almost_2", L"Assets/Textures/FristRound/Pic/hammer_effect_almost_2.png");
	////gameoutput->AddPic("hammer_almost2", "hammer_effect_almost_2", 0, 0, 41, 116);
	//TextureManager::Load("hammer_effect_hit", L"Assets/Textures/FristRound/Pic/hammer_effect_hit.png");
	////gameoutput->AddPic("hammer_hit", "hammer_effect_hit", 0, 0, 332, 58);
	//TextureManager::Load("hammer_effect_perfect", L"Assets/Textures/FristRound/Pic/hammer_effect_perfect.png");
	////gameoutput->AddPic("hammer_perfect", "hammer_effect_perfect", 0, 0, 409, 91);
	//
	////锤子自带效果
	//TextureManager::Load("hammer_smear", L"Assets/Textures/FristRound/Pic/hammer_smear.png");
	////gameoutput->AddPic("hammer_smear", "hammer_smear", 0, 0, 431, 985);
	//
	////钉子
	TextureManager::Load("nail_normal_1", L"Assets/Textures/FristRound/Pic/nail_normal_1.png");
	TextureManager::Load("nail_normal_2", L"Assets/Textures/FristRound/Pic/nail_normal_2.png");
	TextureManager::Load("nail_normal_3", L"Assets/Textures/FristRound/Pic/nail_normal_3.png");
	TextureManager::Load("nail_normal_4", L"Assets/Textures/FristRound/Pic/nail_normal_4.png");
	TextureManager::Load("nail_normal_5", L"Assets/Textures/FristRound/Pic/nail_normal_5.png");
	TextureManager::Load("nail_normal_6", L"Assets/Textures/FristRound/Pic/nail_normal_6.png");
	TextureManager::Load("nail_normal_7", L"Assets/Textures/FristRound/Pic/nail_normal_7.png");
	//
	//显示框
	TextureManager::Load("fg", L"Assets/Textures/FristRound/Pic/fg.png");

	//箱子
	TextureManager::Load("wood_centre", L"Assets/Textures/FristRound/Pic/wood_centre.png");
	
	TextureManager::Load("wood_left", L"Assets/Textures/FristRound/Pic/wood_left.png");

	TextureManager::Load("wood_right",L"Assets/Textures/FristRound/Pic/wood_right.png");
	
	//结算环节的图片与音效
	//1
	TextureManager::Load("results_art_hammertime_amazing",L"Assets/Textures/FristRound/Pic/results_art_hammertime_amazing.png");
	//gameoutput->AddPic("amazing", "results_art_hammertime_amazing", 0, 0, 653, 453);
	TextureManager::Load("results_art_hammertime_cool",L"Assets/Textures/FristRound/Pic/results_art_hammertime_cool.png");
	//gameoutput->AddPic("cool", "results_art_hammertime_cool", 0, 0, 653, 453);
	TextureManager::Load("results_art_hammertime_tryagain", L"Assets/Textures/FristRound/Pic/results_art_hammertime_tryagain.png");
	//gameoutput->AddPic("tryagain", "results_art_hammertime_tryagain", 0, 0, 653, 453);
	
	//2
	TextureManager::Load("amazing_sticker", L"Assets/Textures/FristRound/Pic/amazing_sticker.png");
	//gameoutput->AddPic("amazing_sticker", "amazing_sticker", 0, 0, 586, 317);
	TextureManager::Load("cool_sticker", L"Assets/Textures/FristRound/Pic/cool_sticker.png");
	//gameoutput->AddPic("cool_sticker", "cool_sticker", 0, 0, 483, 304);
	TextureManager::Load("tryagain_sticker",L"Assets/Textures/FristRound/Pic/tryagain_sticker.png");
	//gameoutput->AddPic("tryagain_sticker", "tryagain_sticker", 0, 0, 428, 344);




	////对话框确认
	//CAudioManager::Get().PushOnceAudio("CatTurn", "Assets/Audios/FristRound/SFX_FS_CatTurn.wav");
	//正式
	CAudioManager::Get().PushOnceAudio("HammerTime", "Assets/Audios/FristRound/HammerTime.wav");
	//////钉子效果音效-击中
	////CAudioManager::Get().PushOnceAudio("SFX_HT_NailHammerHit", "Assets/Audios/FristRound/SFX_HT_NailHammerHit.wav");
	//////错过倾斜
	////CAudioManager::Get().PushOnceAudio("SFX_HT_NailMissTilt", "Assets/Audios/FristRound/SFX_HT_NailMissTilt.wav");
	//////稍微偏差
	////CAudioManager::Get().PushOnceAudio("SFX_HT_NailPlace", "Assets/Audios/FristRound/SFX_HT_NailPlace.wav");


	//状态管理
	m_StateMachine = new StateMachine();
	//状态
	m_OpeningState = new HammerOpening(this);
	m_TeachingState = new HammerTeaching(this);
	m_ConfirmState = new HammerConfirming(this);
	m_GameState = new HammerGaming(this);
	m_SettlementState = new HammerSettlementing(this);
	//加入状态管理
	m_StateMachine->AddState(STATE_HAMMER_OPEN, m_OpeningState);
	m_StateMachine->AddState(STATE_HAMMER_TEACH, m_TeachingState);
	m_StateMachine->AddState(STATE_HAMMER_CONFIRM, m_ConfirmState);
	m_StateMachine->AddState(STATE_HAMMER_GAME, m_GameState);
	m_StateMachine->AddState(STATE_HAMMER_SETTLEMENT, m_SettlementState);
	//设置初始状态
	m_StateMachine->Switch(STATE_HAMMER_GAME);


	//m_hammer = new CHammer;
	//m_hammer->Init();

	CAudioManager::Get().PushOnceAudio("Bits And Bops TUTORIAL 120", "Assets/Audios/FristRound/Bits And Bops TUTORIAL 120.wav");
	//TextureManager::Load("nail_normal_1", L"Assets/Textures/FristRound/Pic/nail_normal_1.png");



	//CAudioManager::Get().PlayOnceAudio("Bits And Bops TUTORIAL 120");

	m_gameModeHammerTime = new GameModeHammerTime;

	


}

void CHammerScene::Update(float dt)
{

	m_StateMachine->Update(dt);



	//int i = m_StateMachine->GetCurrentStateId();
	//if (i == STATE_HAMMER_OPEN)
	//	m_OpeningState->OnUpdate(dt);
	//else if (i == STATE_HAMMER_TEACH)
	//	m_TeachingState->OnUpdate(dt);



		//STATE_HAMMER_OPEN,
		//STATE_HAMMER_TEACH,
		//STATE_HAMMER_CONFIRM,
		//STATE_HAMMER_GAME,
		//STATE_HAMMER_SETTLEMENT,
	
	//m_gameModeHammerTime->Update(dt);
	//m_gameModeHammerTime->Render();





}

void CHammerScene::End()
{
	//delete m_StateMachine;
	//delete m_OpeningState;
	//delete m_TeachingState;
}

