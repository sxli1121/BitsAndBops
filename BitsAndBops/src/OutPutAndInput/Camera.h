#pragma once
#include "Math/matrix.h"

class Camera
{
public:
	Camera();

	void SetScale(float scale);
	void SetRotation(float angle);            //Ðý×ª
	void SetOrtho(float left,float top,float width, float height);      //´óÐ¡

	Matrix3f GetProjectionMatrix();
	Matrix3f GetViewMatrix();
	Matrix3f GetViewProjMatrix();

private:
	void CalculateMatrix();
private:
	float m_Left{ 0 };
	float m_Top{ 0 };
	float m_Width {0};
	float m_Height{ 0 };
	float m_RotationAngle{ 0 };
	float m_Scale = 1.0f;

	Matrix3f m_ViewMatrix;
	Matrix3f m_ProjectionMatrix;
	Matrix3f m_ViewProjMatrix;
};

