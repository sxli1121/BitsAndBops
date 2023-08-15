#include "GameOutput.h"
#include "Core/FrameWork.h"
#include "Math/Matrix.h"
//#include "CObject.h"
#include "TextureManager.h"
#include "Camera.h"

#include <cassert>

CGameOutput* CGameOutput::game_output  = nullptr;

CGameOutput::CGameOutput()
{
    m_MainDC = nullptr;
    //m_Tag = 0;
}
CGameOutput::CGameOutput(const CGameOutput& that)
{
}

CGameOutput* CGameOutput::GetGameOutput()
{
    if (game_output == nullptr)
        game_output = new CGameOutput;
    return game_output;
}

void CGameOutput::Init()
{
    //创建DC-(框架负责制定DC的大小与句柄)
    assert(m_MainDC == nullptr);
    CFrameWork* framework = CFrameWork::GetFrameWork();
    m_MainDC = GetDC(framework->GetHWND());
    m_ClientW = framework->GetClientW();
    m_ClientH = framework->GetClientH();
    //BackDC与MainDC的数据一样
    m_BackDC = CreateCompatibleDC(m_MainDC);
    //位图-将两个DC中的位图选入相同大小-删除原本的位图
    HBITMAP bmp = CreateCompatibleBitmap(m_MainDC, m_ClientW, m_ClientH);
    DeleteObject(SelectObject(m_BackDC, bmp));
    DeleteObject(bmp);
    //开启高级模式
    SetGraphicsMode(m_BackDC, GM_ADVANCED);
}

bool CGameOutput::AddImg(const char* id, const char* fn)
{
    //路径与key为空判断
    assert(id != nullptr || fn != nullptr || id[0] != '-' );
    std::string str = id;
    //key重复判断
    assert(m_ImgMap.find(str) == m_ImgMap.end());

    //选入DC 创建兼容DC并返回
    MyTextureManager::Instance().Init(m_BackDC);
    HDC dc = MyTextureManager::Instance().LoadImg(fn);

    //DC入映射
    m_ImgMap.insert(std::pair<const char*, HDC>(id, dc));
    return true;
}

bool CGameOutput::EraseImg(const char* id)
{
    assert(id != nullptr);
    std::map<std::string, HDC>::iterator it;
    std::string str = id;
    it = m_ImgMap.find(str);

    assert(it != m_ImgMap.end());
    /*if (it == m_ImgMap.end())
        return false;*/
    DeleteObject(it->second);
    m_ImgMap.erase(it);

    return true;
}

bool CGameOutput::AddPic(const char* bmpkey, const char* imgkey, int sx, int sy, int pw, int ph)
{
    //为空
    assert(bmpkey != nullptr && imgkey != nullptr);
    std::string str = bmpkey;
    //pic不重复
    assert(m_PicMap.find(str) == m_PicMap.end());
    //img存在
    std::map<std::string, HDC>::iterator it;
    str = imgkey;
    it = m_ImgMap.find(str);
    assert(it != m_ImgMap.end());

    str = bmpkey;
    PIC bmp;
    bmp.dc = it->second;
    bmp.sx = sx;
    bmp.sy = sy;
    bmp.pw = pw;
    bmp.ph = ph;
    m_PicMap.insert(std::pair<std::string, PIC>(str, bmp));
    return true;
}


bool CGameOutput::AddBmp(const char* key, PIC bmp)
{
    assert(key != nullptr);
    //检测 key 是否重复
    std::string str = key; 
    assert(m_PicMap.find(str) == m_PicMap.end());
   
    m_PicMap.insert(std::pair<std::string, PIC>(str, bmp));
    return true;
}

void CGameOutput::Clear()
{
    m_PicMap.clear();
    std::map<std::string, HDC>::iterator it;
    for (it = m_ImgMap.begin(); it != m_ImgMap.end(); ++it)
        DeleteObject(it->second);
    m_ImgMap.clear();
}

void CGameOutput::DrawLine(float x1, float y1, float x2, float y2, int w, unsigned int c)
{
    HPEN np = 0;
    HPEN op = 0;

    if (w < 1)
        return;
    if (w != 1 || c != 0)
    {
        np = CreatePen(PS_SOLID, w, c);
        op = (HPEN)SelectObject(m_BackDC, np);
    }
    MoveToEx(m_BackDC, x1, y1, 0);
    LineTo(m_BackDC, x2, y2);
    if (np)
    {
        SelectObject(m_BackDC, op);
        DeleteObject(np);
    }
}

