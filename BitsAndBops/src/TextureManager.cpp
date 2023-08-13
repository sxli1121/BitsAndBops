//**********************************************
//Singleton Texture Manager class
//Written by Ben English
//benjamin.english@oit.edu
//
//For use with OpenGL and the FreeImage library
//**********************************************

#include "TextureManager.h"
#include "FreeImage.h"


//TextureManager* TextureManager::m_inst(0);
//
//TextureManager* TextureManager::Inst()
//{
//	if(!m_inst)
//		m_inst = new TextureManager();
//
//	return m_inst;
//}
//
//TextureManager::TextureManager()
//{
//	// call this ONLY when linking with FreeImage as a static library
//	#ifdef FREEIMAGE_LIB
//		FreeImage_Initialise();
//	#endif
//}
//
////these should never be called
////TextureManager::TextureManager(const TextureManager& tm){}
////TextureManager& TextureManager::operator=(const TextureManager& tm){}
//	
//TextureManager::~TextureManager()
//{
//	// call this ONLY when linking with FreeImage as a static library
//	#ifdef FREEIMAGE_LIB
//		FreeImage_DeInitialise();
//	#endif
//
//	UnloadAllTextures();
//	m_inst = 0;
//}

//bool TextureManager::LoadTexture(const char* filename, const unsigned int texID, GLenum image_format, GLint internal_format, GLint level, GLint border)
//{
//	//image format
//	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
//	//pointer to the image, once loaded
//	FIBITMAP *dib(0);
//	//pointer to the image data
//	BYTE* bits(0);
//	//image width and height
//	unsigned int width(0), height(0);
//	//OpenGL's image ID to map to
//	GLuint gl_texID;
//	
//	//check the file signature and deduce its format
//	fif = FreeImage_GetFileType(filename, 0);
//	//if still unknown, try to guess the file format from the file extension
//	if(fif == FIF_UNKNOWN) 
//		fif = FreeImage_GetFIFFromFilename(filename);
//	//if still unkown, return failure
//	if(fif == FIF_UNKNOWN)
//		return false;
//
//	//check that the plugin has reading capabilities and load the file
//	if(FreeImage_FIFSupportsReading(fif))
//		dib = FreeImage_Load(fif, filename);
//	//if the image failed to load, return failure
//	if(!dib)
//		return false;
//
//	//retrieve the image data
//	bits = FreeImage_GetBits(dib);
//	//get the image width and height
//	width = FreeImage_GetWidth(dib);
//	height = FreeImage_GetHeight(dib);
//	//if this somehow one of these failed (they shouldn't), return failure
//	if((bits == 0) || (width == 0) || (height == 0))
//		return false;
//	
//	//if this texture ID is in use, unload the current texture
//	if(m_texID.find(texID) != m_texID.end())
//		glDeleteTextures(1, &(m_texID[texID]));
//
//	//generate an OpenGL texture ID for this texture
//	glGenTextures(1, &gl_texID);
//	//store the texture ID mapping
//	m_texID[texID] = gl_texID;
//	//bind to the new texture ID
//	glBindTexture(GL_TEXTURE_2D, gl_texID);
//	//store the texture data for OpenGL use
//	glTexImage2D(GL_TEXTURE_2D, level, internal_format, width, height,
//		border, image_format, GL_UNSIGNED_BYTE, bits);
//
//	//Free FreeImage's copy of the data
//	FreeImage_Unload(dib);
//
//	//return success
//	return true;
//}

//bool TextureManager::UnloadTexture(const unsigned int texID)
//{
//	bool result(true);
//	//if this texture ID mapped, unload it's texture, and remove it from the map
//	if(m_texID.find(texID) != m_texID.end())
//	{
//		glDeleteTextures(1, &(m_texID[texID]));
//		m_texID.erase(texID);
//	}
//	//otherwise, unload failed
//	else
//	{
//		result = false;
//	}
//
//	return result;
//}

//bool TextureManager::BindTexture(const unsigned int texID)
//{
//	bool result(true);
//	//if this texture ID mapped, bind it's texture as current
//	if(m_texID.find(texID) != m_texID.end())
//		glBindTexture(GL_TEXTURE_2D, m_texID[texID]);
//	//otherwise, binding failed
//	else
//		result = false;
//
//	return result;
//}
//
//void TextureManager::UnloadAllTextures()
//{
//	//start at the begginning of the texture map
//	std::map<unsigned int, GLuint>::iterator i = m_texID.begin();
//
//	//Unload the textures untill the end of the texture map is found
//	while(i != m_texID.end())
//		UnloadTexture(i->first);
//
//	//clear the texture map
//	m_texID.clear();
//}

