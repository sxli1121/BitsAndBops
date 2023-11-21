#include "MeetTweetScene.h"
#include "Audio/AudioManager.h"
#include "Renderer/TextureManager.h"
#include "Renderer/Renderer.h"
#include "Scene/MeetTweet/States/TweetOpening.h"
#include "Scene/MeetTweet/States/TweetConfirming.h"
#include "Scene/MeetTweet/States/TweetTeachingOne.h"
#include "Scene/MeetTweet/States/TweetTeachingTwo.h"
#include "Scene/MeetTweet/States/TweetGaming.h"
#include "Scene/MeetTweet/States/TweetSettlementing.h"

#include "OutPutAndInput/Camera.h"
#include "Scene/TitleScene.h"


void MeetTweetScene::Init()
{
	//进场
	CAudioManager::Get().PushOnceAudio("JingleDraft", "Assets/Audios/MeetTweet/JingleDraft.wav");
	TextureManager::Load("meet_and_tweet_title_screen", L"Assets/Textures/MeetTweet/meet_and_tweet_title_screen.png");

	//背景
	TextureManager::Load("bg_outside", L"Assets/Textures/MeetTweet/bg_outside.png");
	TextureManager::Load("bg_inside", L"Assets/Textures/MeetTweet/bg_inside.png");
	TextureManager::Load("bg_inside_dark", L"Assets/Textures/MeetTweet/bg_inside_dark.png");
	//窗帘
	TextureManager::Load("bg_blind", L"Assets/Textures/MeetTweet/bg_blind.png");
	//收音机及收音机声音波
	TextureManager::Load("radio", L"Assets/Textures/MeetTweet/radio.png");
	TextureManager::Load("radio_noise_1", L"Assets/Textures/MeetTweet/radio_noise_1.png");
	TextureManager::Load("radio_noise_2", L"Assets/Textures/MeetTweet/radio_noise_2.png");
	TextureManager::Load("radio_noise_3", L"Assets/Textures/MeetTweet/radio_noise_3.png");
	//Tweet字幕和小熊
	TextureManager::Load("subtitles_1", L"Assets/Textures/MeetTweet/subtitles_1.png");
	TextureManager::Load("subtitles_2", L"Assets/Textures/MeetTweet/subtitles_2.png");
	TextureManager::Load("bop", L"Assets/Textures/MeetTweet/bop.png");

	//金丝雀
	//架子
	TextureManager::Load("canary_perch", L"Assets/Textures/MeetTweet/canary_perch.png");
	//正常状态
	TextureManager::Load("canary_bop_1", L"Assets/Textures/MeetTweet/canary_bop_1.png");
	TextureManager::Load("canary_bop_2", L"Assets/Textures/MeetTweet/canary_bop_2.png");
	//perfect
	TextureManager::Load("canary_tweet_1", L"Assets/Textures/MeetTweet/canary_tweet_1.png");
	//almost
	TextureManager::Load("canary_almost", L"Assets/Textures/MeetTweet/canary_almost.png");
	//有差别
	TextureManager::Load("canary_screech_2", L"Assets/Textures/MeetTweet/canary_screech_2.png");
	//差别很大
	TextureManager::Load("canary_screech_1", L"Assets/Textures/MeetTweet/canary_screech_1.png");
	//后续动作
	TextureManager::Load("canary_tweet_2", L"Assets/Textures/MeetTweet/canary_tweet_2.png");
	TextureManager::Load("canary_tweet_3", L"Assets/Textures/MeetTweet/canary_tweet_3.png");
	//对话框相关
	//对话框
	TextureManager::Load("canarycaptions_bubble_in_1", L"Assets/Textures/MeetTweet/canarycaptions_bubble_in_1.png");
	TextureManager::Load("canarycaptions_bubble_in_2", L"Assets/Textures/MeetTweet/canarycaptions_bubble_in_2.png");
	TextureManager::Load("canarycaptions_bubble_in_3", L"Assets/Textures/MeetTweet/canarycaptions_bubble_in_3.png");
	TextureManager::Load("canarycaptions_bubble_1", L"Assets/Textures/MeetTweet/canarycaptions_bubble_1.png");
	TextureManager::Load("canarycaptions_bubble_2", L"Assets/Textures/MeetTweet/canarycaptions_bubble_2.png");
	TextureManager::Load("canarycaptions_bubble_3", L"Assets/Textures/MeetTweet/canarycaptions_bubble_3.png");
	TextureManager::Load("canarycaptions_bubble_out", L"Assets/Textures/MeetTweet/canarycaptions_bubble_out.png");
	//金丝雀的故事
	//感叹号
	TextureManager::Load("canarycaptions_screech", L"Assets/Textures/MeetTweet/canarycaptions_screech.png");

	TextureManager::Load("canarycaptions_drawing_family_1", L"Assets/Textures/MeetTweet/canarycaptions_drawing_family_1.png");
	TextureManager::Load("canarycaptions_drawing_family_2", L"Assets/Textures/MeetTweet/canarycaptions_drawing_family_2.png");
	TextureManager::Load("canarycaptions_drawing_family_3", L"Assets/Textures/MeetTweet/canarycaptions_drawing_family_3.png");
	TextureManager::Load("canarycaptions_drawing_family_final_1", L"Assets/Textures/MeetTweet/canarycaptions_drawing_family_final_1.png");
	TextureManager::Load("canarycaptions_drawing_family_final_2", L"Assets/Textures/MeetTweet/canarycaptions_drawing_family_final_2.png");

	TextureManager::Load("canarycaptions_drawing_exercise_1", L"Assets/Textures/MeetTweet/canarycaptions_drawing_exercise_1.png");
	TextureManager::Load("canarycaptions_drawing_exercise_2", L"Assets/Textures/MeetTweet/canarycaptions_drawing_exercise_2.png");
	TextureManager::Load("canarycaptions_drawing_exercise_3", L"Assets/Textures/MeetTweet/canarycaptions_drawing_exercise_3.png");
	TextureManager::Load("canarycaptions_drawing_exercise_final_1", L"Assets/Textures/MeetTweet/canarycaptions_drawing_exercise_final_1.png");
	TextureManager::Load("canarycaptions_drawing_exercise_final_2", L"Assets/Textures/MeetTweet/canarycaptions_drawing_exercise_final_2.png");

	TextureManager::Load("canarycaptions_drawing_food_1", L"Assets/Textures/MeetTweet/canarycaptions_drawing_food_1.png");
	TextureManager::Load("canarycaptions_drawing_food_2", L"Assets/Textures/MeetTweet/canarycaptions_drawing_food_2.png");
	TextureManager::Load("canarycaptions_drawing_food_3", L"Assets/Textures/MeetTweet/canarycaptions_drawing_food_2.png");
	TextureManager::Load("canarycaptions_drawing_food_final_1", L"Assets/Textures/MeetTweet/canarycaptions_drawing_food_final_1.png");
	TextureManager::Load("canarycaptions_drawing_food_final_2", L"Assets/Textures/MeetTweet/canarycaptions_drawing_food_final_2.png");

	TextureManager::Load("canarycaptions_drawing_singing_1", L"Assets/Textures/MeetTweet/canarycaptions_drawing_singing_1.png");
	TextureManager::Load("canarycaptions_drawing_singing_2", L"Assets/Textures/MeetTweet/canarycaptions_drawing_singing_2.png");
	TextureManager::Load("canarycaptions_drawing_singing_3", L"Assets/Textures/MeetTweet/canarycaptions_drawing_singing_3.png");
	TextureManager::Load("canarycaptions_drawing_singing_final", L"Assets/Textures/MeetTweet/canarycaptions_drawing_singing_final.png");

	TextureManager::Load("canarycaptions_drawing_talking_1", L"Assets/Textures/MeetTweet/canarycaptions_drawing_talking_1.png");
	TextureManager::Load("canarycaptions_drawing_talking_2", L"Assets/Textures/MeetTweet/canarycaptions_drawing_talking_2.png");
	TextureManager::Load("canarycaptions_drawing_talking_3", L"Assets/Textures/MeetTweet/canarycaptions_drawing_talking_3.png");
	TextureManager::Load("canarycaptions_drawing_talking_final", L"Assets/Textures/MeetTweet/canarycaptions_drawing_talking_final.png");

	//最终
	//happy most
	TextureManager::Load("canary_happy_1", L"Assets/Textures/MeetTweet/canary_happy_1.png");
	//happy near
	TextureManager::Load("canary_happy_4", L"Assets/Textures/MeetTweet/canary_happy_4.png");
	//不开心
	TextureManager::Load("canary_neutral", L"Assets/Textures/MeetTweet/canary_neutral.png");


	//小蓝
	//正常状态
	TextureManager::Load("wren_bop_1", L"Assets/Textures/MeetTweet/wren_bop_1.png");
	TextureManager::Load("wren_bop_2", L"Assets/Textures/MeetTweet/wren_bop_2.png");
	//正常叫
	TextureManager::Load("wren_tweet_1", L"Assets/Textures/MeetTweet/wren_tweet_1.png");
	TextureManager::Load("wren_tweet_2", L"Assets/Textures/MeetTweet/wren_tweet_2.png");
	TextureManager::Load("wren_tweet_3", L"Assets/Textures/MeetTweet/wren_tweet_3.png");
	//笑
	TextureManager::Load("wren_giggle_1", L"Assets/Textures/MeetTweet/wren_giggle_1.png");
	TextureManager::Load("wren_giggle_2", L"Assets/Textures/MeetTweet/wren_giggle_2.png");
	TextureManager::Load("wren_giggle_3", L"Assets/Textures/MeetTweet/wren_giggle_3.png");
	//perfect and almost
	TextureManager::Load("wren_happy_1", L"Assets/Textures/MeetTweet/wren_happy_1.png");
	TextureManager::Load("wren_happy_2", L"Assets/Textures/MeetTweet/wren_happy_2.png");
	TextureManager::Load("wren_happy_3", L"Assets/Textures/MeetTweet/wren_happy_3.png");
	//有差别
	TextureManager::Load("wren_confused_1", L"Assets/Textures/MeetTweet/wren_confused_1.png");
	TextureManager::Load("wren_confused_2", L"Assets/Textures/MeetTweet/wren_confused_2.png");
	TextureManager::Load("wren_confused_3", L"Assets/Textures/MeetTweet/wren_confused_3.png");
	TextureManager::Load("wren_confused_4", L"Assets/Textures/MeetTweet/wren_confused_4.png");
	//差别很大-miss
	TextureManager::Load("wren_angry_1", L"Assets/Textures/MeetTweet/wren_angry_1.png");
	TextureManager::Load("wren_angry_2", L"Assets/Textures/MeetTweet/wren_angry_2.png");
	TextureManager::Load("wren_angry_3", L"Assets/Textures/MeetTweet/wren_angry_3.png");
	//对话框
	TextureManager::Load("wrencaptions_bubble_in_1", L"Assets/Textures/MeetTweet/wrencaptions_bubble_in_1.png");
	TextureManager::Load("wrencaptions_bubble_in_2", L"Assets/Textures/MeetTweet/wrencaptions_bubble_in_2.png");
	TextureManager::Load("wrencaptions_bubble_in_3", L"Assets/Textures/MeetTweet/wrencaptions_bubble_in_3.png");
	TextureManager::Load("wrencaptions_bubble_1", L"Assets/Textures/MeetTweet/wrencaptions_bubble_1.png");
	TextureManager::Load("wrencaptions_bubble_2", L"Assets/Textures/MeetTweet/wrencaptions_bubble_2.png");
	TextureManager::Load("wrencaptions_bubble_3", L"Assets/Textures/MeetTweet/wrencaptions_bubble_3.png");
	TextureManager::Load("wrencaptions_bubble_out", L"Assets/Textures/MeetTweet/wrencaptions_bubble_out.png");
	//小蓝的故事
	TextureManager::Load("wrencaptions_drawing_family_1", L"Assets/Textures/MeetTweet/wrencaptions_drawing_family_1.png");
	TextureManager::Load("wrencaptions_drawing_family_2", L"Assets/Textures/MeetTweet/wrencaptions_drawing_family_2.png");
	TextureManager::Load("wrencaptions_drawing_family_3", L"Assets/Textures/MeetTweet/wrencaptions_drawing_family_3.png");
	TextureManager::Load("wrencaptions_drawing_family_final_1", L"Assets/Textures/MeetTweet/wrencaptions_drawing_family_final_1.png");
	TextureManager::Load("wrencaptions_drawing_family_final_2", L"Assets/Textures/MeetTweet/wrencaptions_drawing_family_final_2.png");

	TextureManager::Load("wrencaptions_drawing_exercise_1", L"Assets/Textures/MeetTweet/wrencaptions_drawing_exercise_1.png");
	TextureManager::Load("wrencaptions_drawing_exercise_2", L"Assets/Textures/MeetTweet/wrencaptions_drawing_exercise_2.png");
	TextureManager::Load("wrencaptions_drawing_exercise_3", L"Assets/Textures/MeetTweet/wrencaptions_drawing_exercise_3.png");
	TextureManager::Load("wrencaptions_drawing_exercise_final_1", L"Assets/Textures/MeetTweet/wrencaptions_drawing_exercise_final_1.png");
	TextureManager::Load("wrencaptions_drawing_exercise_final_2", L"Assets/Textures/MeetTweet/wrencaptions_drawing_exercise_final_2.png");

	TextureManager::Load("wrencaptions_drawing_food_1", L"Assets/Textures/MeetTweet/wrencaptions_drawing_food_1.png");
	TextureManager::Load("wrencaptions_drawing_food_2", L"Assets/Textures/MeetTweet/wrencaptions_drawing_food_2.png");
	TextureManager::Load("wrencaptions_drawing_food_3", L"Assets/Textures/MeetTweet/wrencaptions_drawing_food_3.png");
	TextureManager::Load("wrencaptions_drawing_food_final_1", L"Assets/Textures/MeetTweet/wrencaptions_drawing_food_final_1.png");
	TextureManager::Load("wrencaptions_drawing_food_final_2", L"Assets/Textures/MeetTweet/wrencaptions_drawing_food_final_2.png");

	TextureManager::Load("wrencaptions_drawing_singing_1", L"Assets/Textures/MeetTweet/wrencaptions_drawing_singing_1.png");
	TextureManager::Load("wrencaptions_drawing_singing_2", L"Assets/Textures/MeetTweet/wrencaptions_drawing_singing_2.png");
	TextureManager::Load("wrencaptions_drawing_singing_3", L"Assets/Textures/MeetTweet/wrencaptions_drawing_singing_3.png");
	TextureManager::Load("wrencaptions_drawing_singing_final", L"Assets/Textures/MeetTweet/wrencaptions_drawing_singing_final.png");

	TextureManager::Load("wrencaptions_drawing_talking_1", L"Assets/Textures/MeetTweet/wrencaptions_drawing_talking_1.png");
	TextureManager::Load("wrencaptions_drawing_talking_2", L"Assets/Textures/MeetTweet/wrencaptions_drawing_talking_2.png");
	TextureManager::Load("wrencaptions_drawing_talking_3", L"Assets/Textures/MeetTweet/wrencaptions_drawing_talking_3.png");
	TextureManager::Load("wrencaptions_drawing_talking_final", L"Assets/Textures/MeetTweet/wrencaptions_drawing_talking_final.png");

	//确认框
	TextureManager::Load("tutorial_textbox", L"Assets/Textures/MeetTweet/tutorial_textbox.png");


	//结算环节
	//背景音乐
	CAudioManager::Get().PushLoopAudio("SFX_MT_Ambience", "Assets/Audios/MeetTweet/SFX_MT_Ambience.wav");

	CAudioManager::Get().PushOnceAudio("SFX_HT_NailHammerHit", "Assets/Audios/FristRound/SFX_HT_NailHammerHit.wav");

	CAudioManager::Get().PushOnceAudio("AMAZING", "Assets/Audios/MeetTweet/AMAZING.wav");
	CAudioManager::Get().PushOnceAudio("COOL", "Assets/Audios/MeetTweet/COOL.wav");
	CAudioManager::Get().PushOnceAudio("TRY AGAIN", "Assets/Audios/MeetTweet/TRY AGAIN.wav");
	//黑白大图
	TextureManager::Load("results_art_meetandtweet_amazing", L"Assets/Textures/MeetTweet/results_art_meetandtweet_amazing.png");
	TextureManager::Load("results_art_meetandtweet_cool", L"Assets/Textures/MeetTweet/results_art_meetandtweet_cool.png");
	TextureManager::Load("results_art_meetandtweet_tryagain", L"Assets/Textures/MeetTweet/results_art_meetandtweet_tryagain.png");
	//结算效果图
	TextureManager::Load("perfectdiamond_sticker", L"Assets/Textures/MeetTweet/perfectdiamond_sticker.png");
	TextureManager::Load("cool_sticker", L"Assets/Textures/MeetTweet/cool_sticker.png");
	TextureManager::Load("tryagain_sticker", L"Assets/Textures/MeetTweet/tryagain_sticker.png");

	m_StateMachine = new StateMachine;
	//状态
	m_OpeningState = new TweetOpening(this);
	m_ConfirmingState = new TweetConfirming(this);
	m_TeachingOneState = new TweetTeachingOne(this);
	m_TeachingTwoState = new TweetTeachingTwo(this);
	m_GamingState = new TweetGaming(this);
	m_SettlementingState = new TweetSettlementing(this);
	//加入状态管理
	m_StateMachine->AddState(STATE_TWEET_OPEN, m_OpeningState);
	m_StateMachine->AddState(STATE_TWEET_CONFIRM, m_ConfirmingState);
	m_StateMachine->AddState(STATE_TWEET_TEACH1, m_TeachingOneState);
	m_StateMachine->AddState(STATE_TWEET_TEACH2, m_TeachingTwoState);
	m_StateMachine->AddState(STATE_TWEET_GAME, m_GamingState);
	m_StateMachine->AddState(STATE_TWEET_SETTLEMENT, m_SettlementingState);
	//设置初始状态
	m_StateMachine->Switch(STATE_TWEET_OPEN);

	g_gameModeMeetTweet = new GameModeMeetTweet;

	//教学环节音效
	CAudioManager::Get().PushOnceAudio("Bits And Bops TUTORIAL 110", "Assets/Audios/MeetTweet/Bits And Bops TUTORIAL 110.wav");
	//正式音乐
	CAudioManager::Get().PushOnceAudio("Meet and Tweet (BITS AND BOPS) 220", "Assets/Audios/MeetTweet/Meet and Tweet (BITS AND BOPS) 220.wav");
	//提示音
	CAudioManager::Get().PushOnceAudio("tweet", "Assets/Audios/MeetTweet/tweet.wav");
	//回答音
	CAudioManager::Get().PushOnceAudio("tweet2", "Assets/Audios/MeetTweet/tweet2.wav");
	CAudioManager::Get().PushOnceAudio("SFX_MT_CanaryTweetBad", "Assets/Audios/MeetTweet/SFX_MT_CanaryTweetBad.wav");
	CAudioManager::Get().PushOnceAudio("SFX_MT_CanaryTweetAlmost", "Assets/Audios/MeetTweet/SFX_MT_CanaryTweetAlmost.wav");

	//对话框确认
	CAudioManager::Get().PushOnceAudio("CatTurn", "Assets/Audios/MeetTweet/SFX_FS_CatTurn.wav");
	//窗帘移动
	CAudioManager::Get().PushOnceAudio("SFX_MT_Blinds", "Assets/Audios/MeetTweet/SFX_MT_Blinds.wav");


	m_GameMode = CTitleScene::GetGameMode();
	m_Camera.SetOrtho(0, 0, 960, 540);
}

void MeetTweetScene::Update(float dt)
{
	m_Camera.SetScale(m_CameraScale);
	m_Camera.SetRotation(m_CameraRotation);
	m_Camera.SetOrtho(m_CameraPosition.x, m_CameraPosition.y, 960, 540);

	Renderer::SetViewProjection(m_Camera.GetViewProjMatrix());

	m_StateMachine->Update(dt);
}

void MeetTweetScene::End()
{
	delete m_StateMachine;
	delete m_OpeningState;
	delete m_ConfirmingState;
	delete m_TeachingOneState;
	delete m_TeachingTwoState;
	delete m_GamingState;
	delete m_SettlementingState;
	delete g_gameModeMeetTweet;
}