//一般在测试环境
void CGameOutput::DrawRect(float x, float y, float w, float h, int pw, unsigned int pc)
{
    HPEN np = 0;
    HPEN op = 0;
    if (pw < 1 || w < 1 || h < 1)
        return;
    if (pw != 1 || pc != 0)
    {
        np = CreatePen(PS_SOLID, pw, pc);
        op = (HPEN)SelectObject(m_BackDC, np);
    }
    float L = x;
    float R = L + w - 1;
    float T = y;
    float B = T + h - 1;
    MoveToEx(m_BackDC, L, T, 0);
    LineTo(m_BackDC, R, T);

    MoveToEx(m_BackDC, R, T, 0);
    LineTo(m_BackDC, R, B);

    MoveToEx(m_BackDC, L, B, 0);
    LineTo(m_BackDC, R, B);

    MoveToEx(m_BackDC, L, T, 0);
    LineTo(m_BackDC, L, B);
    if (np)
    {
        SelectObject(m_BackDC, op);
        DeleteObject(np);
    }
 
}


void CGameOutput::SetFont(int w, int h)
{
    if (w < 1)
        w = 15;
    if (h < 1)
        h = 15;
    //创建字体 HFONT 句柄 内存中的一个字体对象-CreateFontA 函数创建画笔
    HFONT font = CreateFontA(h,w,0,0,400,0,0,0,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "宋体");
    DeleteObject(SelectObject(m_BackDC, font));
}

void CGameOutput::DrawTxt(int x, int y, const char* string,unsigned int color)
{
    assert(string != 0);
    INAGE_SOURCE_STRING str;
    str.str = string;
    str.c = color;
    str.x = x;
    str.y = y;
    m_Txt.push_back(str); 

   // //设置文字颜色-给HDC设置文字颜色
   // unsigned int  fc = SetTextColor(m_BackDC, color);
   // TextOutA(m_BackDC, x, y, string, len);
   // //绘制文字   HDC   输出的文字   文字长度  文字范围   文字形式
   //// DrawTextA(m_BackDC, i2->buf, i2->len, &r, DT_WORDBREAK);
   // //在哪个画布 绘制什么字体的颜色
   // SetTextColor(m_BackDC, fc);
}

void CGameOutput::DrawPic(const char* key, Matrix33* m, int level)
{
    assert(key != nullptr);
   //存在
    std::map<std::string, PIC>::iterator bit;
    std::string str = key;
    bit = m_PicMap.find(str);
    assert(bit != m_PicMap.end());

    Matrix33 cameraMatrix;
    m_camera.CameraMove(10,10);
    m_camera.SetCameraMatrix();
    cameraMatrix = m_camera.GetCameraMatrix();
    
    LAYER_BMP  tbmp;
    tbmp.Pic = &bit->second;
 
    
    assert(tbmp.Pic != 0);

   //世界坐标转换为窗口坐标
    XFORM xm;
    xm.eM11 = 1;
    xm.eM22 = 1;
    xm.eM12 = 0;
    xm.eM21 = 0;
 /*   xm.eDx = -m_ClientW;
    xm.eDy = -m_ClientH;*/
 
    xm.eDx = 0;
    xm.eDy = 0;

    tbmp.Matrix.eM11 = m->eM11 * xm.eM11 + m->eM12 * xm.eM21 + 0 * xm.eDx;
    tbmp.Matrix.eM12 = m->eM11 * xm.eM12 + m->eM12 * xm.eM22 + 0 * xm.eDy;
    //eM13 = 0;
    tbmp.Matrix.eM21 = m->eM21 * xm.eM11 + m->eM22 * xm.eM21 + 0 * xm.eDx;
    tbmp.Matrix.eM22 = m->eM21 * xm.eM12 + m->eM22 * xm.eM22 + 0 * xm.eDy;
    //eM23 = 0;
    tbmp.Matrix.eDx = m->eDx * xm.eM11 + m->eDy * xm.eM21 + 1 * xm.eDx;
    tbmp.Matrix.eDy = m->eDx * xm.eM12 + m->eDy * xm.eM22 + 1 * xm.eDy;

    tbmp.Matrix = *m * cameraMatrix;

    switch (level)
    {
    case LEVEL1:m_LevelBmp1.push_back(tbmp); break;
    case LEVEL2:m_LevelBmp2.push_back(tbmp); break;
    case LEVEL3:m_LevelBmp3.push_back(tbmp); break;
    }

    SetWorldTransform(m_BackDC, &xm);
}

void CGameOutput::DrawDistantView(const char* key, float x, float y, int level, float sx, float sy)
{
    assert(key != nullptr);
    //检测 key 是否能找到
    std::map<std::string, PIC>::iterator bit;
    std::string str = key;
    bit = m_PicMap.find(str);
    assert(bit != m_PicMap.end());

    //用图层的结构体记录找到的bmp key
    LAYER_BMP  tbmp;
    tbmp.Pic= &bit->second;
    tbmp.Matrix.eDx = x;
    tbmp.Matrix.eDy = y;
    tbmp.Matrix.eM11 = sx;
    tbmp.Matrix.eM22 = sy;

    assert(tbmp.Pic->dc != 0);
    switch (level)
    {
    case DISTANT_VIEW1:m_DistantViewBmp1.push_back(tbmp); break;
    case DISTANT_VIEW2:m_DistantViewBmp2.push_back(tbmp); break;
    }
}

