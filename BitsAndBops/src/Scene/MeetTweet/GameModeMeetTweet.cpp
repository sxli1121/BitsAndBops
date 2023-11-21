#include "GameModeMeetTweet.h"
#include "Core/Time.h"
#include "Audio/AudioManager.h"
#include "Renderer/Renderer.h"
#include "OutPutAndInput/GameInput.h"

TweetLevel::~TweetLevel()
{
	Blocks.clear();
	BeatsPerMeasure.clear();
}

GameModeMeetTweet::~GameModeMeetTweet()
{

}

void GameModeMeetTweet::Init()
{
	m_NextBlockIndex = 0;
	m_HalfBeatIndex = 0;
	m_NextBeatIndex = 0;
	m_BeatPerMeasureIndex = 0;
	m_CaptionIndex = 0;
	m_WernStoryIndex = 0;
	m_CanaryStoryIndex = 0;
	m_AnswerStoryStste = Normal;


	m_LevelFinished = false;
	m_Scor = 0;
	m_StartTime = 0;

	m_IsOneSubtitle = false;
	m_IsTwoSubtitle = false;

	m_AnswerBeats.clear();

	float CanaryPositionX = 625;
	float CanaryPositionY = 345;

	//金丝雀正常Bop
	m_CanaryBopAnimation.Reset();
	m_CanaryBopAnimation.SetMode(AnimationMode::Loop);
	m_CanaryBopAnimation.AddFrame({
		0,"canary_bop_1",CanaryPositionX,CanaryPositionY,294.5f,275,0,0.205f,0.925f });
	m_CanaryBopAnimation.AddFrame({
		0.26666f,"canary_bop_2",CanaryPositionX,CanaryPositionY,293,275,0,0.203f,0.926f});
	m_CanaryBopAnimation.AddFrame({
		0.5333f,"canary_bop_2",CanaryPositionX,CanaryPositionY,293,275,0,0.203f,0.926f});


	float RandioSmeraX = 385;
	float RandioSmeraY = 185;
	m_RadioAnimation.Reset();
	m_RadioAnimation.SetMode(AnimationMode::Once);
	m_RadioAnimation.AddFrame({
		0,"radio_noise_1",RandioSmeraX,RandioSmeraY,81,137,0,0,0
	});
	m_RadioAnimation.AddFrame({
		0.1f,"radio_noise_2",RandioSmeraX,RandioSmeraY,78,136.5f,0,0,0
		});
	m_RadioAnimation.AddFrame({
		0.2f,"radio_noise_3",RandioSmeraX,RandioSmeraY,79,134.5,0,0,0
		});
	m_RadioAnimation.AddFrame({
	0.3f,"radio_noise_3",RandioSmeraX,RandioSmeraY,79,134.5,0,0,0
		});


	Vector2 position = { 625,345 };
	m_CanaryPerfectAnimation.Reset();
	m_CanaryPerfectAnimation.SetMode(AnimationMode::Once);
	m_CanaryPerfectAnimation.AddFrame("canary_tweet_1", position, { 334,314.5f }, 0.0f, { 0.472f,0.934f }, 0.25f);
	m_CanaryPerfectAnimation.AddFrame("canary_tweet_2", position, { 304.5f,300.5f }, 0.0f, { 0.368f,0.932f }, 0.25f);
	m_CanaryPerfectAnimation.AddFrame("canary_tweet_3", position, { 315.5f,278 }, 0.0f, { 0.206f,0.928f }, 0.25f);

	m_CanaryAlmostAnimation.Reset();
	m_CanaryAlmostAnimation.SetMode(AnimationMode::Once);
	m_CanaryAlmostAnimation.AddFrame("canary_almost", position, { 334,314.5f }, 0.0f, { 0.466f,0.929f }, 0.25f);
	m_CanaryAlmostAnimation.AddFrame("canary_tweet_2", position, { 304.5f,300.5f }, 0.0f, { 0.368f,0.932f }, 0.25f);
	m_CanaryAlmostAnimation.AddFrame("canary_tweet_3", position, { 315.5f,278 }, 0.0f, { 0.206f,0.928f }, 0.25f);

	m_CanaryMissAnimation.Reset();
	m_CanaryMissAnimation.SetMode(AnimationMode::Once);
	m_CanaryMissAnimation.AddFrame("canary_screech_1", position, { 340,314.5f }, 0.0f, { 0.478f,0.932f }, 0.25f);
	m_CanaryMissAnimation.AddFrame("canary_tweet_2", position, { 304.5f,300.5f }, 0.0f, { 0.368f,0.932f }, 0.25f);
	m_CanaryMissAnimation.AddFrame("canary_tweet_3", position, { 315.5f,278 }, 0.0f, { 0.206f,0.928f }, 0.25f);

	//
	float WrenPositionX = 200;
	float WrenPositionY = 330;
	m_WrenBopAnimation.Reset();
	m_WrenBopAnimation.SetMode(AnimationMode::Loop);
	m_WrenBopAnimation.AddFrame({
   0,"wren_bop_1",WrenPositionX,WrenPositionY,275,210,0,0.582f,0.969f
		});
	m_WrenBopAnimation.AddFrame({
	   0.26666f,"wren_bop_2",WrenPositionX,WrenPositionY,278,207.5f,0,0.586f,0.966f
		});
	m_WrenBopAnimation.AddFrame({
	   0.5333f,"wren_bop_2",WrenPositionX,WrenPositionY,278,207.5f,0,0.586f,0.966f
		});


	m_WrenGiggleAnimation.Reset();
	m_WrenGiggleAnimation.SetMode(AnimationMode::Once);
	m_WrenGiggleAnimation.AddFrame({
   0,"wren_giggle_1",WrenPositionX,WrenPositionY,275,210,0,0.604f,0.964f
		});
	m_WrenGiggleAnimation.AddFrame({
	   0.2666f,"wren_giggle_2",WrenPositionX,WrenPositionY,284,204,0,0.593f,0.966f
		});
	m_WrenGiggleAnimation.AddFrame({
   0.4f, "wren_giggle_3",WrenPositionX,WrenPositionY,278,207.5f,0,0.584f,0.966
		});
	m_WrenGiggleAnimation.AddFrame({
   0.5f, "wren_giggle_3",WrenPositionX,WrenPositionY,278,207.5f,0,0.584f,0.966
		});


	m_WrenHappyAnimation.Reset();
	m_WrenHappyAnimation.SetMode(AnimationMode::Once);
	m_WrenHappyAnimation.AddFrame({
   0,
   "wren_happy_1",WrenPositionX,WrenPositionY,276,213,0,0.583f,0.967f
		});
	m_WrenHappyAnimation.AddFrame({
	   0.25f, "wren_happy_2",WrenPositionX,WrenPositionY,278.5f,209.5f,0,0.589f,0.969f
		});
	m_WrenHappyAnimation.AddFrame({
   0.4f,"wren_happy_3",WrenPositionX,WrenPositionY,281,205,0,0.59f,0.966f
	});
	m_WrenHappyAnimation.AddFrame({
   0.5f, "wren_happy_3",WrenPositionX,WrenPositionY,281,205,0,0.59f,0.966f
		});


	m_WrenConfuseAnimation.Reset();
	m_WrenConfuseAnimation.SetMode(AnimationMode::Once);
	m_WrenConfuseAnimation.AddFrame({
   0, "wren_confused_1",WrenPositionX,WrenPositionY,276.5f,213,0,0.58f,0.969f
		});
	m_WrenConfuseAnimation.AddFrame({
	   0.25f,"wren_confused_2",WrenPositionX,WrenPositionY,287,203.5f,0,0.594f,0.968f
		});
	m_WrenConfuseAnimation.AddFrame({
   0.35f,"wren_confused_3",WrenPositionX,WrenPositionY,282.5f,205,0,0.586f,0.968f
		});
	m_WrenConfuseAnimation.AddFrame({
   0.4f,"wren_confused_4",WrenPositionX,WrenPositionY,281,205,0,0.591f,0.968f
		});
	m_WrenConfuseAnimation.AddFrame({
	   0.5f,"wren_confused_4",WrenPositionX,WrenPositionY,281,205,0,0.591f,0.968f
		});


	m_WrenAngerAnimation.Reset();
	m_WrenAngerAnimation.SetMode(AnimationMode::Once);
	m_WrenAngerAnimation.AddFrame({
   0,"wren_angry_1",WrenPositionX,WrenPositionY,269,216,0,0.572f,0.967f
		});
	m_WrenAngerAnimation.AddFrame({
	   0.25f,"wren_angry_2",WrenPositionX,WrenPositionY,276.5f,213,0,0.580f,0.967f
		});
	m_WrenAngerAnimation.AddFrame({
	0.4f,"wren_angry_3",WrenPositionX,WrenPositionY,278.5f,209.5f,0,0.585f,0.969f
		});
	m_WrenAngerAnimation.AddFrame({
   0.5f, "wren_angry_3",WrenPositionX,WrenPositionY,278.5f,209.5f,0,0.585f,0.969f
		});

	position = { 200,330 };
	m_WrenPromoteAnimation.Reset();
	m_WrenPromoteAnimation.SetMode(AnimationMode::Once);
	m_WrenPromoteAnimation.AddFrame("wren_tweet_1", position, { 287,244.5f }, 0.0f, { 0.462f,0.973f }, 0.25f);
	m_WrenPromoteAnimation.AddFrame("wren_tweet_2", position, { 258,242 }, 0.0f, { 0.538f,0.973f }, 0.25f);
	//m_WrenPromoteAnimation.AddFrame("wren_tweet_3", position, { 230,268 }, 0.0f, { 0.562f,0.972f }, 0.25f);

	float wenBubbleX = 250;
	float wenBubbleY = 0;
	m_BubbleAnimation.Reset();
	m_BubbleAnimation.SetMode(AnimationMode::Loop);
	m_BubbleAnimation.AddFrame({
   0,"wrencaptions_bubble_1",wenBubbleX,wenBubbleY,435,290.5f,0,0.5,0.5,
		});
	m_BubbleAnimation.AddFrame({
	   0.25f,"wrencaptions_bubble_2",wenBubbleX,wenBubbleY,436.5f,292,0,0.5,0.5,
		});
	m_BubbleAnimation.AddFrame({
   0.4f,"wrencaptions_bubble_3",wenBubbleX,wenBubbleY,439.5f,293.5f,0,0.5,0.5,
		});
	m_BubbleAnimation.AddFrame({
   0.5f,"wrencaptions_bubble_3",wenBubbleX,wenBubbleY,439.5f,293,0,0.5,0.5,
		});

	m_BubbleInAnimation.Reset();
	m_BubbleInAnimation.SetMode(AnimationMode::Once);
	m_BubbleInAnimation.AddFrame({
   0,"wrencaptions_bubble_in_1",wenBubbleX,wenBubbleY,227.5f,163.5f,0,0.5f,0.5f
		});
	m_BubbleInAnimation.AddFrame({
	   0.25f,"wrencaptions_bubble_in_2",wenBubbleX,wenBubbleY,447,302,0,0.5f,0.5f
		});
	m_BubbleInAnimation.AddFrame({
   0.4f,"wrencaptions_bubble_in_3",wenBubbleX,wenBubbleY,442,297,0,0.5f,0.5f
		});
	m_BubbleInAnimation.AddFrame({
   0.5f,"wrencaptions_bubble_in_3",wenBubbleX,wenBubbleY,442,297,0,0.5f,0.5f
		});

	m_BubbleOutAnimation.Reset();
	m_BubbleOutAnimation.SetMode(AnimationMode::Once);
	m_BubbleOutAnimation.AddFrame({
   0,"wrencaptions_bubble_out",wenBubbleX,wenBubbleY,455,297.5f,0,0.5f,0.5f
		});
	m_BubbleOutAnimation.AddFrame({
	   0.25f,"wrencaptions_bubble_out",wenBubbleX,wenBubbleY,455,297.5f,0,0.5f,0.5f
		});

	float CanaryBubbleX = 700;
	float  CanaryBubbleY = 0;
	m_CanaryBubbleAnimation.Reset();
	m_CanaryBubbleAnimation.SetMode(AnimationMode::Loop);
	m_CanaryBubbleAnimation.AddFrame({
0,"canarycaptions_bubble_1",CanaryBubbleX,CanaryBubbleY,445.5f,294.5f,0,0.5f,0.5f
		});
	m_CanaryBubbleAnimation.AddFrame({
	   0.25f,"canarycaptions_bubble_2",CanaryBubbleX,CanaryBubbleY,444.5f,295.5f,0,0.5f,0.5f
		});
	m_CanaryBubbleAnimation.AddFrame({
   0.4f,"canarycaptions_bubble_3",CanaryBubbleX,CanaryBubbleY,446,295.5f,0,0.5f,0.5f
		});
	m_CanaryBubbleAnimation.AddFrame({
   0.5f,"canarycaptions_bubble_3",CanaryBubbleX,CanaryBubbleY,446,295.5f,0,0.5f,0.5f
		});


	m_CanaryBubbleInAnimation.Reset();
	m_CanaryBubbleInAnimation.SetMode(AnimationMode::Once);
	m_CanaryBubbleInAnimation.AddFrame({
0,"canarycaptions_bubble_in_1",CanaryBubbleX,CanaryBubbleY,226,166,0,0.5f,0.5f
		});
	m_CanaryBubbleInAnimation.AddFrame({
	   0.25f,"canarycaptions_bubble_in_2",CanaryBubbleX,CanaryBubbleY,457.5f,311,0,0.5f,0.5f
		});
	m_CanaryBubbleInAnimation.AddFrame({
   0.4f,"canarycaptions_bubble_in_3",CanaryBubbleX,CanaryBubbleY,451,303.5f,0,0.5f,0.5f
		});
	m_CanaryBubbleInAnimation.AddFrame({
   0.5f,"canarycaptions_bubble_in_3",CanaryBubbleX,CanaryBubbleY,451,303.5f,0,0.5f,0.5f
		});


	m_CanaryBubbleOutAnimation.Reset();
	m_CanaryBubbleOutAnimation.SetMode(AnimationMode::Once);
	m_CanaryBubbleOutAnimation.AddFrame({
0,"canarycaptions_bubble_out",CanaryBubbleX,CanaryBubbleY,227.5f,163.5f,0,0.5f,0.5f
		});
	m_CanaryBubbleOutAnimation.AddFrame({
	   0.25f,"canarycaptions_bubble_out",CanaryBubbleX,CanaryBubbleY,447,302,0,0.5f,0.5f
		});


	m_CanaryBubbleErrorAnimation.Reset();
	m_CanaryBubbleErrorAnimation.SetMode(AnimationMode::Once);
	m_CanaryBubbleErrorAnimation.AddFrame({
   0,"canarycaptions_screech",CanaryBubbleX,CanaryBubbleY,318,265.5f,0,0.5f,0.5f
		});
	m_CanaryBubbleErrorAnimation.AddFrame({
	   0.25f,"canarycaptions_screech",CanaryBubbleX,CanaryBubbleY,318,265.5f,0,0.5f,0.5f
		});


	float ti = 60.0f/ 110.0f;
	m_Bop1Animation.Reset();
	m_Bop1Animation.SetMode(AnimationMode::Once);
	m_Bop1Animation.AddFrame({ 0,"bop",220, 370, 97.5f, 69.5f,0,0,0 });
	m_Bop1Animation.AddFrame({ ti*0.5f,"bop",320, 300,  97.5f, 69.5f,0,0,0 });
	m_Bop1Animation.AddFrame({ ti,"bop",385, 370,  97.5f, 69.5f,0,0,0 });
	m_Bop1Animation.AddFrame({ ti * 1.5f,"bop",450, 320,  97.5f, 69.5f,0,0,0 });
	m_Bop1Animation.AddFrame({ ti*2,"bop",545, 370,  97.5f, 69.5f,0,0,0 });
	m_Bop1Animation.AddFrame({ ti * 2.15f,"bop",545, 370, 97.5f, 69.5f,0,0,0 });

	m_Bop2Animation.Reset();
	m_Bop2Animation.SetMode(AnimationMode::Once);
	m_Bop2Animation.AddFrame({ 0,"bop",165, 370, 97.5f, 69.5f,0,0,0 });
	m_Bop2Animation.AddFrame({ ti * 0.25f,"bop",245, 320,  97.5f, 69.5f,0,0,0 });
	m_Bop2Animation.AddFrame({ ti*0.5f,"bop",325, 370, 97.5f, 69.5f,0,0,0 });
	m_Bop2Animation.AddFrame({ ti * 0.75f,"bop",397.5f, 320,  97.5f, 69.5f,0,0,0 });
	m_Bop2Animation.AddFrame({ ti,"bop",470, 370,  97.5f, 69.5f,0,0,0 });
	m_Bop2Animation.AddFrame({ ti * 1.5f,"bop",525, 320,  97.5f, 69.5f,0,0,0 });
	m_Bop2Animation.AddFrame({ ti * 2,"bop",580, 370,  97.5f, 69.5f,0,0,0 });
	m_Bop2Animation.AddFrame({ ti * 2.5f,"bop",630, 320, 97.5f, 69.5f,0,0,0 });
	m_Bop2Animation.AddFrame({ ti*3,"bop",680, 370,  97.5f, 69.5f,0,0,0 });
	m_Bop2Animation.AddFrame({ ti * 3.15f,"bop",680, 370,  97.5f, 69.5f,0,0,0 });
}

