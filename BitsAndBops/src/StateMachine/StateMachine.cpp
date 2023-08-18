#include "StateMachine.h"
#include "State.h"
#include <cassert>


void StateMachine::AddState(int id, State* state)
{
    assert(id != STATE_NONE);
    assert(state != nullptr);
    assert(GetStateById(id) == nullptr);

    m_States[id] = state;
}

void StateMachine::Update(float dt)
{
    if (m_NextState != nullptr)
    {
        if (m_CurrentState != nullptr)
        {
            m_CurrentState->OnExit();
        }
        m_CurrentState = m_NextState;
        m_CurrentId = m_NextId;
        m_NextState = nullptr;
        m_NextId = STATE_NONE;

        m_CurrentState->OnEnter();
    }

    if (m_CurrentState != nullptr)
    {
        m_CurrentState->OnUpdate(dt);
    }
  
}

void StateMachine::Switch(int id)
{
    assert(id != STATE_NONE);

    State* state = GetStateById(id);
    assert(state != nullptr);
   
    m_NextState = state;
    m_NextId = id;
}

int StateMachine::GetCurrentStateId()
{
    return m_CurrentId;
}

State* StateMachine::GetStateById(int id)
{
    auto it = m_States.find(id);
    if (it == m_States.end()) return nullptr;
    return it->second;
}
