#include "Hero.h"
#include "Hero_idle.h"
#include "Hero_Move.h"
#include "Action.h"
void CHero::Init()
{
	CAction* act;
	act = new CHero_idle;
	//类对象就是行为要挂载的对象
	act->SetTag(this);
	act->Init();
	m_ActionMap.insert(std::pair < std::string,CAction*> ("idle", act));

	act = new Hero_Move;
	act->SetTag(this);
	act->Init();
	m_ActionMap.insert(std::pair < std::string, CAction*>("move", act));

	m_CurAction = act;
	m_Dir = 5;

	//接下来的行为

}

void CHero::Run()
{
	m_CurAction->Run();

	if (m_NextAction.size()!=0)
	{
		std::map<std::string, CAction*>::iterator it;
		it = m_ActionMap.find(m_NextAction);
		if (it != m_ActionMap.end())
		{
			m_CurAction->End();
			m_CurAction = it->second;
			m_CurAction->Act_Begin();
		}
		m_NextAction.clear();
	}

}

void CHero::End()
{

}

void CHero::SetNextAction(const char* key)
{
	if (key == 0)
		return;
	m_NextAction = key;
}

void CHero::SetDir(int Dir)
{
	m_Dir = Dir;
}

int CHero::GetDir()
{
	return m_Dir;
}
