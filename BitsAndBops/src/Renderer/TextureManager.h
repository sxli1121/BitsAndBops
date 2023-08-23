#pragma once
#include <string>
class Texture;
class TextureManager
{
public:

	static void Init();
	static void Shutdown();

	static Texture* Load(const std::string& id, const wchar_t* fileName);      //º”‘ÿÕº∆¨
	static Texture* GetTexture(const std::string& id);
	static void Unload(const std::string& id);
	static void UnloadAll();

};

