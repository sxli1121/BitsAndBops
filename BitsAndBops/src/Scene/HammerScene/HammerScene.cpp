#include "HammerScene.h"
#include "Audio/AudioManager.h"
#include "Tools/Timer.h"
#include "Scene/HammerScene/States/HammerOpening.h"
#include "States/hammerTeaching.h"
#include "States/hammerConfirming.h"
#include "States/hammerGaming.h"
#include "States/hammerSettlementing.h"
#include "OutPutAndInput/Gameinput.h"
#include "Scene/HammerScene/GameModeHammerTime.h"
#include "Renderer/TextureManager.h"
#include "OutPutAndInput/Camera.h"
#include "Renderer/Renderer.h"
//#include "Tools/TimerStamp.h"

void CHammerScene::Init()
{
	Camera camera;
	camera.GetViewProjMatrix();

	////����
	TextureManager::Load("hammer_title_screen", L"Assets/Textures/FristRound/Pic/hammer_time_title_screen.png");
	////����
	CAudioManager::Get().PushOnceAudio("JingleDraft", "Assets/Audios/FristRound/JingleDraft.wav");
	//�ȴ��Ի���ʱ������
	CAudioManager::Get().PushLoopAudio("construction_ambience", "Assets/Audios/FristRound/construction_ambience.wav");
	//�Ի���ȷ��
	CAudioManager::Get().PushOnceAudio("CatTurn","Assets/Audios/FristRound/SFX_FS_CatTurn.wav");
	////�̳�
	//CAudioManager::Get().PushOnceAudio("Bits And Bops TUTORIAL 110", "Assets/Audios/FristRound/Bits And Bops TUTORIAL 110.wav");
	////����Ч����Ч-����
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailHammerHit", "Assets/Audios/FristRound/SFX_HT_NailHammerHit.wav");
	////�����б
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailMissTilt", "Assets/Audios/FristRound/SFX_HT_NailMissTilt.wav");
	////��΢ƫ��
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailPlace", "Assets/Audios/FristRound/SFX_HT_NailPlace.wav");


	////��Ϸ����ͼƬ����Ч
	////��
	TextureManager::Load("hand1", L"Assets/Textures/FristRound/Pic/hand_1.png");
	TextureManager::Load("hand2", L"Assets/Textures/FristRound/Pic/hand_2.png");
	TextureManager::Load("hand3", L"Assets/Textures/FristRound/Pic/hand_3.png");
	TextureManager::Load("hand_smear",L"Assets/Textures/FristRound/Pic/hand_smear.png");


	//�Ի���
	TextureManager::Load("tutorial_textbox", L"Assets/Textures/FristRound/Pic/tutorial_textbox.png");
	//
	////����
	TextureManager::Load("hammer", L"Assets/Textures/FristRound/Pic/hammer.png");
	////gameoutput->AddPic("hammer", "hammer", 0, 0, 1479, 1001);
	////����Ч��
	//TextureManager::Load("hammer_effect_almost_1", L"Assets/Textures/FristRound/Pic/hammer_effect_almost_1.png");
	//gameoutput->AddPic("hammer_almost1", "hammer_effect_almost_1", 0, 0, 46, 125);
	//TextureManager::Load("hammer_effect_almost_2", L"Assets/Textures/FristRound/Pic/hammer_effect_almost_2.png");
	//gameoutput->AddPic("hammer_almost2", "hammer_effect_almost_2", 0, 0, 41, 116);
	TextureManager::Load("hammer_effect_hit", L"Assets/Textures/FristRound/Pic/hammer_effect_hit.png");
	//gameoutput->AddPic("hammer_hit", "hammer_effect_hit", 0, 0, 332, 58);
	TextureManager::Load("hammer_effect_perfect", L"Assets/Textures/FristRound/Pic/hammer_effect_perfect.png");
	//gameoutput->AddPic("hammer_perfect", "hammer_effect_perfect", 0, 0, 409, 91);
	//
	////�����Դ�Ч��
	TextureManager::Load("hammer_smear", L"Assets/Textures/FristRound/Pic/hammer_smear.png");
	
	
	////����
	TextureManager::Load("nail_normal_1", L"Assets/Textures/FristRound/Pic/nail_normal_1.png");
	TextureManager::Load("nail_normal_2", L"Assets/Textures/FristRound/Pic/nail_normal_2.png");
	TextureManager::Load("nail_normal_3", L"Assets/Textures/FristRound/Pic/nail_normal_3.png");
	TextureManager::Load("nail_normal_4", L"Assets/Textures/FristRound/Pic/nail_normal_4.png");
	TextureManager::Load("nail_normal_5", L"Assets/Textures/FristRound/Pic/nail_normal_5.png");
	TextureManager::Load("nail_normal_6", L"Assets/Textures/FristRound/Pic/nail_normal_6.png");
	TextureManager::Load("nail_normal_7", L"Assets/Textures/FristRound/Pic/nail_normal_7.png");
	//
	//��ʾ��
	TextureManager::Load("bg_texture", L"Assets/Textures/FristRound/Pic/bg_texture.png");
	TextureManager::Load("Clear", L"Assets/Textures/FristRound/Pic/Clear.png");
	TextureManager::Load("fg", L"Assets/Textures/FristRound/Pic/fg.png");
	TextureManager::Load("fg_numbers", L"Assets/Textures/FristRound/Pic/fg_numbers.png");

	//����
	TextureManager::Load("wood_centre", L"Assets/Textures/FristRound/Pic/wood_centre.png");
	
	TextureManager::Load("wood_left", L"Assets/Textures/FristRound/Pic/wood_left.png");

	TextureManager::Load("wood_right",L"Assets/Textures/FristRound/Pic/wood_right.png");
	
	//���㻷�ڵ�ͼƬ����Ч
	//1
	TextureManager::Load("results_art_hammertime_amazing",L"Assets/Textures/FristRound/Pic/results_art_hammertime_amazing.png");
	TextureManager::Load("results_art_hammertime_cool",L"Assets/Textures/FristRound/Pic/results_art_hammertime_cool.png");
	TextureManager::Load("results_art_hammertime_tryagain", L"Assets/Textures/FristRound/Pic/results_art_hammertime_tryagain.png");
	//2
	TextureManager::Load("amazing_sticker", L"Assets/Textures/FristRound/Pic/perfect_sticker.png");
	TextureManager::Load("cool_sticker", L"Assets/Textures/FristRound/Pic/cool_sticker.png");
	TextureManager::Load("tryagain_sticker",L"Assets/Textures/FristRound/Pic/tryagain_sticker.png");
	
	TextureManager::Load("bop", L"Assets/Textures/MeetTweet/wren_angry_1.png");

	//������Ч
	CAudioManager::Get().PushOnceAudio("AMAZING", "Assets/Audios/FristRound/AMAZING.wav");
	CAudioManager::Get().PushOnceAudio("COOL", "Assets/Audios/FristRound/COOL.wav");
	CAudioManager::Get().PushOnceAudio("TRY AGAIN", "Assets/Audios/FristRound/TRY AGAIN.wav");


	//��ʽ
	CAudioManager::Get().PushOnceAudio("HammerTime", "Assets/Audios/FristRound/HammerTime.wav");
	
	//״̬����
	m_StateMachine = new StateMachine();
	//״̬
	m_OpeningState = new HammerOpening(this);
	m_TeachingState = new HammerTeaching(this);
	m_ConfirmState = new HammerConfirming(this);
	m_GameState = new HammerGaming(this);
	m_SettlementState = new HammerSettlementing(this);
	//����״̬����
	m_StateMachine->AddState(STATE_HAMMER_OPEN, m_OpeningState);
	m_StateMachine->AddState(STATE_HAMMER_TEACH, m_TeachingState);
	m_StateMachine->AddState(STATE_HAMMER_CONFIRM, m_ConfirmState);
	m_StateMachine->AddState(STATE_HAMMER_GAME, m_GameState);
	m_StateMachine->AddState(STATE_HAMMER_SETTLEMENT, m_SettlementState);
	//���ó�ʼ״̬
	m_StateMachine->Switch(STATE_HAMMER_GAME);



	CAudioManager::Get().PushOnceAudio("Bits And Bops TUTORIAL 120", "Assets/Audios/FristRound/Bits And Bops TUTORIAL 120.wav");
	//TextureManager::Load("nail_normal_1", L"Assets/Textures/FristRound/Pic/nail_normal_1.png");



	//CAudioManager::Get().PlayOnceAudio("Bits And Bops TUTORIAL 120");
	m_gameModeHammerTime = new GameModeHammerTime;



	//�����
	m_Camera.SetOrtho(0, 0, 960, 540);
}