MyTextureManager::MyTextureManager()
{
	//FreeImage的静态库的头文件中会有这个宏
#ifdef FREEIMAGE_LIB
	FreeImage_Initialise();//只有使用静态库的时候要进行这样的初始化
#endif
	mDC = nullptr;
}

MyTextureManager::~MyTextureManager()
{
	ClearAllImage();
}

MyTextureManager& MyTextureManager::Instance()
{
	//C++11以后已经解决了多线程中局部静态变量的安全问题
	static MyTextureManager _instance;
	return _instance;
}

void MyTextureManager::Init(HDC _dc)
{
	
	mDC = _dc;
}

HDC MyTextureManager::LoadImg(const char* imgname, bool FlipVertical/*是否将图片进行颠倒*/)
{
	if (imgname == nullptr) { return nullptr; }
	if (mDC == nullptr) {
		printf("请先初始化DC\n");
		return nullptr;
	}
	
	//判断是否已经存在------
	//mImgs.count(imgname);//这个函数只能告诉我们存在性，不能得到具体的信息
	auto itr = mImgs.find(imgname);
	if (itr != mImgs.end())
	{
		return itr->second;//如果已经被加载了就返回已经加载的结果避免重复加载
	}



	//不存在-开始加载-------
	//定义了一个图片格式（FREE_IMAGE_FORMAT） 的变量 fif;
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//如果图片成功加载，那么dib就是一个指向图片的指针变量
	FIBITMAP* dib = nullptr;
	//指向图片数据的指针变量
	BYTE* bits = nullptr;
	//定义图片的宽高
	unsigned int width = 0, height = 0;

	//尝试从文件头签名获取图片的格式
	fif = FreeImage_GetFileType(imgname, 0);
	//如果上述调用失败，那么尝试从文件扩展名猜测图片的格式
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(imgname);
	//如果还是不能得到受支持的格式，返回假
	if (fif == FIF_UNKNOWN)
		return nullptr;



	//检查是否支持读取-------
	//检查一下读到的格式是否被支持读取，成功就加载
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, imgname);
	//如果加载失败，返回假
	if (!dib)
		return nullptr;


	//根据传入的参数判断是否需要将图片的数据进行颠倒
	if (FlipVertical)
	{
		//FreeImage_FlipHorizontal(dib);//水平翻转
		FreeImage_FlipVertical(dib);//垂直翻转
	}

	//检查图图片的数据是否合格
	//获取图片的数据
	bits = FreeImage_GetBits(dib);
	//获取图片的宽高信息
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);

	//上述三个信息任一一个为0就都返回假--(图片数据、宽高)
	if ((bits == 0) || (width == 0) || (height == 0))
	{
		FreeImage_Unload(dib);//因为Load操作是成功的，所以这里要释放
		return nullptr;
	}


	//获取图片的位深度
	int bpp = FreeImage_GetBPP(dib);
	if (bpp!=32)
	{
		//将图片转换为32位格式
		dib = FreeImage_ConvertTo32Bits(dib);
		bpp = FreeImage_GetBPP(dib);
		bits = FreeImage_GetBits(dib); 
	}

	//创建32位位图
	HBITMAP bmp = CreateBitmap(width, height, 1, bpp, bits);
	//创建一个兼容DC
	HDC memDC = CreateCompatibleDC(mDC);
	//将位图拷贝到创建的兼容DC中-删除在外面的位图-删除挤出来的位图
	HBITMAP old = (HBITMAP)SelectObject(memDC, bmp);
	DeleteObject(old);
	DeleteObject(bmp);

	FreeImage_Unload(dib);
	dib = nullptr;
	bits = nullptr;

	//相当于插入的操作
	mImgs[imgname] = memDC;
	return memDC;
}

HDC MyTextureManager::GetImg(const char* imgname)
{
	if (imgname == nullptr) { return nullptr; }
	//std::map<std::string, HDC>::iterator itr = mImgs.find(imgname);
	auto itr = mImgs.find(imgname);
	if (itr != mImgs.end())
	{
		return itr->second;//找到的图片对应的HDC
	}
	//没有找到的情况下，尝试加载一下
	HDC dc = LoadImg(imgname);
	if (dc != nullptr)
	{
		return dc;
	}
	return nullptr;
}

void MyTextureManager::EraseImg(const char* imgname)
{
	if (imgname == nullptr) { return; }
	//std::map<std::string, HDC>::iterator itr = mImgs.find(imgname);
	auto itr = mImgs.find(imgname);
	if (itr != mImgs.end())
	{
		DeleteDC(itr->second);
		mImgs.erase(itr);
	}
}

void MyTextureManager::ClearAllImage()
{
	if (!mImgs.empty())
	{ 
		for (auto& img:mImgs)
		{
			DeleteDC(img.second);
		} 
		mImgs.clear();
	}
}
