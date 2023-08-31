#include "Texture.h"
#include "Renderer.h"

#include <d2d1.h>
#include <wincodec.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "windowscodecs.lib")

template<class T> void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}


int Texture::GetWidth() const
{
    return (int)m_Bitmap->GetSize().width;
}

int Texture::GetHeight() const
{
    return (int)m_Bitmap->GetSize().height;
}

Texture* Texture::Load(const wchar_t* fileName)
{
    IWICImagingFactory* wicFactory;
    CoCreateInstance(
        CLSID_WICImagingFactory,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&wicFactory)
    );

    IWICBitmapDecoder* decoder;
    wicFactory->CreateDecoderFromFilename(
        fileName,
        NULL,
        GENERIC_READ,
        WICDecodeMetadataCacheOnLoad,
        &decoder
    );

    IWICBitmapFrameDecode* frame;
    decoder->GetFrame(0, &frame);

    IWICFormatConverter* converter;
    wicFactory->CreateFormatConverter(&converter);

    converter->Initialize(
        frame,
        GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone,
        NULL,
        0.0f,
        WICBitmapPaletteTypeCustom
    );

    ID2D1Bitmap* bitmap;
    Renderer::GetRenderTarget()->CreateBitmapFromWicBitmap(
        converter,
        NULL,
        &bitmap
    );

    SafeRelease(&converter);
    SafeRelease(&frame);
    SafeRelease(&decoder);
    SafeRelease(&wicFactory);

    Texture* texture = new Texture;
    texture->m_Bitmap = bitmap;

    return texture;
}
