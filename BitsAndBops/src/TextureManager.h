//**********************************************
//Singleton Texture Manager class
//Written by Ben English
//benjamin.english@oit.edu
//
//For use with OpenGL and the FreeImage library
//**********************************************

#ifndef TextureManager_H
#define TextureManager_H

#include <windows.h>
//#include <gl/gl.h>
//#include "FreeImage.h"
#include <map>
#include <string>


//class TextureManager
//{
//public:
//	static TextureManager* Inst();
//	virtual ~TextureManager();
//
//	//load a texture an make it the current texture
//	//if texID is already in use, it will be unloaded and replaced with this texture
//	bool LoadTexture(const char* filename,	//where to load the file from
//		const unsigned int texID,			//arbitrary id you will reference the texture by
//											//does not have to be generated with glGenTextures
//		GLenum image_format = GL_RGB,		//format the image is in
//		GLint internal_format = GL_RGB,		//format to store the image in
//		GLint level = 0,					//mipmapping level
//		GLint border = 0);					//border size
//
//	//free the memory for a texture
//	bool UnloadTexture(const unsigned int texID);
//
//	//set the current texture
//	bool BindTexture(const unsigned int texID);
//
//	//free all texture memory
//	void UnloadAllTextures();
//
//protected:
//	TextureManager();
//	TextureManager(const TextureManager& tm);
//	TextureManager& operator=(const TextureManager& tm);
//
//	static TextureManager* m_inst;
//	std::map<unsigned int, GLuint> m_texID;
//};

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