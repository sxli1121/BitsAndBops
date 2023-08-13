#pragma once
#include "CObject.h"
#include "Action.h"
#include "Hero_idle.h"
#include "Hero_Move.h"
#include <string>
#include <map>
class CAction;
class CHero :public CObject
{
	//Ó¢ÐÛµÄ¶¯»­map
	std::map<std::string, CAction*> m_ActionMap;
	CAction* m_CurAction;
	std::string m_NextAction;
	int m_Dir;

public:
	void Init();
	void Run();
	void End();
	void SetNextAction(const char* key);
	void SetDir(int Dir);
	int GetDir();
};

