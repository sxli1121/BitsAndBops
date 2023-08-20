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
	//��ܵĵ���
	CFrameWork* jk = CFrameWork::GetFrameWork();
	//��ܳ�ʼ��
	jk->Init(hInstance, hPreInstance, lpCmdLine, iCmdShow);
	//���ɿ���еĳ���
	jk->AddScene("Start", new CStartScene);
	//jk->AddScene("ս������", new CFightScene);

	//��ʼ����
	jk->SetStartScene("Start");
	//����
	CFrameWork::GetFrameWork()->Run();

	return 1;
} 