#include "XKJ.h"
#include "GameOutput.h"
#include "GameInput.h"
#include "S_Manager.h"
#include "Scene.h"

#include <time.h>

static BOOL g_Act;
CKJ* CKJ::p = nullptr;

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

int CKJ::GetCW()
{
	return m_cw;
}
int CKJ::GetCH()
{
	return m_ch;
}

bool CKJ::AddScene(const char* id, CScene* p)
{
	if(m_sm == nullptr)
		return false;

	return m_sm->AddScene(id, p);
}

void CKJ::EraseScene(const char* id)
{
	if (m_sm == nullptr)
		return;

	return m_sm->EraseScene(id);
}

void CKJ::SetStartScene(const char* id)
{
	m_curS = m_sm->GetScene(id);
}

void CKJ::SetNextScene(const char* id)
{
	m_nextS = m_sm->GetScene(id);
}

CKJ::CKJ()
{
	m_hWnd = 0;
	m_sm = nullptr;
}

CKJ::CKJ(const CKJ& that)
{
}

CKJ* CKJ::GetKJ()
{
	if (p == nullptr)
		p = new CKJ;
	return p;
}

void CKJ::Init(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	m_cw = 1000;
	m_ch = 800;
	g_Act = TRUE;
	//1) ��䴰�ڽṹ��
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
	wc.lpszClassName = "ʮ��";

	//2��ע�ᴰ�ڣ��ô��ڽṹ������������ݣ�
	RegisterClass(&wc);

	int sw = GetSystemMetrics(SM_CXSCREEN);
	int sh = GetSystemMetrics(SM_CYSCREEN);

	RECT rect
		=
	{
		(sw - m_cw) / 2,
		(sh - m_ch) / 2,
		m_cw + (sw - m_cw) / 2,
		m_ch + (sh - m_ch) / 2
	};

	AdjustWindowRect(&rect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, FALSE);

	//3���ô��ڽṹ������������
	m_hWnd = CreateWindow(wc.lpszClassName, "��һ������",
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		HWND_DESKTOP, 0, wc.hInstance, 0);

	//4����ʾ���ڣ����ھ������ʾ��ʽ��
	ShowWindow(m_hWnd, nCmdShow);

	//5�����´��ڣ����ھ����
	UpdateWindow(m_hWnd);

	CGO::GetGO()->Init();
	CGameInput::GetGI()->SetHWND(m_hWnd);
	m_curS = nullptr;
	m_nextS = nullptr;

	m_sm = new CSM;
}

void CKJ::Run()
{
	//srand((int)time(0));
	rand();
	if (m_curS != nullptr)
		m_curS->Init();
	CGO* go = CGO::GetGO();
	CGameInput* gi = CGameInput::GetGI();
	//6����Ϣѭ��
	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		//�������Ϣ�ʹ�����Ϣ ����ִ����Ϸ
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if (g_Act)
		{
			//���Ĵ���
			gi->Update();
			go->Begin();

			if (m_curS != nullptr)
				m_curS->Run();
			
			go->End();

			if (m_nextS)
			{
				m_curS->End();
				m_curS = m_nextS;
				m_nextS = nullptr;
				m_curS->Init();
			}
		}
		else
		{
			WaitMessage();
		}
		Sleep(1);
	}
}

void CKJ::End()
{
}

HWND CKJ::GetHWND()
{
	return m_hWnd;
}