void CGameOutput::DrawFront(const char* key, float x, float y, int level, float sx, float sy)
{
    assert(key != nullptr);
    //检测 key 是否能找到
    std::map<std::string, PIC>::iterator bit;
    std::string str = key;
    bit = m_PicMap.find(str);
    assert(bit != m_PicMap.end());

    //用图层的结构体记录找到的bmp key
    LAYER_BMP  tbmp;
    tbmp.Pic = &bit->second;
    tbmp.Matrix.eDx = x;
    tbmp.Matrix.eDy = y;
    tbmp.Matrix.eM11 = sx;
    tbmp.Matrix.eM22 = sy;

    assert(tbmp.Pic->dc != 0);
    switch (level)
    {
    case DISTANT_VIEW1:m_FrontBmp1.push_back(tbmp); break;
    case DISTANT_VIEW2:m_FrontBmp2.push_back(tbmp); break;
    }
}

void CGameOutput::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3,unsigned int color)
{
    POINT point[3];
    point[0].x = x1;
    point[0].y = y1;
    point[1].x = x2;
    point[1].y = y2;
    point[2].x = x3;
    point[2].y = y3;
    HBRUSH newbrush = CreateSolidBrush(color);
    HBRUSH oldbrush;
    oldbrush = (HBRUSH) SelectObject(m_BackDC, newbrush);
    Polygon(m_BackDC, point, 3);
    DeleteObject(SelectObject(m_BackDC, oldbrush));
}

void CGameOutput::Begin()
{
    //清空后备设备为白色
    BitBlt(m_BackDC, 0, 0, m_ClientW, m_ClientW, 0, 0, 0, WHITENESS);
    m_DistantViewBmp1.clear();
    m_DistantViewBmp2.clear();
    m_LevelBmp1.clear();
    m_LevelBmp2.clear();
    m_LevelBmp3.clear();
    m_FrontBmp1.clear();
    m_FrontBmp2.clear();
    m_UiBmp.clear();
    m_ImageSourceBmp.clear();
    m_Txt.clear();
}

