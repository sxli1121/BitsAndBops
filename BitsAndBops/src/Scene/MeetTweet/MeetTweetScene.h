#pragma once
#include "Core/Scene.h"
#include "StateMachine/StateMachine.h"
#include "Scene/MeetTweet/GameModeMeetTweet.h"
#include "OutPutAndInput/Camera.h"
#include "Math/Vector2.h"
#include "Scene/TitleScene.h"

enum Tweet_State
{
	//场景里面的状态
	STATE_TWEET_OPEN,
	STATE_TWEET_CONFIRM,
	STATE_TWEET_TEACH1,
	STATE_TWEET_TEACH2,
	STATE_TWEET_GAME,
	STATE_TWEET_SETTLEMENT,
};

class TweetOpening;
class TweetConfirming;
class TweetTeachingOne;
class TweetTeachingTwo;
class TweetGaming;
class TweetSettlementing;

class MeetTweetScene : public CScene
{
public:
	void Init();
	void Update(float dt);
	void End();

	StateMachine* GetStateMachine() { return m_StateMachine; }
private:
	StateMachine* m_StateMachine;

	TweetOpening* m_OpeningState{ nullptr };
	TweetConfirming* m_ConfirmingState{ nullptr };
	TweetTeachingOne* m_TeachingOneState{ nullptr };
	TweetTeachingTwo* m_TeachingTwoState{ nullptr };
	TweetGaming* m_GamingState{ nullptr };
	TweetSettlementing* m_SettlementingState{ nullptr };
	GameModeMeetTweet* g_gameModeMeetTweet;

	Camera m_Camera;
	Vector2 m_CameraPosition;
	float m_CameraRotation{ 0.0f };
	float m_CameraScale{ 1.0f };

	GameMode m_GameMode;

	friend class TweetOpening;
	friend class TweetConfirming;
	friend class TweetTeachingOne;
	friend class TweetTeachingTwo;
	friend class TweetGaming;
	friend class TweetSettlementing;
};