void GameModeMeetTweet::Play(TweetLevel* lever)
{
	m_CurrentLevel = lever;
	m_StartTime = Time::GetRealtimeSinceStartup();

	//为answerBeats赋值
	int size = m_CurrentLevel->Blocks.size();
	int blockIndex = 0;
	int BeatPerMeasureIndex = 0;
	AnswerBeat answerBeat;
	for (int i = 0; i < size; i++)
	{
		answerBeat.Beat = m_CurrentLevel->Blocks[blockIndex] + m_CurrentLevel->BeatsPerMeasure[BeatPerMeasureIndex];
		answerBeat.State = KeystorkeAnswerState::Normal;
		blockIndex++;
		BeatPerMeasureIndex++;
		m_AnswerBeats.push_back(answerBeat);
	}
	m_CanaryBopAnimation.Play();
	m_WrenBopAnimation.Play();

}

void GameModeMeetTweet::Update(float dt)
{
	GeneratePromptAudio();

	////按键判断
	CGameInput* input = CGameInput::GetGameInput();

	if (input->GetKeyState(_GI_K_SPACE) == _KS_DC)
	{
		for (AnswerBeat& answerBeat : m_AnswerBeats)
		{
			if (answerBeat.State == KeystorkeAnswerState::Normal)
			{
				float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
				float perfectTime = beatUnitTime * answerBeat.Beat;

				double hitTime = Time::GetRealtimeSinceStartup() - m_StartTime;
				float diff = hitTime - perfectTime;
				float diffBeat = diff * beatUnitTime;
				if (abs(diffBeat) <= HitJudgmentTimePerfect)
				{
					answerBeat.State = KeystorkeAnswerState::Perfect;
					CAudioManager::Get().PlayOnceAudio("tweet2");

					m_CanaryPerfectAnimation.Play();
					if (answerBeat.Beat == 46.0f || answerBeat.Beat == 78.0f || answerBeat.Beat == 109.0f)
						m_WrenGiggleAnimation.Play();                              
					else
						m_WrenHappyAnimation.Play();

					m_Scor += 2;

					//Story Generate
					CanaryStoryplay();
					m_AnswerStoryStste = Normal;
				}
				else if (abs(diffBeat) <= HitJudgmentTimeAlmost)
				{
					answerBeat.State = KeystorkeAnswerState::Almost;

					CAudioManager::Get().PlayOnceAudio("SFX_MT_CanaryTweetAlmost");

					m_CanaryAlmostAnimation.Play();
					m_WrenConfuseAnimation.Play();

					m_Scor += 1;


					CanaryStoryplay();

					m_AnswerStoryStste = Normal;

				}
				else
				{
					CAudioManager::Get().PlayOnceAudio("SFX_MT_CanaryTweetBad");

					m_CanaryMissAnimation.Play();
					m_WrenAngerAnimation.Play();

					double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;

					if (currentTime >= beatUnitTime * m_CurrentLevel->Blocks[4])
					{
						m_CanaryBubbleErrorAnimation.Play();
						m_AnswerStoryStste = Error;
					}               

				}
				break;
			}
		}
	}

	UpdateAnswerBeats(dt);


	m_CanaryPerfectAnimation.Update(dt);
	m_CanaryAlmostAnimation.Update(dt);
	m_CanaryMissAnimation.Update(dt);
	m_CanaryBopAnimation.Update(dt);
	m_RadioAnimation.Update(dt);

	m_WrenBopAnimation.Update(dt);
	m_WrenPromoteAnimation.Update(dt);
	m_WrenHappyAnimation.Update(dt);
	m_WrenConfuseAnimation.Update(dt);
	m_WrenAngerAnimation.Update(dt);
	m_WrenGiggleAnimation.Update(dt);

	m_Bop1Animation.Update(dt);
	m_Bop2Animation.Update(dt);
	
	m_BubbleInAnimation.Update(dt);
	m_BubbleAnimation.Update(dt);
	m_BubbleOutAnimation.Update(dt);

	m_CanaryBubbleAnimation.Update(dt);
	m_CanaryBubbleInAnimation.Update(dt);
	m_CanaryBubbleOutAnimation.Update(dt);
	m_CanaryBubbleErrorAnimation.Update(dt);

}

