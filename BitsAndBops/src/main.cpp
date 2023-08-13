#include <Windows.h>
#include "Core/XKJ.h"
#include "Scene/StartScene.h"
#include "Scene/FightScene.h"
#include "Scene/TestSence2.h"
#include "Scene/ta.h"
#include "Math/vector.h"
#include "Math/Matrix.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, PSTR lpCmdLine, INT iCmdShow)
{
	CKJ* jk = CKJ::GetKJ();
	jk->Init(hInstance, hPreInstance, lpCmdLine, iCmdShow);
	jk->AddScene("Test", new CTestScene3);
	jk->AddScene("Õ½¶·³¡¾°", new CFightScene);

	jk->SetStartScene("Test");
	CKJ::GetKJ()->Run();

	return 1;
} 