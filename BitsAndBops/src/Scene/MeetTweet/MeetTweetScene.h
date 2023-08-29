#pragma once
#include "Core/Scene.h"
#include "Tools/Timer.h"
#include "Tools/TimerStampManage.h"
#include "StateMachine/StateMachine.h"
#include "Animation/FrameAnimation.h"
#include "Scene/MeetTweet/GameModeMeetTweet.h"
#include <vector>

enum TweetState
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
class Camera;

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
	Camera* m_Camera;
	GameModeMeetTweet* g_gameModeMeetTweet;

	friend class TweetOpening;
	friend class TweetConfirming;
	friend class TweetTeaching_one;
	friend class TweetTeaching_two;
	friend class TweetGaming;
	friend class TweetSettlementing;
	

};

