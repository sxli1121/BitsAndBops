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
	CScene* m_curS;		//��ǰ�������еĳ���
	CScene* m_nextS;	//׼���л��ĳ���
	CSM* m_sm;			//����������
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