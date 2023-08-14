#include "Scene_Manager.h"
#include "Scene.h"

bool CSceneManage::AddScene(const char* id, CScene* scene)
{
    if (id == nullptr || scene == nullptr)
        return false;
    if(m_SceneManageMap.find(id) != m_SceneManageMap.end())
        return false;

    m_SceneManageMap.insert(std::pair<const char*, CScene*>(id, scene));
}

void CSceneManage::EraseScene(const char* id)
{
    if (id == nullptr)
        return;
    std::map<const char*, CScene*>::iterator it;
    it = m_SceneManageMap.find(id);
    if (it == m_SceneManageMap.end())
        return ;
    delete it->second;
    m_SceneManageMap.erase(it);
}

CScene* CSceneManage::GetScene(const char* id)
{
    if (id == nullptr)
        return nullptr;
    std::map<const char*, CScene*>::iterator it;
    it = m_SceneManageMap.find(id);
    if (it == m_SceneManageMap.end())
        return nullptr;
    return it->second;
}

void CSceneManage::ClearScene()
{
    std::map<const char*, CScene*>::iterator it;
    for (it = m_SceneManageMap.begin(); it != m_SceneManageMap.end(); ++it)
        delete it->second;
    m_SceneManageMap.clear();
}
