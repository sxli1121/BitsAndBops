#pragma once
#include "Renderer/Texture.h"
#include "Math/Matrix.h"

#include <string>

class Renderer
{
public:
	static void Init();
	static void Shutdown();
	static void Clear(float r,float g,float b);
	static void SwapBuffers();                       

	static void DrawTexture(const Texture* texture, float x, float y,float width = 1.0f, float height = 1.0f, float rotation = 0.0f, float pivotX = 0.0f, float pivotY = 0.0f, const Matrix3f& local2World = Matrix3f::Identity);
	static void DrawTexture(const std::string& id, float x, float y, float width = 1.0f, float height=1.0f, float rotation=0.0f, float pivotX=0.0f, float pivotY=0.0f);
	static void DrawTexture(const std::string& id, const Vector2& position, const Vector2& scale = { 1,1 }, float rotation = 0, const Vector2& pivot = { .5f,.5f }, const Matrix3f& local2World = Matrix3f::Identity);

	static void DrawString(std::string str, float x, float y, float w, float h, float r=1.0f, float g=1.0f, float b=1.0f,float fontSize = 22.0f,const wchar_t* fontName= L"simhei");

	static void SetViewport(int x, int y, int width, int height);
	static void SetViewProjection(const Matrix3f& m);

	static ID2D1HwndRenderTarget* GetRenderTarget();
};

