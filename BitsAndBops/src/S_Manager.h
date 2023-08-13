#pragma once
#include <map>
#include <string>
class CScene;
class CSM
{
	std::map<const char*, CScene*> m_sm;
public:
	bool AddScene(const char* id, CScene* p);
	void EraseScene(const char* id);

	CScene* GetScene(const char* id);

	void Clear();
};