void CHammerScene::Update(float dt)
{
	// RenderTest
	//auto input = CGameInput::GetGameInput();
	//if (input->IsKeyPressed(_GI_K_W))
	//{
	//	m_CameraPosition += Vector2(0, -1.0f) * 100 * dt;
	//}
	//if (input->IsKeyPressed(_GI_K_S))
	//{
	//	m_CameraPosition += Vector2(0, 1.0f) * 100 * dt;
	//}
	//if (input->IsKeyPressed(_GI_K_A))
	//{
	//	m_CameraPosition += Vector2(-1, 0) * 100 * dt;
	//}
	//if (input->IsKeyPressed(_GI_K_D))
	//{
	//	m_CameraPosition += Vector2(1, 0) * 100 * dt;
	//}
	//if (input->IsKeyPressed(_GI_K_Q))
	//{
	//	m_CameraRotation -= 100 * dt;
	//}
	//if (input->IsKeyPressed(_GI_K_E))
	//{
	//	m_CameraRotation += 100 * dt;
	//}
	//if (input->IsKeyPressed(_GI_K_Z))
	//{
	//	m_CameraScale -= 1 * dt;
	//}
	//if (input->IsKeyPressed(_GI_K_X))
	//{
	//	m_CameraScale += 1 * dt;
	//}


	m_Camera.SetScale(m_CameraScale);
	m_Camera.SetRotation(m_CameraRotation);
	m_Camera.SetOrtho(m_CameraPosition.x, m_CameraPosition.y, 960, 540);
	Renderer::SetViewProjection(m_Camera.GetViewProjMatrix());

	//Renderer::DrawTexture("bop", 0, 0,100.0f,100.0f,0,0,0);
	//Renderer::DrawString("Hello,World", 0, 0, 100, 100);

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
}

