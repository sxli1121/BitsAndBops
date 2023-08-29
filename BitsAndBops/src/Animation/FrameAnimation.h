#pragma once
#include "Renderer/Texture.h"
#include <vector>
#include <string>

enum class AnimationMode
{
	Once,
	Loop
};

struct AnimationKeyFrame
{
	float time;
	std::string textureId;
	float x;
	float y;
	float width;
	float height;
	float rotation;
	float pivotX;
	float pivotY;
};

class FrameAnimation
{
public:
	void AddFrame(AnimationKeyFrame frame);

	void SetMode(AnimationMode mode);
	AnimationMode GetMode() { return m_Mode; }

	float GetLength() { return m_Length; }

	void Play();
	void Update(float dt);
	void Render();

	bool IsPlaying() { return m_IsPlaying; }

	void Reset()
	{
		m_Length = 0;
		m_IsPlaying = false;
		m_CurrentTime = 0;
		m_CurrentFrameIndex = 0;
		m_Frames.clear();
	}

private:
	float m_Length{0};

	AnimationMode m_Mode{ AnimationMode::Once };
	std::vector<AnimationKeyFrame> m_Frames;
	AnimationKeyFrame m_CurrentStatus;
	bool m_IsPlaying{ false };
	float m_CurrentTime{ 0 };
	int m_CurrentFrameIndex = 0;
};

