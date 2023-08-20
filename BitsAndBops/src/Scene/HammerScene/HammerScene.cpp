#include "HammerScene.h"
#include "OutputAndInput/GameOutput.h"
#include "Audio/AudioManager.h"
#include "Math/Matrix.h"
#include "Tools/Timer.h"
#include "States/HammerOpening.h"
#include "States/hammerTeaching.h"
#include "States/hammerConfirming.h"
#include "States/hammerGaming.h"
#include "States/hammerSettlementing.h"
#include "Animation/HammerAnimation.h"

//#include "Tools/TimerStamp.h"

void CHammerScene::Init()
{
	CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	//进场
	gameoutput->AddImg("hammer_title_screen", "Assets/Textures/FristRound/Pic/hammer_time_title_screen.png");
	gameoutput->AddPic("hammer_title", "hammer_title_screen", 0, 0, 1920, 1080);
	//进场
	CAudioManager::Get().PushOnceAudio("JingleDraft", "Assets/Audios/FristRound/JingleDraft.wav");
	//等待对话框时背景音
	CAudioManager::Get().PushOnceAudio("construction_ambience", "Assets/Audios/FristRound/construction_ambience.wav");
	//对话框确认
	CAudioManager::Get().PushLoopAudio("CatTurn","Assets/Audios/FristRound/JingleDraft.wav");
	//教程
	CAudioManager::Get().PushOnceAudio("Bits And Bops TUTORIAL 110", "Assets/Audios/FristRound/Bits And Bops TUTORIAL 110.wav");
	//钉子效果音效-击中
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailHammerHit", "Assets/Audios/FristRound/SFX_HT_NailHammerHit.wav");
	//错过倾斜
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailMissTilt", "Assets/Audios/FristRound/SFX_HT_NailMissTilt.wav");
	//稍微偏差
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailPlace", "Assets/Audios/FristRound/SFX_HT_NailPlace.wav");


	//游戏环节图片与音效
	//手
	gameoutput->AddImg("hand1", "Assets/Textures/FristRound/Pic/hand_1.png");
	gameoutput->AddPic("hand1", "hand1", 0, 0, 1068, 1305);

	gameoutput->AddImg("hand2", "Assets/Textures/FristRound/Pic/hand_2.png");
	gameoutput->AddPic("hand2", "hand2", 0, 0, 1079, 1305);
	gameoutput->AddImg("hand3", "Assets/Textures/FristRound/Pic/hand_3.png");
	gameoutput->AddPic("hand3", "hand3", 0, 0, 1084, 1305);
	gameoutput->AddImg("hand_smear", "Assets/Textures/FristRound/Pic/hand_smear.png");
	gameoutput->AddPic("hand_smear", "hand_smear", 0, 0, 978, 1305);
	
	//锤子
	gameoutput->AddImg("hammer", "Assets/Textures/FristRound/Pic/hammer.png");
	gameoutput->AddPic("hammer", "hammer", 0, 0, 1479, 1001);
	//锤子效果
	gameoutput->AddImg("hammer_effect_almost_1", "Assets/Textures/FristRound/Pic/hammer_effect_almost_1.png");
	gameoutput->AddPic("hammer_almost1", "hammer_effect_almost_1", 0, 0, 46, 125);
	gameoutput->AddImg("hammer_effect_almost_2", "Assets/Textures/FristRound/Pic/hammer_effect_almost_2.png");
	gameoutput->AddPic("hammer_almost2", "hammer_effect_almost_2", 0, 0, 41, 116);
	gameoutput->AddImg("hammer_effect_hit", "Assets/Textures/FristRound/Pic/hammer_effect_hit.png");
	gameoutput->AddPic("hammer_hit", "hammer_effect_hit", 0, 0, 332, 58);
	gameoutput->AddImg("hammer_effect_perfect", "Assets/Textures/FristRound/Pic/hammer_effect_perfect.png");
	gameoutput->AddPic("hammer_perfect", "hammer_effect_perfect", 0, 0, 409, 91);
	//锤子自带效果
	gameoutput->AddImg("hammer_smear", "Assets/Textures/FristRound/Pic/hammer_smear.png");
	gameoutput->AddPic("hammer_smear", "hammer_smear", 0, 0, 431, 985);
	
	//钉子
	gameoutput->AddImg("nail_normal_1", "Assets/Textures/FristRound/Pic/nail_normal_1.png");
	gameoutput->AddPic("nail_normal1", "nail_normal_1", 0, 0, 81, 209);
	gameoutput->AddImg("nail_normal_2", "Assets/Textures/FristRound/Pic/nail_normal_2.png");
	gameoutput->AddPic("nail_normal2", "nail_normal_2", 0, 0, 81, 197);
	gameoutput->AddImg("nail_normal_3", "Assets/Textures/FristRound/Pic/nail_normal_3.png");
	gameoutput->AddPic("nail_normal3", "nail_normal_3", 0, 0, 156, 82);
	gameoutput->AddImg("nail_normal_4", "Assets/Textures/FristRound/Pic/nail_normal_4.png");
	gameoutput->AddPic("nail_normal4", "nail_normal_4", 0, 0, 150, 101);
	gameoutput->AddImg("nail_normal_5", "Assets/Textures/FristRound/Pic/nail_normal_5.png");
	gameoutput->AddPic("nail_normal5", "nail_normal_5", 0, 0, 153, 95);
	gameoutput->AddImg("nail_normal_6", "Assets/Textures/FristRound/Pic/nail_normal_6.png");
	gameoutput->AddPic("nail_normal6", "nail_normal_6", 0, 0, 157, 84);
	gameoutput->AddImg("nail_normal_7", "Assets/Textures/FristRound/Pic/nail_normal_7.png");
	gameoutput->AddPic("nail_normal7", "nail_normal_7", 0, 0, 86, 25);
	
	//显示框
	gameoutput->AddImg("fg", "Assets/Textures/FristRound/Pic/fg.png");
	gameoutput->AddPic("fg", "fg", 0, 0, 1988, 1988);
	//箱子
	gameoutput->AddImg("wood_centre", "Assets/Textures/FristRound/Pic/wood_centre.png");
	gameoutput->AddPic("wood_centre", "wood_centre", 0, 0, 470, 234);
	gameoutput->AddImg("wood_left", "Assets/Textures/FristRound/Pic/wood_left.png");
	gameoutput->AddPic("wood_left", "wood_left", 0, 0, 63, 234);
	gameoutput->AddImg("wood_right", "Assets/Textures/FristRound/Pic/wood_right.png");
	gameoutput->AddPic("wood_right", "wood_right", 0, 0, 63, 234);
	
	
	//结算环节的图片与音效
	//1
	gameoutput->AddImg("results_art_hammertime_amazing", "Assets/Textures/FristRound/Pic/results_art_hammertime_amazing.png");
	gameoutput->AddPic("amazing", "results_art_hammertime_amazing", 0, 0, 653, 453);
	gameoutput->AddImg("results_art_hammertime_cool", "Assets/Textures/FristRound/Pic/results_art_hammertime_cool.png");
	gameoutput->AddPic("cool", "results_art_hammertime_cool", 0, 0, 653, 453);
	gameoutput->AddImg("results_art_hammertime_tryagain", "Assets/Textures/FristRound/Pic/hammer_time_title_screen.png");
	gameoutput->AddPic("tryagain", "results_art_hammertime_tryagain", 0, 0, 653, 453);
	//2
	gameoutput->AddImg("amazing_sticker", "Assets/Textures/FristRound/Pic/amazing_sticker.png");
	gameoutput->AddPic("amazing_sticker", "amazing_sticker", 0, 0, 586, 317);
	gameoutput->AddImg("cool_sticker", "Assets/Textures/FristRound/Pic/cool_sticker.png");
	gameoutput->AddPic("cool_sticker", "cool_sticker", 0, 0, 483, 304);
	gameoutput->AddImg("tryagain_sticker", "Assets/Textures/FristRound/Pic/tryagain_sticker.png");
	gameoutput->AddPic("tryagain_sticker", "tryagain_sticker", 0, 0, 428, 344);
	
	
	
	//对话框确认
	CAudioManager::Get().PushOnceAudio("CatTurn", "Assets/Audios/FristRound/SFX_FS_CatTurn.wav");
	//正式背景
	CAudioManager::Get().PushOnceAudio("HammerTime", "Assets/Audios/FristRound/HammerTime.wav");
	//钉子效果音效-击中
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailHammerHit", "Assets/Audios/FristRound/SFX_HT_NailHammerHit.wav");
	//错过倾斜
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailMissTilt", "Assets/Audios/FristRound/SFX_HT_NailMissTilt.wav");
	//稍微偏差
	CAudioManager::Get().PushOnceAudio("SFX_HT_NailPlace", "Assets/Audios/FristRound/SFX_HT_NailPlace.wav");



	float m_time[] =
	{
		0.0f , 1.0f , 2.0f ,
		8.0f , 9.0f , 10.0f,
		16.0f, 17.0f, 18.0f,
		24.0f, 25.0f, 26.0f,
		32.0f, 33.0f, 34.0f,
		40.0f, 41.0f, 42.0f
	};
	m_TeachTimeManage = new TimerStampManage;
	//初始化时间戳
	m_TeachTimeManage->AddTimeStamp(m_time, 18);
	//状态初始化
	//m_State = HAMMER_OPEN;
	//时间初始化
	//m_Timer.Begin();


	gameoutput->AddImg("1", "Assets/Textures/1.png");
	gameoutput->AddPic("c", "1", 0, 0, 1920, 1080);

	//CAudioManager::Get().PlayOnceAudio("JingleDraft");

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
	m_StateMachine->Switch(STATE_HAMMER_TEACH);


	m_hammer = new CHammer;
	m_hammer->Init();
}

