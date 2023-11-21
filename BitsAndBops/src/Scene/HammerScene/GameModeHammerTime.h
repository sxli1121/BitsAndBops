#pragma once
#include "Animation/FrameAnimation.h"
#include <vector>

struct HammerBlock
{
	std::vector<float> Nails;
};

enum class LevelName
{
	HAMMER_TEACH,
	HAMMER_GAME,
};

struct HammerLevel
{
	LevelName levelName;
	float Duration;
	std::vector<HammerBlock> Blocks;
	int BPM;
	int BeatsPerMeasure;
};

enum class NailState
{
	Normal,
	Miss,
	Perfect,
	AlmostEarly,
	AlmostLate,
};

struct NailObject
{
	float x;
	float BornBetas;
	NailState State;
};

struct MobileStation
{
	float x;
	float MobileWidth;
};



class GameModeHammerTime
{
public:
	void Init();
	void Play(HammerLevel* lever);
	void Update(float dt);
	void Render();
	bool IsDone();

	bool GetLevelFinished();
	float GetGrades();
private:
	void GenerateNails();
	void UpdateNails(float dt);
	void DrawNails();

	float CalculateGrades();
private:
	HammerLevel* m_CurrentLevel{ nullptr };

	std::vector<NailObject> m_AllNails;
	std::vector<MobileStation> m_AllMobile;

	double m_StartTime{ 0.0 };
	int m_NextBlockIndex{ 0 };
	int m_NextNailIndex{ 0 };
	bool m_LevelFinished{ false };
	float m_mobileSpeed{ 0.0f };
	int m_Scor{ 0 };

	const float HitJudgmentTimePerfect = 0.05f;
	const float HitJudgmentTimeAlmost = 0.2f;
	const float HitJudgmentTimeMiss = 0.3f;

	FrameAnimation m_HandAnimation;
	FrameAnimation m_HammerAnimation;
	FrameAnimation m_HammmerSmearAnimation;
	FrameAnimation m_HammerPerfectAnimation;
	FrameAnimation m_HammerAlmostAnimation;

	FrameAnimation m_HandSmearAnimation;
};

