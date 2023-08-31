#pragma once
#include <d2d1.h>

namespace Gdiplus
{
	class Image;
}

class Texture
{
public:
	int GetWidth() const;
	int GetHeight() const;
	inline ID2D1Bitmap* GetBitmap() const { return m_Bitmap; }
	static Texture* Load(const wchar_t* fileName);
private:
	ID2D1Bitmap* m_Bitmap{ nullptr };
};

