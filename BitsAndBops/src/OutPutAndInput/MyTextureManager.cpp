#include "MyTextureManager.h"
#include "FreeImage.h"


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

