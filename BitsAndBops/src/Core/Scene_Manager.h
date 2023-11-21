#pragma once
#include <map>

class CScene;

class CSceneManage
{
	std::map<const char*, CScene*> m_SceneManageMap;
public:
	bool AddScene(const char* id, CScene* scene);
	void EraseScene(const char* id);
	void ClearScene();
	CScene* GetScene(const char* id);
};
