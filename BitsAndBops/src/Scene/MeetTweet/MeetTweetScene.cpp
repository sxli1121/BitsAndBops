#include "MeetTweetScene.h"
#include "Audio/AudioManager.h"
#include "Renderer/TextureManager.h"
#include "Renderer/Renderer.h"
#include "Scene/HammerScene/States/HammerGaming.h"
#include "Scene/HammerScene/States/HammerSettlementing.h"
#include "Scene/MeetTweet/States/TweetOpening.h"
#include "Scene/MeetTweet/States/TweetConfirming.h"
#include "Scene/MeetTweet/States/TweetTeachingOne.h"
#include "Scene/MeetTweet/States/TweetTeachingTwo.h"
#include "Scene/MeetTweet/States/TweetGaming.h"
#include "Scene/MeetTweet/States/TweetSettlementing.h"

#include "OutPutAndInput/Camera.h"


void MeetTweetScene::Init()
{
	//����
	CAudioManager::Get().PushOnceAudio("JingleDraft", "Assets/Audios/MeetTweet/JingleDraft.wav");
	TextureManager::Load("meet_and_tweet_title_screen", L"Assets/Textures/MeetTweet/meet_and_tweet_title_screen.png");
	//����
	TextureManager::Load("bg_inside", L"Assets/Textures/MeetTweet/bg_inside.png");
	TextureManager::Load("bg_inside_dark", L"Assets/Textures/MeetTweet/bg_inside_dark.png");
	//��������������������
	TextureManager::Load("radio", L"Assets/Textures/MeetTweet/radio.png");
	TextureManager::Load("radio_noise_1", L"Assets/Textures/MeetTweet/radio_noise_1.png");
	TextureManager::Load("radio_noise_2", L"Assets/Textures/MeetTweet/radio_noise_2.png");
	TextureManager::Load("radio_noise_3", L"Assets/Textures/MeetTweet/radio_noise_3.png");
	//Tweet��Ļ��С��
	TextureManager::Load("subtitles_1", L"Assets/Textures/MeetTweet/subtitles_1.png");
	TextureManager::Load("subtitles_2", L"Assets/Textures/MeetTweet/subtitles_2.png");
	TextureManager::Load("bop", L"Assets/Textures/MeetTweet/bop.png");

	//��˿ȸ
	//����
	TextureManager::Load("canary_perch", L"Assets/Textures/MeetTweet/canary_perch.png");
	//����״̬
	TextureManager::Load("canary_bop_1", L"Assets/Textures/MeetTweet/canary_bop_1.png");
	TextureManager::Load("canary_bop_2", L"Assets/Textures/MeetTweet/canary_bop_2.png");
	//perfect
	TextureManager::Load("canary_tweet_1", L"Assets/Textures/MeetTweet/canary_tweet_1.png");
	//almost
	TextureManager::Load("canary_almost", L"Assets/Textures/MeetTweet/canary_almost.png");
	//�в��
	TextureManager::Load("canary_screech_2", L"Assets/Textures/MeetTweet/canary_screech_2.png");
	//���ܴ�
	TextureManager::Load("canary_screech_1", L"Assets/Textures/MeetTweet/canary_screech_1.png");
	//��������
	TextureManager::Load("canary_tweet_2", L"Assets/Textures/MeetTweet/canary_tweet_2.png");
	TextureManager::Load("canary_tweet_3", L"Assets/Textures/MeetTweet/canary_tweet_3.png");
	//�Ի������
	//�Ի���
	TextureManager::Load("canarycaptions_bubble_in_1", L"Assets/Textures/MeetTweet/canarycaptions_bubble_in_1.png");
	TextureManager::Load("canarycaptions_bubble_in_2", L"Assets/Textures/MeetTweet/canarycaptions_bubble_in_2.png");
	TextureManager::Load("canarycaptions_bubble_in_3", L"Assets/Textures/MeetTweet/canarycaptions_bubble_in_3.png");
	TextureManager::Load("canarycaptions_bubble_1", L"Assets/Textures/MeetTweet/canarycaptions_bubble_1.png");
	TextureManager::Load("canarycaptions_bubble_2", L"Assets/Textures/MeetTweet/canarycaptions_bubble_2.png");
	TextureManager::Load("canarycaptions_bubble_3", L"Assets/Textures/MeetTweet/canarycaptions_bubble_3.png");
	TextureManager::Load("canarycaptions_bubble_out", L"Assets/Textures/MeetTweet/canarycaptions_bubble_out.png");
	//��˿ȸ�Ĺ���
	//��̾��
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

	//����
	//happy most
	TextureManager::Load("canary_happy_1", L"Assets/Textures/MeetTweet/canary_happy_1.png");
	//happy near
	TextureManager::Load("canary_happy_4", L"Assets/Textures/MeetTweet/canary_happy_4.png");
	//������
	TextureManager::Load("canary_neutral", L"Assets/Textures/MeetTweet/canary_neutral.png");
	

	//С��
	//����״̬
	TextureManager::Load("wren_bop_1", L"Assets/Textures/MeetTweet/wren_bop_1.png");
	TextureManager::Load("wren_bop_2", L"Assets/Textures/MeetTweet/wren_bop_2.png");
	//��������
	TextureManager::Load("wren_tweet_1", L"Assets/Textures/MeetTweet/wren_tweet_1.png");
	//����
	TextureManager::Load("wren_tweet_2", L"Assets/Textures/MeetTweet/wren_tweet_2.png");
	TextureManager::Load("wren_tweet_3", L"Assets/Textures/MeetTweet/wren_tweet_3.png");
	//Ц
	TextureManager::Load("wren_giggle_1", L"Assets/Textures/MeetTweet/wren_giggle_1.png");
	TextureManager::Load("wren_giggle_2", L"Assets/Textures/MeetTweet/wren_giggle_2.png");
	TextureManager::Load("wren_giggle_3", L"Assets/Textures/MeetTweet/wren_giggle_3.png");
	//perfect and almost
	TextureManager::Load("wren_happy_1", L"Assets/Textures/MeetTweet/wren_happy_1.png");
	TextureManager::Load("wren_happy_2", L"Assets/Textures/MeetTweet/wren_happy_2.png");
	TextureManager::Load("wren_happy_3", L"Assets/Textures/MeetTweet/wren_happy_3.png");
	//�в��
	TextureManager::Load("wren_confused_1", L"Assets/Textures/MeetTweet/wren_confused_1.png");
	TextureManager::Load("wren_confused_2", L"Assets/Textures/MeetTweet/wren_confused_2.png");
	TextureManager::Load("wren_confused_3", L"Assets/Textures/MeetTweet/wren_confused_3.png");
	TextureManager::Load("wren_confused_4", L"Assets/Textures/MeetTweet/wren_confused_4.png");
	//���ܴ�-miss
	TextureManager::Load("wren_angry_1", L"Assets/Textures/MeetTweet/wren_angry_1.png");
	TextureManager::Load("wren_angry_2", L"Assets/Textures/MeetTweet/wren_angry_2.png");
	TextureManager::Load("wren_angry_3", L"Assets/Textures/MeetTweet/wren_angry_3.png");
	//�Ի���
	TextureManager::Load("wrencaptions_bubble_in_1", L"Assets/Textures/MeetTweet/wrencaptions_bubble_in_1.png");
	TextureManager::Load("wrencaptions_bubble_in_2", L"Assets/Textures/MeetTweet/wrencaptions_bubble_in_2.png");
	TextureManager::Load("wrencaptions_bubble_in_3", L"Assets/Textures/MeetTweet/wrencaptions_bubble_in_3.png");
	TextureManager::Load("wrencaptions_bubble_1", L"Assets/Textures/MeetTweet/wrencaptions_bubble_1.png");
	TextureManager::Load("wrencaptions_bubble_2", L"Assets/Textures/MeetTweet/wrencaptions_bubble_2.png");
	TextureManager::Load("wrencaptions_bubble_3", L"Assets/Textures/MeetTweet/wrencaptions_bubble_3.png");
	TextureManager::Load("wrencaptions_bubble_out", L"Assets/Textures/MeetTweet/wrencaptions_bubble_out.png");
	//С���Ĺ���
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

	

	//���㻷��
	//��������
	CAudioManager::Get().PushLoopAudio("SFX_MT_Ambience", "Assets/Audios/MeetTweet/SFX_MT_Ambience.wav");

	CAudioManager::Get().PushOnceAudio("SFX_HT_NailHammerHit", "Assets/Audios/FristRound/SFX_HT_NailHammerHit.wav");

	CAudioManager::Get().PushOnceAudio("AMAZING", "Assets/Audios/MeetTweet/AMAZING.wav");
	CAudioManager::Get().PushOnceAudio("COOL", "Assets/Audios/MeetTweet/COOL.wav");
	CAudioManager::Get().PushOnceAudio("TRY AGAIN", "Assets/Audios/MeetTweet/TRY AGAIN.wav");
	//�ڰ״�ͼ
	TextureManager::Load("results_art_meetandtweet_amazing", L"Assets/Textures/MeetTweet/results_art_meetandtweet_amazing.png");
	TextureManager::Load("results_art_meetandtweet_cool", L"Assets/Textures/MeetTweet/results_art_meetandtweet_cool.png");
	TextureManager::Load("results_art_meetandtweet_tryagain", L"Assets/Textures/MeetTweet/results_art_meetandtweet_tryagain.png");
	//����Ч��ͼ
	TextureManager::Load("perfectdiamond_sticker", L"Assets/Textures/MeetTweet/perfectdiamond_sticker.png");
	TextureManager::Load("cool_sticker", L"Assets/Textures/MeetTweet/cool_sticker.png");
	TextureManager::Load("tryagain_sticker", L"Assets/Textures/MeetTweet/tryagain_sticker.png");

	m_StateMachine = new StateMachine;
	//״̬
	m_OpeningState = new TweetOpening(this);
	m_ConfirmingState = new TweetConfirming(this);
	m_TeachingOneState = new TweetTeachingOne(this);
	m_TeachingTwoState = new TweetTeachingTwo(this);
	m_GamingState = new TweetGaming(this);
	m_SettlementingState = new TweetSettlementing(this);
	//����״̬����
	m_StateMachine->AddState(STATE_TWEET_OPEN, m_OpeningState);
	m_StateMachine->AddState(STATE_TWEET_CONFIRM, m_ConfirmingState);
	m_StateMachine->AddState(STATE_TWEET_TEACH1,m_TeachingOneState);
	m_StateMachine->AddState(STATE_TWEET_TEACH2,m_TeachingTwoState);
	m_StateMachine->AddState(STATE_TWEET_SETTLEMENT,m_SettlementingState);
	//���ó�ʼ״̬
	m_StateMachine->Switch(STATE_TWEET_OPEN);


}

void MeetTweetScene::Update(float dt)
{
	m_Camera->SetAngle(50);
	//Matrix  m = ;
	Renderer::DrawTexture("wren_bop_2", 100, 100, 556 * 0.5, 415 * 0.5);
	
	
	
	//m_StateMachine->Update(dt);
}

void MeetTweetScene::End()
{

}
