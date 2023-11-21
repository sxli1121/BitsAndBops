#pragma once
#include "Animation/FrameAnimation.h"
#include "Tools/Timer.h"
#include <vector>

enum class TweetLevelName
{
	TWEET_TEACH_ONE,
	TWEET_TEACH_TWO,
	TWEET_GAME,
};

enum CanaryStoryState
{
	Normal,
	Error,
};

struct TweetLevel
{
	TweetLevelName levelName;
	float Duration;
	std::vector<float> Blocks;
	int BPM;
	std::vector<int> BeatsPerMeasure;

	~TweetLevel();
};

enum class KeystorkeAnswerState
{
	Normal,
	Miss,
	Perfect,
	Almost,
};

struct AnswerBeat
{
	KeystorkeAnswerState State;
	double Beat;
};

class GameModeMeetTweet
{
public:
	~GameModeMeetTweet();
	void Init();
	void Play(TweetLevel* lever);
	void Update(float dt);
	void Render();
	bool IsDone();

	float GetGrades();
private:
	void GeneratePromptAudio();
	void UpdateAnswerBeats(float dt);
	void PromoptObject();

	void GameRender();

	void CanaryStoryplay();
private:
	TweetLevel* m_CurrentLevel{ nullptr };

	std::vector<AnswerBeat> m_AnswerBeats;

	int m_NextBlockIndex{ 0 };
	int m_HalfBeatIndex{ 0 };
	int m_NextBeatIndex{ 0 };
	int m_BeatPerMeasureIndex{ 0 };

	int m_CaptionIndex{ 0 };   
	int m_WernStoryIndex{0};
	int m_CanaryStoryIndex{ 0 };
	bool m_LevelFinished{ false };



	int m_Scor{ 0 };
	double m_StartTime{ 0.0 };
	bool m_IsOneSubtitle{ false };
	bool m_IsTwoSubtitle{ false };

	const float HitJudgmentTimePerfect = 0.1f;
	const float HitJudgmentTimeAlmost = 0.2f;
	const float HitJudgmentTimeMiss = 0.3f;

	FrameAnimation m_CanaryBopAnimation;
	FrameAnimation m_CanaryPerfectAnimation;
	FrameAnimation m_CanaryAlmostAnimation;
	FrameAnimation m_CanaryMissAnimation;
	FrameAnimation m_RadioAnimation;

	FrameAnimation m_WrenPromoteAnimation;
	FrameAnimation m_WrenBopAnimation;
	FrameAnimation m_WrenGiggleAnimation;
	FrameAnimation m_WrenHappyAnimation;
	FrameAnimation m_WrenConfuseAnimation;
	FrameAnimation m_WrenAngerAnimation;

	FrameAnimation m_BubbleAnimation;
	FrameAnimation m_BubbleInAnimation;
	FrameAnimation m_BubbleOutAnimation;

	FrameAnimation m_CanaryBubbleAnimation;
	FrameAnimation m_CanaryBubbleInAnimation;
	FrameAnimation m_CanaryBubbleOutAnimation;
	FrameAnimation m_CanaryBubbleErrorAnimation;
	int m_AnswerStoryStste{ Normal };

	FrameAnimation m_Bop1Animation;
	FrameAnimation m_Bop2Animation;
};

