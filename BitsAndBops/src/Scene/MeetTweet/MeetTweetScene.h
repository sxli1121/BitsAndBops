#pragma once
#include "Core/Scene.h"
#include "Tools/Timer.h"
#include "Tools/TimerStampManage.h"
#include "StateMachine/StateMachine.h"
#include "Animation/FrameAnimation.h"
#include "Scene/MeetTweet/GameModeMeetTweet.h"
#include "OutPutAndInput/Camera.h"

#include "Tools/Timer.h"
#include <vector>

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
	GameModeMeetTweet* g_gameModeMeetTweet;


	friend class TweetOpening;
	friend class TweetConfirming;
	friend class TweetTeachingOne;
	friend class TweetTeachingTwo;
	friend class TweetGaming;
	friend class TweetSettlementing;

};

//正式关卡的节拍 切换   1121   2221   2221      1121       1121       1122       1121      1111   1112 

////float[] numArray1 = new float[23]
//{
//	17f,                          //4
//		21f,                      //6
//		28f,					  //
//		44f,					  //6
//		60f,					  //5
//		65f,					  //4
//		69f,					  //7
//		76f,					  //5
//		81f,					  //4
//		85f,					  //7
//		92f,					  //4
//		96f,					  //4
//		100f,					  //12
//		112f,					  //4
//		116f,					  //8
//		124f,					  //
//		128.5f,					  //
//		132.5f,					  //
//		136.5f,					  //
//		140f,					  //
//		144.5f,					  //
//		148.5f,					  //
//		152.5f					  //
//};





//float[] numArray2 = new float[13]
//{
//	24f,
//		32f,
//		36f,
//		40f,
//		48f,
//		52f,
//		56f,
//		72f,
//		88f,
//		104f,
//		107f,
//		120f,
//		155f
//};
//numArray1 = new float[10]
//{
//	8f,
//		12f,
//		16f,
//		20f,
//		24f,
//		28f,
//		32f,
//		36f,
//		40f,
//		44f
//};
//numArray2 = new float[10]
//{
//	8f,
//		12f,
//		16f,
//		20f,
//		24f,
//		28f,
//		32f,
//		36f,
//		40f,
//		44f
//};


