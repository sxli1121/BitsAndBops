#ifndef TextureManager_H
#define TextureManager_H

#include <windows.h>
//#include <gl/gl.h>
//#include "FreeImage.h"
#include <map>
#include <string>

//纹理管理单例类
class MyTextureManager
{

private:
	MyTextureManager();
	//函数后面标记 = delete 表示该函数被删除，不能被相关的功能调用
	MyTextureManager(const MyTextureManager&) = delete;
	MyTextureManager& operator = (const MyTextureManager&) = delete;
public:
	~MyTextureManager();
	//单例接口
	static MyTextureManager& Instance();

	void Init(HDC _dc);
	HDC LoadImg(const char* imgname, bool FlipVertical = true);
	HDC GetImg(const char* imgname);
	void EraseImg(const char* imgname);
	void ClearAllImage();
protected:
	std::map<std::string, HDC> mImgs;
	HDC mDC = nullptr;
};
#endif