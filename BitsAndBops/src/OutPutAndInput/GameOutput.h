#pragma once
#include "Math/Matrix.h"
#include "Camera.h"
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
#define IMAGE_SOURCE    9               //图源
#define UI              8                  

class CObject;

class CGameOutput
{
private:
	struct PIC
	{
		HDC dc;           //图片id
		int sx;		      //原图起始点坐标
		int sy;	          
		int pw;		      //本图片 的 大小
		int ph;
		//unsigned int c;		//要去除的颜色记录
	};

	////自己创造的DC用来兼容做镜像的图片dc
	//struct MDC
	//{
	//	HDC bmp_dc;
	//	int w;     //记录画布的宽高——用来直接transparentbit镜像
	//	int h;
	//};
	
	//图层的bmp
	struct LAYER_BMP
	{
		PIC* Pic;              //--用来找到struct _BMP中的数据
		Matrix33 Matrix;        //如果是逻辑层-组合矩阵//如果是远景等-其中拥有位置坐标与左右上下的系数
		//unsigned int c;         //图源使用颜色
	};
	
	//图源-文字
	struct INAGE_SOURCE_STRING
	{
		std::string str;
		int x;
		int y;
		unsigned int c;
	};
	
	HDC m_MainDC;
	HDC m_BackDC;
	int m_ClientW;
	int m_ClientH;
	float m_ClientX;               //窗口位置
	float m_ClientY;
	//const CObject* m_Tag;     //跟随对象

	Camera m_Camera;
	Matrix33 m_ViewMatrix;

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

	static CGameOutput* game_output;
	CGameOutput();
	CGameOutput(const CGameOutput& that);

	//两种绘制-png/bmp
	void DrawAlpha(HDC _dest, HDC _picdc, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh,
		unsigned char alpha);
	void DrawBmp(HDC _dest, HDC _picdc, int dx, int dy, int dw, int dh, int sx, int sy,
		int sw, int sh, DWORD transcolor);
public:
	static CGameOutput* GetGameOutput();

	void Init();
	void Begin();
	void End();

	bool AddImg(const char* id, const char* fn);
	bool AddPic(const char* bmpkey, const char* imgkey,int sx, int sy, int pw, int ph);
	bool AddBmp(const char* key, PIC bmp);
	bool EraseImg(const char* id);
	void Clear();

	void DrawLine(float x1, float y1, float x2, float y2, int w = 1, unsigned int color = RGB(0,0,0));
	void DrawRect(float x, float y, float w, float h,int penw = 1, unsigned int pencolor = RGB(0, 0, 0));
	void DrawPic(const char* key, Matrix33* m ,int level = LEVEL2);
	void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color);
	void SetFont(int w = 15, int h = 15);    //设置画笔
	void DrawTxt(int x, int y, const char* string, unsigned int color);

	void DrawDistantView(const char* key, float x, float y, int level = DISTANT_VIEW2,
		float sx=1.0f, float sy =1.0f);
	void DrawFront(const char* key, float x, float y, int level, float sx = 1.0f, float sy = 1.0f);

	//void SetCameraMatrix();
	void SetClientXY(float cx, float cy);
	void SetTag(const CObject* tag);
};