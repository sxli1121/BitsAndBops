#include "Renderer.h"
#include "Texture.h"
#include "Core/FrameWork.h"
#include "TextureManager.h"
#include "Tools/Utils.h"
#include "OutPutAndInput/Camera.h"
#include "Math/Math.h"

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <cassert>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "windowscodecs.lib")

template<class T> void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

using namespace D2D1;

struct RendererData
{
    ID2D1Factory* Factory;
    ID2D1HwndRenderTarget* RenderTarget;
    IDWriteFactory* WriteFactory;
    int ClientWidth;
    int ClientHeight;
    HWND WindowHandle;

    Matrix3f ViewportMatrix;
    Matrix3f ViewProjectionMatrix;
};
//特殊单例方式
RendererData s_Data;

void Renderer::Init()
{
    CFrameWork* framework = CFrameWork::GetFrameWork();
    s_Data.WindowHandle = framework->GetHWND();
    s_Data.ClientWidth = framework->GetClientW();
    s_Data.ClientHeight = framework->GetClientH();

    D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &s_Data.Factory);
    DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&s_Data.WriteFactory));

    RECT rc;
    GetClientRect(s_Data.WindowHandle, &rc);

    D2D1_SIZE_U size = SizeU(rc.right - rc.left, rc.bottom - rc.top);

    s_Data.Factory->CreateHwndRenderTarget(
        RenderTargetProperties(),
        HwndRenderTargetProperties(s_Data.WindowHandle, size),
        &s_Data.RenderTarget
    );

    SetViewport(0, 0, s_Data.ClientWidth, s_Data.ClientHeight);

    TextureManager::Init();
}

void Renderer::Shutdown()
{
    TextureManager::Shutdown();

    SafeRelease(&s_Data.RenderTarget);
    SafeRelease(&s_Data.Factory);
}

void Renderer::Clear(float r, float g, float b)
{
    s_Data.RenderTarget->Clear(ColorF(r, g, b));
}

void Renderer::DrawTexture(const Texture* texture, float x, float y, 
    float width, float height, float rotation, float pivotX, float pivotY,const Matrix3f& local2World)
{
    ID2D1Bitmap* bitmap = texture->GetBitmap();

    const Matrix3f localTransform = Matrix3f::Translate({ x,y })
        * Matrix3f::Rotate(Math::Deg2Rad(rotation))
        * Matrix3f::Scale({ width,height })
        * Matrix3f::Translate({ -pivotX, -pivotY });

    Matrix3f m = s_Data.ViewportMatrix  * s_Data.ViewProjectionMatrix * local2World * localTransform;

    D2D1_MATRIX_3X2_F transform = {
        m(0, 0), m(1, 0),
        m(0, 1), m(1, 1),
        m(0, 2), m(1, 2)
    };

    s_Data.RenderTarget->SetTransform(transform);
    D2D1_RECT_F rect;
    rect.left = 0.0f;
    rect.right = 1.0f;
    rect.top = 0.0f;
    rect.bottom = 1.0f;

    s_Data.RenderTarget->DrawBitmap(bitmap,&rect);
}

void Renderer::DrawTexture(const std::string& id, float x, float y, float width, float height, float rotation, float pivotX, float pivotY)
{
    Texture* texture = TextureManager::GetTexture(id);
    assert(texture != nullptr);
    if (texture == nullptr) return;

    Renderer::DrawTexture(texture, x, y, width, height, rotation, pivotX, pivotY);
}

void Renderer::DrawTexture(const std::string& id, const Vector2& position, const Vector2& scale, float rotation,
	const Vector2& pivot, const Matrix3f& local2World)
{
    Texture* texture = TextureManager::GetTexture(id);
    assert(texture != nullptr);
    if (texture == nullptr) return;

    DrawTexture(texture, position.x, position.y, scale.x, scale.y, rotation, pivot.x, pivot.y, local2World);
}

void Renderer::DrawString(std::string str, float x, float y, float w, float h, float r, float g, float b,float fontSize,const wchar_t* fontName)
{

    s_Data.RenderTarget->SetTransform(Matrix3x2F::Identity());

    IDWriteTextFormat* textFormat;
    s_Data.WriteFactory->CreateTextFormat(
        fontName,
        NULL,
        DWRITE_FONT_WEIGHT_NORMAL,
        DWRITE_FONT_STYLE_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL,
        fontSize,
        L"zh-cn",
        &textFormat
    );

    textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
    textFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

    ID2D1SolidColorBrush* brush;
    s_Data.RenderTarget->CreateSolidColorBrush(ColorF(r, g, b), &brush);

    std::wstring wstr = Utils::utf8_to_wstring(str);

    D2D1_RECT_F rect;
    rect.left = x;
    rect.right = x+w;
    rect.top = y;
    rect.bottom = y+h;

    s_Data.RenderTarget->DrawText(
        wstr.c_str(),
        wstr.length(),
        textFormat,
        rect,
        brush
    );

    SafeRelease(&brush);
    SafeRelease(&textFormat);
}

void Renderer::SetViewport(int x, int y, int width, int height)
{
    s_Data.ViewportMatrix = {
        (float)width,0,(float)x,
        0,(float)height,(float)y,
        0,0,1
    };
}

void Renderer::SetViewProjection(const Matrix3f& m)
{
    s_Data.ViewProjectionMatrix = m;
}

ID2D1HwndRenderTarget* Renderer::GetRenderTarget()
{
    return s_Data.RenderTarget;
}

void Renderer::SwapBuffers()
{
    s_Data.RenderTarget->EndDraw();
    s_Data.RenderTarget->BeginDraw();
}