void CGameOutput::End()
{

    //if (m_Tag)
    //{
    //    m_ClientX = m_Tag->GetX();
    //    m_ClientY = m_Tag->GetY();
    //}
    PIC* bmp;
    XFORM* m;
    //绘制远景
    int len = m_DistantViewBmp1.size();
    for (int i = 0; i < len; i++)
    {
        bmp = m_DistantViewBmp1[i].Pic;
        m = &m_DistantViewBmp1[i].Matrix;
        //(m->eDx - m_cx)* m->eM11   绘制位置 - 窗口的位置 * 系数  代表画在窗口中的时候 窗口位置也需要对应调整
        DrawAlpha(m_BackDC, bmp->dc, m->eDx - m_ClientX * m->eM11, m->eDy - m_ClientY * m->eM22,
            bmp->pw, bmp->ph, bmp->sx, bmp->sy, bmp->pw, bmp->ph, 255);

      
        XFORM xm;
        xm.eM11 = 1;
        xm.eM22 = 1;
        xm.eM12 = 0;
        xm.eM21 = 0;
        xm.eDx = 0;
        xm.eDy = 0;
        SetWorldTransform(m_BackDC, &xm);
    }

    len = m_DistantViewBmp2.size();
    for (int i = 0; i < len; i++)
    {
        bmp = m_DistantViewBmp2[i].Pic;
        m = &m_DistantViewBmp2[i].Matrix;
        DrawAlpha(m_BackDC, bmp->dc, m->eDx - m_ClientX * m->eM11, m->eDy - m_ClientY * m->eM22,
            bmp->pw, bmp->ph, bmp->sx, bmp->sy, bmp->pw, bmp->ph, 255);
        //TransparentBlt(m_BackDC, m->eDx - m_cx * m->eM11, m->eDy - m_cy * m->eM22,
        //    bmp->pw, bmp->ph, bmp->dc, bmp->sx, bmp->sy, bmp->pw, bmp->ph/*, bmp->c*/);
        XFORM xm;
        xm.eM11 = 1;
        xm.eM22 = 1;
        xm.eM12 = 0;
        xm.eM21 = 0;
        xm.eDx = 0;
        xm.eDy = 0;
        SetWorldTransform(m_BackDC, &xm);
    }

    //绘制逻辑层
    len = m_LevelBmp1.size();
    for (int i = 0; i < len; i++)
    {
        bmp = m_LevelBmp1[i].Pic;
        m = &m_LevelBmp1[i].Matrix;
        SetWorldTransform(m_BackDC, &m_LevelBmp1[i].Matrix);
        DrawAlpha(m_BackDC, bmp->dc, 0, 0,
            bmp->pw, bmp->ph, bmp->sx, bmp->sy, bmp->pw, bmp->ph, 255);
        XFORM xm;
        xm.eM11 = 1;
        xm.eM22 = 1;
        xm.eM12 = 0;
        xm.eM21 = 0;
        xm.eDx = 0;
        xm.eDy = 0;
        SetWorldTransform(m_BackDC, &xm);
    }

    len = m_LevelBmp2.size();
    for (int i = 0; i < len; i++)
    {
        bmp = m_LevelBmp2[i].Pic;
        m = &m_LevelBmp2[i].Matrix;
        SetWorldTransform(m_BackDC, &m_LevelBmp2[i].Matrix);
        DrawAlpha(m_BackDC, bmp->dc,0,0,
            bmp->pw, bmp->ph, bmp->sx, bmp->sy, bmp->pw, bmp->ph, 255);
       /* TransparentBlt(m_BackDC, -bmp->pw / 2, -bmp->ph / 2,
            bmp->pw, bmp->ph, bmp->dc, bmp->sx, bmp->sy, bmp->pw, bmp->ph, bmp->c);*/
        XFORM xm;
        xm.eM11 = 1;
        xm.eM22 = 1;
        xm.eM12 = 0;
        xm.eM21 = 0;
        xm.eDx = 0;
        xm.eDy = 0;
        SetWorldTransform(m_BackDC, &xm);
    }

    len = m_LevelBmp3.size();
    for (int i = 0; i < len; i++)
    {
        bmp = m_LevelBmp3[i].Pic;
        m = &m_LevelBmp3[i].Matrix;
        SetWorldTransform(m_BackDC, &m_LevelBmp3[i].Matrix);
        DrawAlpha(m_BackDC, bmp->dc, 0, 0,
            bmp->pw, bmp->ph, bmp->sx, bmp->sy, bmp->pw, bmp->ph, 255);
        XFORM xm;
        xm.eM11 = 1;
        xm.eM22 = 1;
        xm.eM12 = 0;
        xm.eM21 = 0;
        xm.eDx = 0;
        xm.eDy = 0;
        SetWorldTransform(m_BackDC, &xm);
    }

    //绘制前景
    len = m_FrontBmp1.size();
    for (int i = 0; i < len; i++)
    {
        bmp = m_FrontBmp1[i].Pic;
        m = &m_FrontBmp1[i].Matrix;
        DrawAlpha(m_BackDC, bmp->dc, 0, 0,
            bmp->pw, bmp->ph, bmp->sx, bmp->sy, bmp->pw, bmp->ph, 255);
    }

    len = m_FrontBmp2.size();
    for (int i = 0; i < len; i++)
    {
        bmp = m_FrontBmp2[i].Pic;
        m = &m_FrontBmp2[i].Matrix;
        DrawAlpha(m_BackDC, bmp->dc, 0, 0,
            bmp->pw, bmp->ph, bmp->sx, bmp->sy, bmp->pw, bmp->ph, 255);
    }

    BitBlt(m_MainDC, 0, 0, m_ClientW, m_ClientH, m_BackDC, 0, 0, SRCCOPY);
}

void CGameOutput::SetClientXY(float cx, float cy)
{
//    if (//m_Tag == 0)
//    {
//        m_ClientX = cx;
//        m_ClientY = cy;
//    }
}

void CGameOutput::SetTag(const CObject* tag)
{
    //为0 没有跟随对象
    //m_Tag = tag;
}



void CGameOutput::DrawAlpha(HDC _dest, HDC _picdc, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh, unsigned char alpha)
{
    BLENDFUNCTION bf = { 0 };
    //BLENDFUNCTION 结构体变量做为函数参数，用于AlphaBlend函数进行Alpha的融合
    bf.BlendOp = AC_SRC_OVER;
    bf.BlendFlags = 0;
    bf.AlphaFormat = AC_SRC_ALPHA;
    bf.SourceConstantAlpha = alpha;
    AlphaBlend(m_BackDC, dx, dy, dw, dh, _picdc, sx, sy, sw, sh, bf);
}

void CGameOutput::DrawBmp(HDC _dest, HDC _picdc, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh, DWORD transcolor)
{
    TransparentBlt(_dest, dx, dy, dw, dh, _picdc, sx, sy, sw, sh, transcolor);
}