void GameModeMeetTweet::Render()
{
	if (m_CurrentLevel->levelName == TweetLevelName::TWEET_GAME)
	{
		GameRender();
	}
	else
	{
		//背景
		Renderer::DrawTexture("bg_outside",  0, -150, 960, 690);
		Renderer::DrawTexture("bg_inside", 0, -150, 960, 690);

		Renderer::DrawTexture("radio", 90, 56, 279.5f, 276);
		Renderer::DrawTexture("canary_perch", 550, 340, 174, 200.5f);
		//public
		if (m_RadioAnimation.IsPlaying())
		{
			m_RadioAnimation.Render();
		}

	}


	//Renderer public
	//Canary

	if (m_CanaryPerfectAnimation.IsPlaying())
	{
		m_CanaryPerfectAnimation.Render();
	}
	else if (m_CanaryAlmostAnimation.IsPlaying())
	{
		m_CanaryAlmostAnimation.Render();
	}
	else if (m_CanaryMissAnimation.IsPlaying())
	{
		m_CanaryMissAnimation.Render();
	}
	else if (m_CanaryBopAnimation.IsPlaying())
	{
		m_CanaryBopAnimation.Render();
	}


	//bop
	if (m_Bop1Animation.IsPlaying())
	{
		m_Bop1Animation.Render();
	}
	if (m_Bop2Animation.IsPlaying())
	{
		m_Bop2Animation.Render();
	}

	if (m_IsOneSubtitle)
	{
		Renderer::DrawTexture("subtitles_1", 190, 450, 480.5f, 46);

	}
	else if (m_IsTwoSubtitle)
	{

		Renderer::DrawTexture("subtitles_2", 140, 450, 666, 46);
	}

}

