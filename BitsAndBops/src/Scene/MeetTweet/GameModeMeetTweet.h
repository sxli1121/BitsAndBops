#pragma once
#include "Animation/FrameAnimation.h"
#include "Tools/Timer.h"
#include <vector>

struct TweetLevel
{
	float Duration;
	std::vector<float> Blocks;
	int BPM;
	std::vector<int> BeatsPerMeasure;
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
	
private:
	TweetLevel* m_CurrentLevel{ nullptr };

	std::vector<AnswerBeat> m_AnswerBeats;

	int m_NextBlockIndex{ 0 };
	int m_HalfBeatIndex{ 0 };
	int m_NextBeatIndex{ 0 };
	int m_BeatPerMeasureIndex{ 0 };
	int m_CaptionIndex{ 0 };
	bool m_LevelFinished{ false };
	int m_Scorer{ 0 };
	double m_StartTime{ 0.0 };

	const float HitJudgmentTimePerfect = 0.05f;
	const float HitJudgmentTimeAlmost = 0.3f;
	const float HitJudgmentTimeMiss = 0.5f;

	FrameAnimation m_CanaryBopAnimation;
	FrameAnimation m_CanaryPerfectAnimation;
	FrameAnimation m_CanaryAlmostAnimation;
	FrameAnimation m_CanaryMissAnimation;
	FrameAnimation m_RadioAnimation;
};

