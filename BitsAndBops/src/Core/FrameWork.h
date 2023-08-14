#pragma once
#include <windows.h>
class CSceneManage;
class CScene;

class CFrameWork
{
private:
	int m_ClientW;                //窗口宽高
	int m_ClientH;
	static CFrameWork* frame_work;         //单例指针
	CFrameWork();
	CFrameWork(const CFrameWork& that);

	HWND m_hWnd;                 //窗口句柄
	CScene* m_CurScene;		    //当前场景
	CScene* m_NextScene;	        
	CSceneManage* m_SceneManage;			//场景管理

public:
	static CFrameWork* GetFrameWork();

	void Init(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow);
	void Run();
	void End();

	int GetClientW();
	int GetClientH();
	HWND GetHWND();

	bool AddScene(const char* id, CScene* p);
	void EraseScene(const char* id);
	void SetStartScene(const char* id);
	void SetNextScene(const char* id);
};