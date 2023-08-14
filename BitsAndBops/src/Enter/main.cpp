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
	//��ܵĵ���
	CFrameWork* jk = CFrameWork::GetFrameWork();
	//��ܳ�ʼ��
	jk->Init(hInstance, hPreInstance, lpCmdLine, iCmdShow);
	//���ɿ���еĳ���
	jk->AddScene("Test", new CTestScene3);
	//jk->AddScene("ս������", new CFightScene);

	//��ʼ����
	jk->SetStartScene("Test");
	//����
	CFrameWork::GetFrameWork()->Run();

	return 1;
} 