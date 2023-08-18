#pragma once
#include <map>
class State;

#define STATE_NONE -1

class StateMachine
{
public:
	void AddState(int id,State* state);
	void Update(float dt);
	void Switch(int id);
	int  GetCurrentStateId();

private:
	State* GetStateById(int id);

private:
	State* m_CurrentState{ nullptr };
	State* m_NextState{ nullptr };
	int m_CurrentId{ STATE_NONE };
	int m_NextId{ STATE_NONE };
	std::map<int, State*> m_States;

};

