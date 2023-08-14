#include <Windows.h>
#include "Core/FrameWork.h"
#include "Scene/StartScene.h"
#include "Scene/FightScene.h"
#include "Scene/TestSence2.h"
#include "Scene/ta.h"
#include "Math/vector.h"
#include "Math/Matrix.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, PSTR lpCmdLine, INT iCmdShow)
{
	//框架的单例
	CFrameWork* jk = CFrameWork::GetFrameWork();
	//框架初始化
	jk->Init(hInstance, hPreInstance, lpCmdLine, iCmdShow);
	//生成框架中的场景
	jk->AddScene("Test", new CTestScene3);
	//jk->AddScene("战斗场景", new CFightScene);

	//开始场景
	jk->SetStartScene("Test");
	//运行
	CFrameWork::GetFrameWork()->Run();

	return 1;
} 