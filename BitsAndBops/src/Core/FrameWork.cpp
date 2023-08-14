#include "FrameWork.h"
#include "OutputAndInput/GameOutput.h"
#include "OutputAndInput/GameInput.h"
#include "Core/Scene_Manager.h"
#include "Core/Scene.h"

#include <time.h>

//焦点
static BOOL g_Act;
CFrameWork* CFrameWork::frame_work = nullptr;

//消息拦截
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg,
	WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_ACTIVATEAPP:
	{
		g_Act = (BOOL)wParam;
		return 0;
	}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int CFrameWork::GetClientW()
{
	return m_ClientW;
}

int CFrameWork::GetClientH()
{
	return m_ClientH;
}

bool CFrameWork::AddScene(const char* id, CScene* p)
{
	if(m_SceneManage == nullptr)
		return false;
	return m_SceneManage->AddScene(id, p);
}

void CFrameWork::EraseScene(const char* id)
{
	if (m_SceneManage == nullptr)
		return;
	return m_SceneManage->EraseScene(id);
}

void CFrameWork::SetStartScene(const char* id)
{
	m_CurScene = m_SceneManage->GetScene(id);
}

void CFrameWork::SetNextScene(const char* id)
{
	m_NextScene = m_SceneManage->GetScene(id);
}

CFrameWork::CFrameWork()
{
	m_hWnd = 0;
	m_SceneManage = nullptr;
}

CFrameWork::CFrameWork(const CFrameWork& that)
{

}

CFrameWork* CFrameWork::GetFrameWork()
{
	if (frame_work == nullptr)
		frame_work = new CFrameWork;
	return frame_work;
}

void CFrameWork::Init(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	m_ClientW = 1000;
	m_ClientH = 800;
	g_Act = TRUE;
	//1) 填充窗口结构体
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpszMenuName = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "十四";

	//2）注册窗口（该窗口结构体必须填充好数据）
	RegisterClass(&wc);
	int sw = GetSystemMetrics(SM_CXSCREEN);
	int sh = GetSystemMetrics(SM_CYSCREEN);

	RECT rect
		=
	{
		(sw - m_ClientW) / 2,
		(sh - m_ClientH) / 2,
		m_ClientW + (sw - m_ClientW) / 2,
		m_ClientH + (sh - m_ClientH) / 2
	};

	AdjustWindowRect(&rect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, FALSE);

	//3）用窗口结构体来创建窗口
	m_hWnd = CreateWindow(wc.lpszClassName, "第一个窗口",
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		HWND_DESKTOP, 0, wc.hInstance, 0);

	//4）显示窗口（窗口句柄，显示方式）
	ShowWindow(m_hWnd, nCmdShow);

	//5）更新窗口（窗口句柄）
	UpdateWindow(m_hWnd);

	CGameOutput::GetGameOutput()->Init();
	CGameInput::GetGameInput()->SetHWND(m_hWnd);

	m_CurScene = nullptr;
	m_NextScene = nullptr;
	m_SceneManage = new CSceneManage;
}

void CFrameWork::Run()
{
	srand((int)time(0));
	rand();

	if (m_CurScene != nullptr)
		m_CurScene->Init();
	CGameOutput* go = CGameOutput::GetGameOutput();
	CGameInput* gi = CGameInput::GetGameInput();
	//6）消息循环
	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		//如果有消息就处理消息 否则执行游戏
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if (g_Act)
		{
			//输入输出初始化-当前场景运行
			gi->Update();
			go->Begin();
			if (m_CurScene != nullptr)
				m_CurScene->Run();
			go->End();
			//场景的切换
			if (m_NextScene)
			{
				m_CurScene->End();
				m_CurScene = m_NextScene;
				m_NextScene = nullptr;
				m_CurScene->Init();
			}
		}
		else
		{
			WaitMessage();
		}
		Sleep(1);
	}
}

void CFrameWork::End()
{

}

HWND CFrameWork::GetHWND()
{
	return m_hWnd;
}