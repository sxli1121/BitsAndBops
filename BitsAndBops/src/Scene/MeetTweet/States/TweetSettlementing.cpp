#include "TweetSettlementing.h"
#include  "Audio/AudioManager.h"
#include "Scene/MeetTweet/MeetTweetScene.h"
#include "Renderer/Renderer.h"
void TweetSettlementing::OnEnter()
{
	m_timer.Begin();

	float grades = m_Scene->g_gameModeMeetTweet->GetGrades();
	//grades = 0.5;

	if (grades > 0.9)
	{
		m_Grades = TweetGradesResule::GRADES_PERFECT;
	}
	else if (grades > 0.75)
	{
		m_Grades = TweetGradesResule::GRADES_COOL;
	}
	else
	{
		m_Grades = TweetGradesResule::GRADES_TRYAGAIN;
	}
	CAudioManager::Get().PlayLoopAudio("SFX_MT_Ambience");
}

void TweetSettlementing::OnUpdate(float dt)
{
	//结果图 文字 音效与效果图
	double currentTime = m_timer.GetTimerMilliSec();

	Renderer(currentTime);
	PlayAudio(currentTime);


	if (m_Grades == TweetGradesResule::GRADES_PERFECT)
	{
		if (m_IsAudioPlay == false && currentTime >= 1000)
		{
			CAudioManager::Get().PlayOnceAudio("AMAZING");
			m_IsAudioPlay = true;
		}

	}
	else if (m_Grades == TweetGradesResule::GRADES_COOL)
	{
		if (m_IsAudioPlay == false && currentTime >= 3000)
		{
			CAudioManager::Get().PlayOnceAudio("COOL");
			m_IsAudioPlay = true;
		}
	}
	else
	{
		if (m_IsAudioPlay == false && currentTime >= 3000)
		{
			CAudioManager::Get().PlayOnceAudio("TRY AGAIN");
			m_IsAudioPlay = true;
		}
	}

}

void TweetSettlementing::OnExit()
{
	CAudioManager::Get().StopLoopAudio("SFX_MT_Ambience");
}

void TweetSettlementing::Renderer(double currentTime)
{
	if (m_Grades == TweetGradesResule::GRADES_PERFECT)
	{
		Renderer::DrawTexture("results_art_meetandtweet_amazing", 300, 30, 326.5f, 226.5f);
		if (currentTime >= 1000)
		{
			Renderer::DrawTex(u8"You made a friend for life!", 350, 270, 400, 100);
		}
		if (currentTime >= 2000)
		{
			Renderer::DrawTexture("perfectdiamond_sticker", 320, 350, 293, 158.5f);
		}

	}
	else if (m_Grades == TweetGradesResule::GRADES_COOL)
	{
		Renderer::DrawTexture("results_art_meetandtweet_cool", 300, 30, 326.5f, 226.5f);
		if (currentTime >= 1000)
		{
			Renderer::DrawTex("That's enough chit-chat for one day.", 330, 270, 400, 100);
		}
		if (currentTime >= 2000)
		{
			Renderer::DrawTexture("cool_sticker", 340, 350, 241.5f, 152);
		}

	}
	else
	{
		Renderer::DrawTexture("results_art_meetandtweet_tryagain", 300, 30, 326.5f, 226.5f);
		if (currentTime >= 1000)
		{
			Renderer::DrawTex("Try letting someone else speak occasionally.", 325, 270, 400, 100);
		}
		if (currentTime >= 2000)
		{
			Renderer::DrawTexture("tryagain_sticker", 340, 350, 214, 172);
		}
	}
}

void TweetSettlementing::PlayAudio(double currentTime)
{
	if (m_IsTextAudioPlay == false && currentTime >= 1000)
	{
		CAudioManager::Get().PlayOnceAudio("SFX_HT_NailHammerHit");
		m_IsTextAudioPlay = true;
	}

	if (m_Grades == TweetGradesResule::GRADES_PERFECT)
	{

		if (m_IsAudioPlay == false && currentTime >= 2000)
		{
			CAudioManager::Get().PlayOnceAudio("AMAZING");
			m_IsAudioPlay = true;
		}

	}
	else if (m_Grades == TweetGradesResule::GRADES_COOL)
	{
		if (m_IsAudioPlay == false && currentTime >= 2000)
		{
			CAudioManager::Get().PlayOnceAudio("COOL");
			m_IsAudioPlay = true;
		}
	}
	else
	{
		if (m_IsAudioPlay == false && currentTime >= 2000)
		{
			CAudioManager::Get().PlayOnceAudio("TRY AGAIN");
			m_IsAudioPlay = true;
		}

	}
}
