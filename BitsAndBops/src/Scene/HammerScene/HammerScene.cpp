#include "HammerScene.h"
#include "Audio/AudioManager.h"
#include "Tools/Timer.h"
#include "Scene/HammerScene/States/HammerOpening.h"
#include "States/hammerTeaching.h"
#include "States/hammerConfirming.h"
#include "States/hammerGaming.h"
#include "States/hammerSettlementing.h"
#include "Scene/HammerScene/GameModeHammerTime.h"
#include "Renderer/TextureManager.h"
#include "OutPutAndInput/Camera.h"
#include "Renderer/Renderer.h"
#include "Scene/TitleScene.h"


void CHammerScene::Init()
{
	Camera camera;
	camera.GetViewProjMatrix();

	////进场
	TextureManager::Load("hammer_title_screen", L"Assets/Textures/FristRound/Pic/hammer_time_title_screen.png");
	////进场
	CAudioManager::Get().PushOnceAudio("JingleDraft", "Assets/Audios/FristRound/JingleDraft.wav");
	//等待对话框时背景音
	CAudioManager::Get().PushLoopAudio("construction_ambience", "Assets/Audios/FristRound/construction_ambience.wav");
	//对话框确认
	CAudioManager::Get().PushOnceAudio("CatTurn","Assets/Audios/FristRound/SFX_FS_CatTurn.wav");
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
	TextureManager::Load("hand_smear",L"Assets/Textures/FristRound/Pic/hand_smear.png");

	//对话框
	TextureManager::Load("tutorial_textbox", L"Assets/Textures/FristRound/Pic/tutorial_textbox.png");
	
	////锤子
	TextureManager::Load("hammer", L"Assets/Textures/FristRound/Pic/hammer.png");
	////锤子效果
	TextureManager::Load("hammer_effect_hit", L"Assets/Textures/FristRound/Pic/hammer_effect_hit.png");
	TextureManager::Load("hammer_effect_perfect", L"Assets/Textures/FristRound/Pic/hammer_effect_perfect.png");
	////锤子自带效果
	TextureManager::Load("hammer_smear", L"Assets/Textures/FristRound/Pic/hammer_smear.png");
	
	//钉子
	TextureManager::Load("nail_normal_1", L"Assets/Textures/FristRound/Pic/nail_normal_1.png");
	TextureManager::Load("nail_normal_2", L"Assets/Textures/FristRound/Pic/nail_normal_2.png");
	TextureManager::Load("nail_normal_3", L"Assets/Textures/FristRound/Pic/nail_normal_3.png");
	TextureManager::Load("nail_normal_4", L"Assets/Textures/FristRound/Pic/nail_normal_4.png");
	TextureManager::Load("nail_normal_5", L"Assets/Textures/FristRound/Pic/nail_normal_5.png");
	TextureManager::Load("nail_normal_6", L"Assets/Textures/FristRound/Pic/nail_normal_6.png");
	TextureManager::Load("nail_normal_7", L"Assets/Textures/FristRound/Pic/nail_normal_7.png");
	//
	//显示框
	TextureManager::Load("bg_texture", L"Assets/Textures/FristRound/Pic/bg_texture.png");
	TextureManager::Load("Clear", L"Assets/Textures/FristRound/Pic/Clear.png");
	TextureManager::Load("fg", L"Assets/Textures/FristRound/Pic/fg.png");
	TextureManager::Load("fg_numbers", L"Assets/Textures/FristRound/Pic/fg_numbers.png");

	//箱子
	TextureManager::Load("wood_centre", L"Assets/Textures/FristRound/Pic/wood_centre.png");
	TextureManager::Load("wood_left", L"Assets/Textures/FristRound/Pic/wood_left.png");
	TextureManager::Load("wood_right",L"Assets/Textures/FristRound/Pic/wood_right.png");
	
	//结算环节的图片与音效
	//1
	TextureManager::Load("results_art_hammertime_amazing",L"Assets/Textures/FristRound/Pic/results_art_hammertime_amazing.png");
	TextureManager::Load("results_art_hammertime_cool",L"Assets/Textures/FristRound/Pic/results_art_hammertime_cool.png");
	TextureManager::Load("results_art_hammertime_tryagain", L"Assets/Textures/FristRound/Pic/results_art_hammertime_tryagain.png");
	//2
	TextureManager::Load("amazing_sticker", L"Assets/Textures/FristRound/Pic/perfect_sticker.png");
	TextureManager::Load("cool_sticker", L"Assets/Textures/FristRound/Pic/cool_sticker.png");
	TextureManager::Load("tryagain_sticker",L"Assets/Textures/FristRound/Pic/tryagain_sticker.png");
	//结算音效
	CAudioManager::Get().PushOnceAudio("AMAZING", "Assets/Audios/FristRound/AMAZING.wav");
	CAudioManager::Get().PushOnceAudio("COOL", "Assets/Audios/FristRound/COOL.wav");
	CAudioManager::Get().PushOnceAudio("TRY AGAIN", "Assets/Audios/FristRound/TRY AGAIN.wav");

	//正式
	CAudioManager::Get().PushOnceAudio("HammerTime", "Assets/Audios/FristRound/HammerTime.wav");
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
	m_StateMachine->Switch(STATE_HAMMER_SETTLEMENT);

	m_GameMode = CTitleScene::GetGameMode();

	m_gameModeHammerTime = new GameModeHammerTime;
	CAudioManager::Get().PushOnceAudio("Bits And Bops TUTORIAL 120", "Assets/Audios/FristRound/Bits And Bops TUTORIAL 120.wav");
	//摄像机
	m_Camera.SetOrtho(0, 0, 960, 540);
}

void CHammerScene::Update(float dt)
{
	m_Camera.SetScale(m_CameraScale);
	m_Camera.SetRotation(m_CameraRotation);
	m_Camera.SetOrtho(m_CameraPosition.x, m_CameraPosition.y, 960, 540);

	Renderer::SetViewProjection(m_Camera.GetViewProjMatrix());

	m_StateMachine->Update(dt);
	 
}

void CHammerScene::End()
{
	delete m_StateMachine;
	delete m_OpeningState;
	delete m_TeachingState;
	delete m_ConfirmState;
	delete m_GameState;
	delete m_SettlementState;
	delete m_gameModeHammerTime;
}

