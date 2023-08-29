#pragma once
#include "Animation/FrameAnimation.h"
#include <vector>

struct TweetBlock
{
	std::vector<float> TweetCall;
};

struct TweetLevel
{
	float Duration;
	std::vector<TweetBlock> Blocks;
	int BPM;
	int BeatsPerMeasure;
};

enum class TweetState
{
	Normal,
	Miss,
	Perfect,
	Almost,
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
	
private:
	HammerLevel* m_CurrentLevel{ nullptr };

	double m_StartTime{ 0.0 };
	int m_NextBlockIndex{ 0 };
	int m_NextNailIndex{ 0 };
	bool m_LevelFinished{ false };
	float m_mobileSpeed{ 0.0f };
	int m_Scorer{ 0 };


	const float HitJudgmentTimePerfect = 0.05f;
	const float HitJudgmentTimeAlmost = 0.3f;
	const float HitJudgmentTimeMiss = 0.5f;

	FrameAnimation m_HandAnimation;
	FrameAnimation m_HammerAnimation;


};

