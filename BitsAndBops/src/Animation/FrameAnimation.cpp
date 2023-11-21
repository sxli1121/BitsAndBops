#include "FrameAnimation.h"
#include "Renderer/TextureManager.h"
#include "Renderer/Renderer.h"
#include <cassert>

void FrameAnimation::AddFrame(AnimationKeyFrame frame)
{
	assert(TextureManager::GetTexture(frame.textureId) != nullptr);
	if (m_Frames.size() != 0)
	{
		assert(frame.time >= m_Frames[m_Frames.size() - 1].time);
	}
	m_Length = frame.time;
	m_Frames.push_back(frame);
}


void FrameAnimation::AddFrame(const std::string& textureId, const Vector2& position, const Vector2& size,
	float rotation, const Vector2& pivot, float duration)
{
	AnimationKeyFrame frame;
	frame.textureId = textureId;
	frame.x = position.x;
	frame.y = position.y;
	frame.width = size.x;
	frame.height = size.y;
	frame.rotation = rotation;
	frame.pivotX = pivot.x;
	frame.pivotY = pivot.y;
	frame.time = !m_Frames.empty() ? m_Frames[m_Frames.size()-1].time : 0.0f;

	AddFrame(frame);

	if(duration > 0.0f)
	{
		frame.time += duration;
		AddFrame(frame);
	}
}

void FrameAnimation::SetMode(AnimationMode mode)
{
	m_Mode = mode;
}


void FrameAnimation::Play()
{
	m_IsPlaying = true;
	m_CurrentTime = 0;
	m_CurrentFrameIndex = 0;
}

inline float lerp(float from, float to, float p)
{
	return from + (to - from) * p;
}

void FrameAnimation::Update(float dt)
{
	if (!m_IsPlaying)
		return;

	if (m_Frames.size() == 0)
	{
		m_IsPlaying = false;
		return;
	}

	m_CurrentTime += dt;

	// 检查是不是播完了
	if (m_CurrentTime > m_Length)
	{
		if (m_Mode == AnimationMode::Once)
		{
			m_IsPlaying = false;
			return;
		}
		else if(m_Mode == AnimationMode::Loop) {
			m_IsPlaying = true;
			m_CurrentTime = 0;
			m_CurrentFrameIndex = 0;
		}
	}

	// Skip frames;
	while (true)
	{
		if (m_CurrentFrameIndex + 1 == m_Frames.size()) break;
		AnimationKeyFrame nextFrame = m_Frames[m_CurrentFrameIndex + 1];
		if (m_CurrentTime < nextFrame.time) break;
		m_CurrentFrameIndex++;
	}

	AnimationKeyFrame currentFrame = m_Frames[m_CurrentFrameIndex];
	if (m_CurrentFrameIndex + 1 < m_Frames.size())
	{
		AnimationKeyFrame nextFrame = m_Frames[m_CurrentFrameIndex + 1];

		float length = nextFrame.time - currentFrame.time;
		float p = (m_CurrentTime - currentFrame.time) / length;
		m_CurrentStatus.textureId = currentFrame.textureId;
		m_CurrentStatus.x = lerp(currentFrame.x, nextFrame.x, p);
		m_CurrentStatus.y = lerp(currentFrame.y, nextFrame.y, p);
		m_CurrentStatus.width = lerp(currentFrame.width, nextFrame.width, p);
		m_CurrentStatus.height = lerp(currentFrame.height, nextFrame.height, p);
		m_CurrentStatus.rotation = lerp(currentFrame.rotation, nextFrame.rotation, p);
		m_CurrentStatus.pivotX = lerp(currentFrame.pivotX, nextFrame.pivotX, p);
		m_CurrentStatus.pivotY = lerp(currentFrame.pivotY, nextFrame.pivotY, p);
	}
	else {
		m_CurrentStatus = currentFrame;
	}
}

void FrameAnimation::Render()
{
	Renderer::DrawTexture(m_CurrentStatus.textureId, m_CurrentStatus.x, m_CurrentStatus.y,
		m_CurrentStatus.width, m_CurrentStatus.height,m_CurrentStatus.rotation,m_CurrentStatus.pivotX, m_CurrentStatus.pivotY);
}
