#include "Texture.h"

#include <Windows.h>
#include <gdiplus.h>
#include <cassert>

int Texture::GetWidth() const
{
	return m_GdiImage->GetWidth();
}

int Texture::GetHeight() const
{
	return m_GdiImage->GetHeight();
}

Texture* Texture::Load(const wchar_t* fileName)
{
	Gdiplus::Image* image = Gdiplus::Image::FromFile(fileName);
	
	assert(image->GetLastStatus() == Gdiplus::Status::Ok);

	if (image->GetLastStatus() != Gdiplus::Status::Ok)
	{
		delete image;
		return nullptr;
	}

	Texture* texture = new Texture;
	texture->m_GdiImage = image;

	return texture;
}
