#pragma once
#include "Math/Vector3D.h"
#include "Math/matrix4X4.h"
#include "OutputAndInput/RenderingPipline.h"
#include "Math/matrix.h"

class Camera
{
public:
	Camera();

	void SetAngle(float angle);            //旋转
	void SetPosition(float x, float y);         //移动
	void SetOrthoSize(float w, float h);      //大小

	Matrix33 GetProjectionMatrix();
	Matrix33 GetViewMatrix();
	Matrix33 GetViewProjMatrix();

private:
	void CalculateMatrix();
private:
	float m_OrthoWeight {0};
	float m_OrthoHeight{ 0 };

	float m_X{ 0 };
	float m_Y{ 0 };
	float m_Angle{ 0 };

	Matrix33 m_ViewMatrix;
	Matrix33 m_ProjectionMatrix;
	Matrix33 m_ViewProjMatrix;
};

