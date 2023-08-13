#include "S_Manager.h"
#include "Scene.h"
bool CSM::AddScene(const char* id, CScene* p)
{
    if (id == nullptr || p == nullptr)
        return false;

    if(m_sm.find(id) != m_sm.end())
        return false;

    m_sm.insert(std::pair<const char*, CScene*>(id, p));
}

void CSM::EraseScene(const char* id)
{
    if (id == nullptr)
        return;
    std::map<const char*, CScene*>::iterator it;
    it = m_sm.find(id);
    if (it == m_sm.end())
        return ;
    delete it->second;
    m_sm.erase(it);
}

CScene* CSM::GetScene(const char* id)
{
    if (id == nullptr)
        return nullptr;
    std::map<const char*, CScene*>::iterator it;
    it = m_sm.find(id);
    if (it == m_sm.end())
        return nullptr;
    return it->second;
}

void CSM::Clear()
{
    std::map<const char*, CScene*>::iterator it;
    for (it = m_sm.begin(); it != m_sm.end(); ++it)
        delete it->second;

    m_sm.clear();
}
