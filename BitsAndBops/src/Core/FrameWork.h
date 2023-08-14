#pragma once
#include <windows.h>
class CSceneManage;
class CScene;

class CFrameWork
{
private:
	int m_ClientW;                //���ڿ��
	int m_ClientH;
	static CFrameWork* frame_work;         //����ָ��
	CFrameWork();
	CFrameWork(const CFrameWork& that);

	HWND m_hWnd;                 //���ھ��
	CScene* m_CurScene;		    //��ǰ����
	CScene* m_NextScene;	        
	CSceneManage* m_SceneManage;			//��������

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