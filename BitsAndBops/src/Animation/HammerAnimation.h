#pragma once
#include "GameObject/CObject.h"
#include "Audio/AudioManager.h"

#include <string>
#include <map>

class Animation;

class CHammer
{

public:
	void Init();
	void Update(float dt);
	void End();

	void HandAmation_Play();
	void HammerAmation_Play();
private:
	Animation* m_HammerAmation1{ nullptr };
	Animation* m_HammerAmation2{ nullptr };
	Animation* m_HammerAmation3{ nullptr };
	Animation* m_HandAmation{ nullptr };

	const float m_AnimationDuration = 0.3f;
	float m_AnimationTime = 0.0f;

	const float m_RotationFrom = 90.0f;
	const float m_RotationTo = 0.0f;

	bool m_IsPlaying = false;
	float m_CurrentRotation = m_RotationFrom;
};

