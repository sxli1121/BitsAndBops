#include "Renderer.h"
#include "Texture.h"
#include "Core/FrameWork.h"
#include "TextureManager.h"

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

    Gdiplus::Graphics* Graphics;
};

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
    //TODO:
    // rotation,pivot etc..
    s_Data.Graphics->DrawImage(image, x, y, width, height);
}

void Renderer::DrawTexture(const std::string& id, float x, float y, float width, float height, float rotation, float pivotX, float pivotY)
{
    Texture* texture = TextureManager::GetTexture(id);
    assert(texture != nullptr);
    Renderer::DrawTexture(texture, x, y, width, height, rotation, pivotX, pivotY);
}

void Renderer::SwapBuffers()
{
    BitBlt(s_Data.MainDC, 0, 0, s_Data.ClientWidth, s_Data.ClientHeight, s_Data.BackDC, 0, 0, SRCCOPY);
}
