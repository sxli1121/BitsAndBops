#include <Windows.h>
#include "Core/FrameWork.h"
#include "Scene/StartScene.h"
#include "Scene/TestSence2.h"
#include "Scene/HammerScene/HammerScene.h"
#include "Scene/StartScene.h"
#include "Math/vector.h"
#include "Math/Matrix.h"

//#include "Scene/HammerScene.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, PSTR lpCmdLine, INT iCmdShow)
{
	//框架的单例
	CFrameWork* jk = CFrameWork::GetFrameWork();
	//框架初始化
	jk->Init(hInstance, hPreInstance, lpCmdLine, iCmdShow);
	//生成框架中的场景
	jk->AddScene("Start", new CStartScene);
	//jk->AddScene("战斗场景", new CFightScene);

	//开始场景
	jk->SetStartScene("Start");
	//运行
	CFrameWork::GetFrameWork()->Run();

	return 1;
} 