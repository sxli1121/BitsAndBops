#include "Renderer.h"
#include "Texture.h"
#include "Core/FrameWork.h"
#include "TextureManager.h"
#include "Tools/Utils.h"
#include "OutPutAndInput/Camera.h"

#include <Windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <cassert>

#include "Math/Math.h"

using namespace Gdiplus;

struct RendererData
{
	HDC MainDC;
	HDC BackDC;
	int ClientWidth;
	int ClientHeight;
    HWND WindowHandle;
    ULONG_PTR GdiplusToken;

    Matrix3f ViewportMatrix;
    Matrix3f ViewProjectionMatrix;

    Gdiplus::Matrix* Transform;
    Gdiplus::Graphics* Graphics;
};
//���ⵥ����ʽ
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
    //BackDC��MainDC������һ��
    s_Data.BackDC = CreateCompatibleDC(s_Data.MainDC);
    //λͼ-������DC�е�λͼѡ����ͬ��С-ɾ��ԭ����λͼ
    HBITMAP bmp = CreateCompatibleBitmap(s_Data.MainDC, s_Data.ClientWidth, s_Data.ClientHeight);
    DeleteObject(SelectObject(s_Data.BackDC, bmp));
    DeleteObject(bmp);
    //�����߼�ģʽ
    SetGraphicsMode(s_Data.BackDC, GM_ADVANCED);

    s_Data.Graphics = Gdiplus::Graphics::FromHDC(s_Data.BackDC);
    s_Data.Transform = new Gdiplus::Matrix;

    SetViewport(0, 0, s_Data.ClientWidth, s_Data.ClientHeight);

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

void Renderer::DrawTexture(const Texture* texture, float x, float y,float width, float height, float rotation, float pivotX, float pivotY)
{
    Image* image = texture->GetGdiImage();

    const Matrix3f localTransform = Matrix3f::Translate({x,y})
					* Matrix3f::Rotate(Math::Deg2Rad(rotation))
					* Matrix3f::Scale({width,height})
					* Matrix3f::Translate({ -pivotX, -pivotY });



    Matrix3f m = s_Data.ViewportMatrix * s_Data.ViewProjectionMatrix * localTransform;



    s_Data.Transform->Reset();
    s_Data.Transform->SetElements(m(0, 0), m(1, 0), m(0, 1), m(1, 1), m(0, 2), m(1, 2));

    s_Data.Graphics->SetTransform(s_Data.Transform);
    s_Data.Graphics->DrawImage(image,0.0f,0.0f,1.0f,1.0f);
}

void Renderer::DrawTexture(const std::string& id, float x, float y,float width, float height, float rotation, float pivotX, float pivotY)
{
    Texture* texture = TextureManager::GetTexture(id);
    assert(texture != nullptr);
    Renderer::DrawTexture(texture, x, y ,width, height, rotation, pivotX, pivotY);
}

void Renderer::DrawTex(std::string str, float x, float y, float w, float h, float r,float g ,float b)
{
    s_Data.Transform->Reset();
    s_Data.Graphics->SetTransform(s_Data.Transform);

    std::wstring wstr = Utils::utf8_to_wstring(str);
     
    FontFamily   fontFamily(L"Arial");
    Font         font(&fontFamily, 12, FontStyleBold, UnitPoint);
    RectF        rectF(x, y, w, h);
    SolidBrush   solidBrush(Color(255, r*255.0f, g*255.0f, b*255.0f));

    s_Data.Graphics->DrawString(wstr.c_str(), -1, &font, rectF, NULL, &solidBrush);
}

void Renderer::SetViewport(int x, int y, int width, int height)
{
    s_Data.ViewportMatrix = {
        (float)width,0,(float)x,
        0, (float)height,(float)y,
        0,0,1
    };
}

void Renderer::SetViewProjection(const Matrix3f& m)
{
    s_Data.ViewProjectionMatrix = m;

}

void Renderer::SwapBuffers()
{
    BitBlt(s_Data.MainDC, 0, 0, s_Data.ClientWidth, s_Data.ClientHeight, s_Data.BackDC, 0, 0, SRCCOPY);
}