void CHammerScene::Update(float dt)
{

	m_StateMachine->Update(dt);


	//CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	//double time = m_Timer.GetTimerMilliSec();
	//float speed = 100;
	//static float x = 10.0f;

	//if (m_State == HAMMER_OPEN)
	//{
	//	//开场
	//	//图片
	//	Matrix33 m,sm;
	//	x += speed*dt;
	//	m.Translate(x,0);
	//	//sm.Scale(0.2, 0.2);
	//	//m = sm * m;
	//	//gameoutput->DrawPic("hammer_title", &m);
	//	gameoutput->DrawPic("c",&m);
	//	//音乐
	//	//CAudioManager::Get().PlayOnceAudio("JingleDraft");

	//	//获取时间- 时间确认 状态切换
	//}
	//else if (m_State == HAMMER_CONFIRM)
	//{
	//	//确认
	//	//画面--（一样的背景与对话框）-（不同的文字） 按下按键切换绘制的文字

	//	//gameoutput->DrawTxt();
	//	//音乐
	//	//CAudioManager::Get().PlayLoopAudio("CatTurn");
	//	
	//}
	//else if (m_State == HAMMER_TEACH)
	//{


	//	//教学环节--有自己的数组
	//	//按下按键的时候获取  到时间获取
	//	//按下按键- 判断是否与时间戳相同  播放不同音效

	//	//到时间没有获取到按键- 播放音效
	//	//时间戳判断
	//	//晚--过了时间戳	time 过了当前时间戳+最大范围值--播放音效--  当前时间戳 作废



	//	//time 
	//	//按键
	//	//早--还未到时间戳   按键时 time <  有作用的第一个时间戳--最大范围值   播放没打到音效
	//	//正好-与时间戳相同  按键时 time 在当前时间戳+-最大范围值/中间范围值/最小范围值 中间--播放打偏/打到音效--当前时间戳 作废
	//	//晚--过了时间戳	   按键时 time 过了当前时间戳+最大范围值--播放音效--  当前时间戳 作废



	//	CAudioManager::Get().PlayLoopAudio("Bits And Bops TUTORIAL 110");

	//}


}

void CHammerScene::End()
{
	delete m_StateMachine;
	delete m_OpeningState;
	delete m_TeachingState;
}
