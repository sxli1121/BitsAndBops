#include "MyTextureManager.h"
#include "FreeImage.h"


MyTextureManager::MyTextureManager()
{
	//FreeImage�ľ�̬���ͷ�ļ��л��������
#ifdef FREEIMAGE_LIB
	FreeImage_Initialise();//ֻ��ʹ�þ�̬���ʱ��Ҫ���������ĳ�ʼ��
#endif
	mDC = nullptr;
}

MyTextureManager::~MyTextureManager()
{
	ClearAllImage();
}

MyTextureManager& MyTextureManager::Instance()
{
	//C++11�Ժ��Ѿ�����˶��߳��оֲ���̬�����İ�ȫ����
	static MyTextureManager _instance;
	return _instance;
}

void MyTextureManager::Init(HDC _dc)
{
	
	mDC = _dc;
}

HDC MyTextureManager::LoadImg(const char* imgname, bool FlipVertical/*�Ƿ�ͼƬ���еߵ�*/)
{
	if (imgname == nullptr) { return nullptr; }
	if (mDC == nullptr) {
		printf("���ȳ�ʼ��DC\n");
		return nullptr;
	}
	
	//�ж��Ƿ��Ѿ�����------
	//mImgs.count(imgname);//�������ֻ�ܸ������Ǵ����ԣ����ܵõ��������Ϣ
	auto itr = mImgs.find(imgname);
	if (itr != mImgs.end())
	{
		return itr->second;//����Ѿ��������˾ͷ����Ѿ����صĽ�������ظ�����
	}

	//������-��ʼ����-------
	//������һ��ͼƬ��ʽ��FREE_IMAGE_FORMAT�� �ı��� fif;
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//���ͼƬ�ɹ����أ���ôdib����һ��ָ��ͼƬ��ָ�����
	FIBITMAP* dib = nullptr;
	//ָ��ͼƬ���ݵ�ָ�����
	BYTE* bits = nullptr;
	//����ͼƬ�Ŀ��
	unsigned int width = 0, height = 0;

	//���Դ��ļ�ͷǩ����ȡͼƬ�ĸ�ʽ
	fif = FreeImage_GetFileType(imgname, 0);
	//�����������ʧ�ܣ���ô���Դ��ļ���չ���²�ͼƬ�ĸ�ʽ
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(imgname);
	//������ǲ��ܵõ���֧�ֵĸ�ʽ�����ؼ�
	if (fif == FIF_UNKNOWN)
		return nullptr;



	//����Ƿ�֧�ֶ�ȡ-------
	//���һ�¶����ĸ�ʽ�Ƿ�֧�ֶ�ȡ���ɹ��ͼ���
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, imgname);
	//�������ʧ�ܣ����ؼ�
	if (!dib)
		return nullptr;


	//���ݴ���Ĳ����ж��Ƿ���Ҫ��ͼƬ�����ݽ��еߵ�
	if (FlipVertical)
	{
		//FreeImage_FlipHorizontal(dib);//ˮƽ��ת
		FreeImage_FlipVertical(dib);//��ֱ��ת
	}

	//���ͼͼƬ�������Ƿ�ϸ�
	//��ȡͼƬ������
	bits = FreeImage_GetBits(dib);
	//��ȡͼƬ�Ŀ����Ϣ
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);

	//����������Ϣ��һһ��Ϊ0�Ͷ����ؼ�--(ͼƬ���ݡ����)
	if ((bits == 0) || (width == 0) || (height == 0))
	{
		FreeImage_Unload(dib);//��ΪLoad�����ǳɹ��ģ���������Ҫ�ͷ�
		return nullptr;
	}


	//��ȡͼƬ��λ���
	int bpp = FreeImage_GetBPP(dib);
	if (bpp!=32)
	{
		//��ͼƬת��Ϊ32λ��ʽ
		dib = FreeImage_ConvertTo32Bits(dib);
		bpp = FreeImage_GetBPP(dib);
		bits = FreeImage_GetBits(dib); 
	}

	//����32λλͼ
	HBITMAP bmp = CreateBitmap(width, height, 1, bpp, bits);
	//����һ������DC
	HDC memDC = CreateCompatibleDC(mDC);
	//��λͼ�����������ļ���DC��-ɾ���������λͼ-ɾ����������λͼ
	HBITMAP old = (HBITMAP)SelectObject(memDC, bmp);
	DeleteObject(old);
	DeleteObject(bmp);

	FreeImage_Unload(dib);
	dib = nullptr;
	bits = nullptr;

	//�൱�ڲ���Ĳ���
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
		return itr->second;//�ҵ���ͼƬ��Ӧ��HDC
	}
	//û���ҵ�������£����Լ���һ��
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

