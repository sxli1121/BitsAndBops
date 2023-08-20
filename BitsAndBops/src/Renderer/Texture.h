#pragma once

namespace Gdiplus
{
	class Image;
}

class Texture
{
public:
	int GetWidth() const;
	int GetHeight() const;
	inline Gdiplus::Image* GetGdiImage() const { return m_GdiImage; }
	static Texture* Load(const wchar_t* fileName);
private:
	Gdiplus::Image* m_GdiImage{ nullptr };
};

