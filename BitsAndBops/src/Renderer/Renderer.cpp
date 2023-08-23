#include "Renderer.h"
#include "Texture.h"
#include "Core/FrameWork.h"
#include "TextureManager.h"
#include "Tools/Utils.h"
#include <Windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <cassert>

using namespace Gdiplus;

struct RendererData
{
	HDC MainDC;
	HDC BackDC;
	int ClientWidth;
	int ClientHeight;
    HWND WindowHandle;
    ULONG_PTR GdiplusToken;

    Gdiplus::Matrix* Transform;
    Gdiplus::Graphics* Graphics;
};
//特殊单例方式
 RendererData s_Data;

void Renderer::Init()
{
 
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    // Initialize GDI+.
    GdiplusStartup(&s_Data.GdiplusToken, &gdiplusStartupInput, NULL);

    CFrameWork* framework = CFrameWork::GetFrameWork();
    s_Data.WindowHandle = framework->GetHWND();
    s_Data.MainDC = GetDC(framework->GetHWND());
    s_Data.ClientWidth = framework->GetClientW();
    s_Data.ClientHeight = framework->GetClientH();
    //BackDC与MainDC的数据一样
    s_Data.BackDC = CreateCompatibleDC(s_Data.MainDC);
    //位图-将两个DC中的位图选入相同大小-删除原本的位图
    HBITMAP bmp = CreateCompatibleBitmap(s_Data.MainDC, s_Data.ClientWidth, s_Data.ClientHeight);
    DeleteObject(SelectObject(s_Data.BackDC, bmp));
    DeleteObject(bmp);
    //开启高级模式
    SetGraphicsMode(s_Data.BackDC, GM_ADVANCED);

    s_Data.Graphics = Gdiplus::Graphics::FromHDC(s_Data.BackDC);
    s_Data.Transform = new Gdiplus::Matrix;

    TextureManager::Init();

}

void Renderer::Shutdown()
{
    TextureManager::Shutdown();

    delete s_Data.Graphics;

    ReleaseDC(s_Data.WindowHandle,s_Data.BackDC);
    ReleaseDC(s_Data.WindowHandle, s_Data.MainDC);

    GdiplusShutdown(s_Data.GdiplusToken);
}

void Renderer::Clear(float r, float g, float b)
{
    s_Data.Graphics->Clear(Color((int)(r * 255.0f), (int)(g * 255.0f), (int)(b * 255.0f)));
}

void Renderer::DrawTexture(const Texture* texture, float x, float y, float width, float height, float rotation, float pivotX, float pivotY)
{
    Image* image = texture->GetGdiImage();
    s_Data.Transform->Reset();
    s_Data.Transform->Translate(x, y);
    s_Data.Transform->Rotate(rotation);
    s_Data.Transform->Scale(width, height);
    s_Data.Transform->Translate(-pivotX, -pivotY);
    s_Data.Graphics->SetTransform(s_Data.Transform);
    s_Data.Graphics->DrawImage(image,0.0f,0.0f,1.0f,1.0f);
}

void Renderer::DrawTexture(const std::string& id, float x, float y, float width, float height, float rotation, float pivotX, float pivotY)
{
    Texture* texture = TextureManager::GetTexture(id);
    assert(texture != nullptr);
    Renderer::DrawTexture(texture, x, y, width, height, rotation, pivotX, pivotY);
}

void Renderer::DrawTex(std::string str, float x, float y, float w, float h, float r,float g ,float b)
{
    std::wstring wstr = Utils::utf8_to_wstring(str);
     
    FontFamily   fontFamily(L"Arial");
    Font         font(&fontFamily, 12, FontStyleBold, UnitPoint);
    RectF        rectF(x, y, w, h);
    SolidBrush   solidBrush(Color(255, r*255.0f, g*255.0f, b*255.0f));

    s_Data.Graphics->DrawString(wstr.c_str(), -1, &font, rectF, NULL, &solidBrush);

    Pen pen(Color(255, 0, 0, 0));
    //s_Data.Graphics->DrawRectangle(&pen, rectF);
}

void Renderer::SwapBuffers()
{
    BitBlt(s_Data.MainDC, 0, 0, s_Data.ClientWidth, s_Data.ClientHeight, s_Data.BackDC, 0, 0, SRCCOPY);
}
