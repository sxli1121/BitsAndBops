#include <Windows.h>
#include "Core/FrameWork.h"
#include "Scene/StartScene.h"
#include "Scene/TitleScene.h"
#include "Scene/MenuScene.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Scene/MeetTweet/MeetTweetScene.h"



INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, PSTR lpCmdLine, INT iCmdShow)
{
	CFrameWork* frameWork = CFrameWork::GetFrameWork();

	frameWork->Init(hInstance, hPreInstance, lpCmdLine, iCmdShow);
	frameWork->AddScene("Start", new CStartScene);
	frameWork->AddScene("Title", new CTitleScene);
	frameWork->AddScene("Menu", new MenuScene);
	frameWork->AddScene("Hammer", new CHammerScene);
	frameWork->AddScene("MeetTweet", new MeetTweetScene);

	//frameWork->SetStartScene("Start");
	frameWork->SetStartScene("Hammer");

	CFrameWork::GetFrameWork()->Run();
	return 1;
}
