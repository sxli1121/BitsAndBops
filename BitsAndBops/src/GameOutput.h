#pragma once
#include <windows.h>
#pragma comment(lib, "msimg32.lib")
#include <map>
#include <string>
#include <vector>

#define BACK_GROUND     0
#define DISTANT_VIEW1   1
#define DISTANT_VIEW2   2
#define LEVEL1          3
#define LEVEL2          4
#define LEVEL3          5
#define FRONT1          6
#define FRONT2          7
#define IMAGE_SOURCE    9               //ͼԴ
#define UI              8                  

class CObject;

class CGO
{
	struct PIC
	{
		HDC dc;    	//ͼƬid
		int sx;		//ԭͼ��ʼ������
		int sy;
		int pw;		//��ͼƬ �� ��С
		int ph;
		//unsigned int c;		//Ҫȥ������ɫ��¼
	};
	////�Լ������DC���������������ͼƬdc
	//struct MDC
	//{
	//	HDC bmp_dc;
	//	int w;     //��¼�����Ŀ�ߡ�������ֱ��transparentbit����
	//	int h;
	//};
	

	
	//ͼ���bmp
	struct LAYER_BMP
	{
		PIC* Pic;              //--�����ҵ�struct _BMP�е�����
		XFORM m;                //������߼���-��Ͼ���//�����Զ����-����ӵ��λ���������������µ�ϵ��
		//unsigned int c;         //ͼԴʹ����ɫ

	};
	
	//ͼԴ-����
	struct INAGE_SOURCE_STRING
	{
		std::string str;
		int x;
		int y;
		unsigned int c;
	};
	
	HDC m_MainDC;
	HDC m_BackDC;
	int m_cw; 
	int m_ch;

	float m_cx;               //����λ��
	float m_cy;
	const CObject* m_tag;     //�������

	std::map<std::string, HDC> m_ImgMap;
	std::map<std::string, PIC> m_PicMap;



	std::vector<LAYER_BMP> m_DistantViewBmp1;
	std::vector<LAYER_BMP> m_DistantViewBmp2;
	std::vector<LAYER_BMP> m_LevelBmp1;
	std::vector<LAYER_BMP> m_LevelBmp2;
	std::vector<LAYER_BMP> m_LevelBmp3;
	std::vector<LAYER_BMP> m_FrontBmp1;
	std::vector<LAYER_BMP> m_FrontBmp2;
	std::vector<LAYER_BMP> m_UiBmp;
	std::vector<LAYER_BMP> m_ImageSourceBmp;
	std::vector<INAGE_SOURCE_STRING> m_Txt;

	CGO();
	CGO(const CGO& that);
	static CGO* p;

	//ͼƬpng
	void DrawAlpha(HDC _dest, HDC _picdc, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh,
		unsigned char alpha);
	//ͼƬbmp
	void DrawBmp(HDC _dest, HDC _picdc, int dx, int dy, int dw, int dh, int sx, int sy,//Դλ��
		int sw, int sh, DWORD transcolor);

public:
	static CGO* GetGO();
	void Init();
	bool AddImg(const char* id, const char* fn);
	void EraseImg(const char* id);

	bool AddPic(const char* bmpkey, const char* imgkey,
		int sx, int sy, int pw, int ph);
	//png
	//bool AddPng(const char* bmpkey, const char* imgkey,
	//	int sx, int sy, int pw, int ph);

	bool AddBmp(const char* key, PIC bmp);

	void Clear();
	//�߶�
	void DrawLine(float x1, float y1, float x2, float y2, 
		int w = 1, unsigned int c = RGB(0,0,0));
	//����
	void DrawRect(float x, float y, float w, float h,
		int pw = 1, unsigned int pc = RGB(0, 0, 0));
	//���û���
	void SetFont(int w = 15,int h = 15);
	//��������
	void DrawTxt(int x, int y, const char* string, unsigned int color);
	//ͼƬ
	void DrawPic(const char* key, const XFORM* m ,int level = LEVEL2);
	//Զ��
	void DrawDistantView(const char* key, float x, float y, int level = DISTANT_VIEW2,
		float sx=1.0f, float sy =1.0f);
	//����
	void DrawFront(const char* key, float x, float y, int level, float sx = 1.0f, float sy = 1.0f);
	//������
	void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color);
	void Begin();
	void End();
	//���ô���λ��
	void SetCXCy(float cx, float cy);
	//�������
	void SetTag(const CObject* tag);

	//����
};