bool GameModeMeetTweet::IsDone()
{
	return false;
}

float GameModeMeetTweet::GetGrades()
{
	float numAnswerBeats = m_AnswerBeats.size();
	//m_scoror / 总成绩的比例
	float grades = m_Scor /( numAnswerBeats * 2);
	return grades;
}

void GameModeMeetTweet::GeneratePromptAudio()
{
	if (m_LevelFinished) return;

	float beatUnitTime = 60.0f / m_CurrentLevel->BPM;
	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;
	int size = m_CurrentLevel->Blocks.size();

	if(m_NextBlockIndex < m_CurrentLevel->Blocks.size())
	{
		float FirstBeatTime = beatUnitTime * m_CurrentLevel->Blocks[m_NextBlockIndex];
		if (currentTime >= FirstBeatTime)
		{
			//Story Generate
			if (currentTime >= beatUnitTime* m_CurrentLevel->Blocks[4])
			{
				m_WernStoryIndex += 1;

				if (m_WernStoryIndex == 1)
				{
					m_BubbleInAnimation.Play();
				}
				if (m_WernStoryIndex == 36)
				{
					m_BubbleOutAnimation.Play();
				}
				else
				{
					m_BubbleAnimation.Play();
				}
			}


			if (m_NextBlockIndex < size)
			{
				PromoptObject();

				m_NextBlockIndex++;
			}
			
			//===================================

			if( m_CurrentLevel->levelName == TweetLevelName::TWEET_GAME)
			{
				if (currentTime <= beatUnitTime * 29)
				{
					if (m_CurrentLevel->BeatsPerMeasure[m_BeatPerMeasureIndex] == 2)
					{
						m_Bop1Animation.Play();
						m_IsOneSubtitle = true;
					}
					else if (m_CurrentLevel->BeatsPerMeasure[m_BeatPerMeasureIndex] == 3)
					{
						m_Bop2Animation.Play();
						m_IsTwoSubtitle = true;
					}
				}
			}
			else
			{
				if (m_CurrentLevel->BeatsPerMeasure[m_BeatPerMeasureIndex] == 2)
				{
					m_Bop1Animation.Play();
					m_IsOneSubtitle = true;

				}
				else if (m_CurrentLevel->BeatsPerMeasure[m_BeatPerMeasureIndex] == 3)
				{
					m_Bop2Animation.Play();
					m_IsTwoSubtitle = true;
				}
			}
		}
	}

	
	if(m_HalfBeatIndex< m_CurrentLevel->Blocks.size())
	{
		float HalfBeatTime = beatUnitTime * m_CurrentLevel->Blocks[m_HalfBeatIndex] + (beatUnitTime * 0.5f);
		if (currentTime >= HalfBeatTime)
		{
			if (m_HalfBeatIndex < size && m_CurrentLevel->BeatsPerMeasure[m_BeatPerMeasureIndex] == 3)
			{
				PromoptObject();
			}
			m_HalfBeatIndex++;
			m_BeatPerMeasureIndex++;
		}
	}


	float NextBeatTime = beatUnitTime * m_CurrentLevel->Blocks[m_NextBeatIndex] + beatUnitTime;
	if (currentTime >= NextBeatTime)
	{
		if (m_BeatPerMeasureIndex < size)
		{
			PromoptObject();;

			m_NextBeatIndex += 1;
		}
	}

	if (m_NextBeatIndex == m_CurrentLevel->Blocks.size())
	{
		m_LevelFinished = true;
	}

}

