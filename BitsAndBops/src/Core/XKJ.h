#pragma once
#include <windows.h>
class CSM;
class CScene;
class CKJ
{
	int m_cw;
	int m_ch;
	static CKJ* p;
	HWND m_hWnd;
	CKJ();
	CKJ(const CKJ& that);
	CScene* m_curS;		//当前正在运行的场景
	CScene* m_nextS;	//准备切换的场景
	CSM* m_sm;			//场景管理者
public:
	static CKJ* GetKJ();

	void Init(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow);
	HWND GetHWND();
	void Run();
	void End();
	int GetCW();
	int GetCH();

	bool AddScene(const char* id, CScene* p);
	void EraseScene(const char* id);

	void SetStartScene(const char* id);
	void SetNextScene(const char* id);
};