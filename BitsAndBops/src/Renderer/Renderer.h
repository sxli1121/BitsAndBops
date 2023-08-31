#pragma once

#include "Renderer/Texture.h"
#include "Renderer/TextureManager.h"
#include "Math/Matrix.h"

#include <string>

class Renderer
{
public:
	static void Init();
	static void Shutdown();
	static void Clear(float r,float g,float b);
	static void SwapBuffers();                       //»º³å

	static void DrawTexture(const Texture* texture, float x, float y,float width = 1.0f, float height = 1.0f, float rotation = 0.0f, float pivotX = 0.0f, float pivotY = 0.0f);
	static void DrawTexture(const std::string& id, float x, float y, float width = 1.0f, float height=1.0f, float rotation=0.0f, float pivotX=0.0f, float pivotY=0.0f);

	static void DrawString(std::string str, float x, float y, float w, float h, float r=1.0f, float g=1.0f, float b=1.0f);

	static void SetViewport(int x, int y, int width, int height);
	static void SetViewProjection(const Matrix3f& m);

	static ID2D1HwndRenderTarget* GetRenderTarget();
};