void GameModeMeetTweet::UpdateAnswerBeats(float dt)
{
	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;

	for (AnswerBeat& answerBeat : m_AnswerBeats)
	{
		if (answerBeat.State == KeystorkeAnswerState::Normal)
		{
			float beatUnitTime = (60.0f / m_CurrentLevel->BPM);
			float missTime = beatUnitTime * (answerBeat.Beat + HitJudgmentTimeMiss);

			if (currentTime > missTime)
			{
				answerBeat.State = KeystorkeAnswerState::Miss;

				m_IsOneSubtitle = false;
				m_IsTwoSubtitle = false;
				
				if (currentTime >= beatUnitTime * m_CurrentLevel->Blocks[4])
				{
					m_CanaryStoryIndex += 1;
					m_AnswerStoryStste = Error;
				}
				
			}
		}
	}
}

void GameModeMeetTweet::PromoptObject()
{
	CAudioManager::Get().PlayOnceAudio("tweet");

	if (m_CurrentLevel->levelName == TweetLevelName::TWEET_GAME)
	{
		m_WrenPromoteAnimation.Play();
	}
	else
	{
		m_RadioAnimation.Play();
	}

}

void GameModeMeetTweet::GameRender()
{
	Renderer::DrawTexture("bg_outside", 0, -150, 960, 690);
	Renderer::DrawTexture("bg_inside_dark", 0, -150, 960, 690);
	Renderer::DrawTexture("canary_perch", 550, 340, 174, 200.5f);


	if (m_BubbleAnimation.IsPlaying())
	{
		m_BubbleAnimation.Render();
	}


	//Animation private
	//Wern
	if (m_WrenPromoteAnimation.IsPlaying())
	{
		m_WrenPromoteAnimation.Render();
	}
	else if (m_WrenHappyAnimation.IsPlaying())
	{
		m_WrenHappyAnimation.Render();
	}
	else if (m_WrenConfuseAnimation.IsPlaying())
	{
		m_WrenConfuseAnimation.Render();
	}
	else if (m_WrenAngerAnimation.IsPlaying())
	{
		m_WrenAngerAnimation.Render();
	}
	else if (m_WrenGiggleAnimation.IsPlaying())
	{
		m_WrenGiggleAnimation.Render();
	}
	else if (m_WrenBopAnimation.IsPlaying())
	{
		m_WrenBopAnimation.Render();
	}

	//==================================================
	//m_WernStoryIndex = 2;

	if (m_BubbleInAnimation.IsPlaying())
	{
		m_BubbleInAnimation.Render();
	}
	else if (m_BubbleOutAnimation.IsPlaying())
	{
		m_BubbleOutAnimation.Render();
	}
	else if (m_BubbleAnimation.IsPlaying())
	{
		m_BubbleAnimation.Render();
	}


	if (m_CanaryBubbleInAnimation.IsPlaying())
	{
		m_CanaryBubbleInAnimation.Render();
	}
	else if (m_CanaryBubbleOutAnimation.IsPlaying())
	{
		m_CanaryBubbleOutAnimation.Render();
	}
	else if (m_CanaryBubbleAnimation.IsPlaying() && m_AnswerStoryStste == Normal)
	{
		m_CanaryBubbleAnimation.Render();
	}



	//===============================

	float wrenStoryX = 250;
	float wrenStoryY = -26;

	if (m_WernStoryIndex == 1 || m_WernStoryIndex == 5)
	{
		Renderer::DrawTexture("wrencaptions_drawing_family_1", wrenStoryX, wrenStoryY, 421, 130, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 2 || m_WernStoryIndex == 6)
	{
		Renderer::DrawTexture("wrencaptions_drawing_family_2", wrenStoryX, wrenStoryY, 421, 222.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 3 || m_WernStoryIndex == 7)
	{
		Renderer::DrawTexture("wrencaptions_drawing_family_3", wrenStoryX, wrenStoryY, 421, 222.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 4)
	{
		Renderer::DrawTexture("wrencaptions_drawing_family_final_1", wrenStoryX, wrenStoryY, 421, 222.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 8)
	{
		Renderer::DrawTexture("wrencaptions_drawing_family_final_2", wrenStoryX, wrenStoryY, 421, 222.5f, 0, 0.5, 0.5);
	}


	if (m_WernStoryIndex == 9 || m_WernStoryIndex == 13)
	{
		Renderer::DrawTexture("wrencaptions_drawing_exercise_1", wrenStoryX, wrenStoryY, 421, 130, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 10 || m_WernStoryIndex == 14)
	{
		Renderer::DrawTexture("wrencaptions_drawing_exercise_2", wrenStoryX, wrenStoryY, 421, 222.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 11 || m_WernStoryIndex == 15)
	{
		Renderer::DrawTexture("wrencaptions_drawing_exercise_3", wrenStoryX, wrenStoryY, 421, 222.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 12)
	{
		Renderer::DrawTexture("wrencaptions_drawing_exercise_final_1", wrenStoryX, wrenStoryY, 421, 222.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 16)
	{
		Renderer::DrawTexture("wrencaptions_drawing_exercise_final_2", wrenStoryX, wrenStoryY, 421, 222.5f, 0, 0.5, 0.5);
	}

	if (m_WernStoryIndex == 17 || m_WernStoryIndex == 21)
	{
		Renderer::DrawTexture("wrencaptions_drawing_food_1", wrenStoryX, wrenStoryY, 420, 155.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 18 || m_WernStoryIndex == 22)
	{
		Renderer::DrawTexture("wrencaptions_drawing_food_2", wrenStoryX, wrenStoryY, 420, 233, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 19 || m_WernStoryIndex == 23)
	{
		Renderer::DrawTexture("wrencaptions_drawing_food_3", wrenStoryX, wrenStoryY, 420, 233, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 20)
	{
		Renderer::DrawTexture("wrencaptions_drawing_food_final_1", wrenStoryX, wrenStoryY, 420, 233, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 24)
	{
		Renderer::DrawTexture("wrencaptions_drawing_food_final_2", wrenStoryX, wrenStoryY, 420, 233, 0, 0.5, 0.5);
	}



	if (m_WernStoryIndex == 25)
	{
		Renderer::DrawTexture("wrencaptions_drawing_singing_1", wrenStoryX, wrenStoryY, 192.5f, 103, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 26)
	{
		Renderer::DrawTexture("wrencaptions_drawing_singing_2", wrenStoryX, wrenStoryY, 335.5f, 123, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 27)
	{
		Renderer::DrawTexture("wrencaptions_drawing_singing_3", wrenStoryX, wrenStoryY, 410.5f, 227.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 28)
	{
		Renderer::DrawTexture("wrencaptions_drawing_singing_final", wrenStoryX, wrenStoryY, 413.5f, 233.5f, 0, 0.5, 0.5);
	}



	if (m_WernStoryIndex == 29)
	{
		Renderer::DrawTexture("wrencaptions_drawing_talking_1", wrenStoryX, wrenStoryY, 227.5f, 202.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 30)
	{
		Renderer::DrawTexture("wrencaptions_drawing_talking_2", wrenStoryX, wrenStoryY, 315.5f, 243.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 31)
	{
		Renderer::DrawTexture("wrencaptions_drawing_talking_3", wrenStoryX, wrenStoryY, 383.5f, 243.5f, 0, 0.5, 0.5);
	}
	else if (m_WernStoryIndex == 32)
	{
		Renderer::DrawTexture("wrencaptions_drawing_talking_final", wrenStoryX, wrenStoryY, 361, 243.5f, 0, 0.5, 0.5);
	}



	float CanaryStoryX = 700;
	float CanaryStoryY = -24;

	if (m_CanaryBubbleErrorAnimation.IsPlaying() && m_AnswerStoryStste==Error)
	{
   		m_CanaryBubbleErrorAnimation.Render();
	}
	else if (m_AnswerStoryStste == Normal)
	{
		if (m_CanaryStoryIndex == 1 || m_CanaryStoryIndex == 5)
		{
			Renderer::DrawTexture("canarycaptions_drawing_family_1", CanaryStoryX, CanaryStoryY, 421, 130, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 2 || m_CanaryStoryIndex == 6)
		{
			Renderer::DrawTexture("canarycaptions_drawing_family_2", CanaryStoryX, CanaryStoryY, 421, 222.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 3 || m_CanaryStoryIndex == 7)
		{
			Renderer::DrawTexture("canarycaptions_drawing_family_3", CanaryStoryX, CanaryStoryY, 421, 222.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 4)
		{
			Renderer::DrawTexture("canarycaptions_drawing_family_final_1", CanaryStoryX, CanaryStoryY, 421, 222.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 8)
		{
			Renderer::DrawTexture("canarycaptions_drawing_family_final_2", CanaryStoryX, CanaryStoryY, 421, 222.5f, 0, 0.5, 0.5);
		}


		if (m_CanaryStoryIndex == 9 || m_CanaryStoryIndex == 13)
		{
			Renderer::DrawTexture("canarycaptions_drawing_exercise_1", CanaryStoryX, CanaryStoryY, 421, 130, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 10 || m_CanaryStoryIndex == 14)
		{
			Renderer::DrawTexture("canarycaptions_drawing_exercise_2", CanaryStoryX, CanaryStoryY, 421, 222.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 11 || m_CanaryStoryIndex == 15)
		{
			Renderer::DrawTexture("canarycaptions_drawing_exercise_3", CanaryStoryX, CanaryStoryY, 421, 222.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 12)
		{
			Renderer::DrawTexture("canarycaptions_drawing_exercise_final_1", CanaryStoryX, CanaryStoryY, 421, 222.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 16)
		{
			Renderer::DrawTexture("canarycaptions_drawing_exercise_final_2", CanaryStoryX, CanaryStoryY, 421, 222.5f, 0, 0.5, 0.5);
		}

		if (m_CanaryStoryIndex == 17 || m_CanaryStoryIndex == 21)
		{
			Renderer::DrawTexture("canarycaptions_drawing_food_1", CanaryStoryX, CanaryStoryY, 420, 155.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 18 || m_CanaryStoryIndex == 22)
		{
			Renderer::DrawTexture("canarycaptions_drawing_food_2", CanaryStoryX, CanaryStoryY, 420, 233, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 19 || m_CanaryStoryIndex == 23)
		{
			Renderer::DrawTexture("canarycaptions_drawing_food_3", CanaryStoryX, CanaryStoryY, 420, 233, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 20)
		{
			Renderer::DrawTexture("canarycaptions_drawing_food_final_1", CanaryStoryX, CanaryStoryY, 420, 233, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 24)
		{
			Renderer::DrawTexture("canarycaptions_drawing_food_final_2", CanaryStoryX, CanaryStoryY, 420, 233, 0, 0.5, 0.5);
		}



		if (m_CanaryStoryIndex == 25)
		{
			Renderer::DrawTexture("canarycaptions_drawing_singing_1", CanaryStoryX, CanaryStoryY, 192.5f, 103, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 26)
		{
			Renderer::DrawTexture("canarycaptions_drawing_singing_2", CanaryStoryX, CanaryStoryY, 335.5f, 123, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 27)
		{
			Renderer::DrawTexture("canarycaptions_drawing_singing_3", CanaryStoryX, CanaryStoryY, 410.5f, 227.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 28)
		{
			Renderer::DrawTexture("canarycaptions_drawing_singing_final", CanaryStoryX, CanaryStoryY, 413.5f, 233.5f, 0, 0.5, 0.5);
		}



		if (m_CanaryStoryIndex == 29)
		{
			Renderer::DrawTexture("canarycaptions_drawing_talking_1", CanaryStoryX, CanaryStoryY, 227.5f, 202.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 30)
		{
			Renderer::DrawTexture("canarycaptions_drawing_talking_2", CanaryStoryX, CanaryStoryY, 315.5f, 243.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 31)
		{
			Renderer::DrawTexture("canarycaptions_drawing_talking_3", CanaryStoryX, CanaryStoryY, 383.5f, 243.5f, 0, 0.5, 0.5);
		}
		else if (m_CanaryStoryIndex == 32)
		{
			Renderer::DrawTexture("canarycaptions_drawing_talking_final", CanaryStoryX, CanaryStoryY, 361, 243.5f, 0, 0.5, 0.5);
		}
	}

}

void GameModeMeetTweet::CanaryStoryplay()
{
	double currentTime = Time::GetRealtimeSinceStartup() - m_StartTime;
	float beatUnitTime = (60.0f / m_CurrentLevel->BPM);

	if (currentTime >= beatUnitTime * m_CurrentLevel->Blocks[4])
	{
		m_CanaryStoryIndex += 1;

		if (m_CanaryStoryIndex == 1)
		{
			m_CanaryBubbleInAnimation.Play();
		}
		if (m_CanaryStoryIndex == 36)
		{                                   
			m_CanaryBubbleOutAnimation.Play();
		}
		else
		{
			m_CanaryBubbleAnimation.Play();
		}
	}
}
