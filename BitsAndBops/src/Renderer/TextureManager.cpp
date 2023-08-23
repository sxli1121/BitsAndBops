#include "TextureManager.h"
#include "Texture.h"

#include <unordered_map>
#include <cassert>

struct TextureManagerData
{
	std::unordered_map<std::string, Texture*> TextureMap;
};

//ÌØÊâµ¥Àý
TextureManagerData s_Data;

void TextureManager::Init()
{

}

void TextureManager::Shutdown()
{
	UnloadAll();
}

Texture* TextureManager::Load(const std::string& id, const wchar_t* fileName)
{
	assert(GetTexture(id) == nullptr);

	Texture* texture = Texture::Load(fileName);
	assert(texture != nullptr);

	s_Data.TextureMap[id] = texture;

	return texture;
}

Texture* TextureManager::GetTexture(const std::string& id)
{
	auto it = s_Data.TextureMap.find(id);
	if (it == s_Data.TextureMap.end()) return nullptr;

	return it->second;
}

void TextureManager::Unload(const std::string& id)
{
	auto it = s_Data.TextureMap.find(id);
	assert(it != s_Data.TextureMap.end());

	delete it->second;

	s_Data.TextureMap.erase(it);
}

void TextureManager::UnloadAll()
{
	
	for (auto it : s_Data.TextureMap)   
	{
		delete it.second;
	}
	s_Data.TextureMap.clear();
}
