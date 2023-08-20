#ifndef TextureManager_H
#define TextureManager_H

#include <windows.h>
//#include <gl/gl.h>
//#include "FreeImage.h"
#include <map>
#include <string>

//�����������
class MyTextureManager
{

private:
	MyTextureManager();
	//���������� = delete ��ʾ�ú�����ɾ�������ܱ���صĹ��ܵ���
	MyTextureManager(const MyTextureManager&) = delete;
	MyTextureManager& operator = (const MyTextureManager&) = delete;
public:
	~MyTextureManager();
	//�����ӿ�
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