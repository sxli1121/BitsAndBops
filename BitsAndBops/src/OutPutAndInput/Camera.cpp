#include "Camera.h"
#include "Core/FrameWork.h"
#include "Math/Math.h"
#include "Math/Matrix.h"


Camera::Camera()
{
	CFrameWork* framework = CFrameWork::GetFrameWork();
	m_Width = framework->GetClientW();
	m_Height = framework->GetClientH();
	CalculateMatrix();
}

void Camera::SetScale(float scale)
{
	m_Scale = scale;
	CalculateMatrix();
}

void Camera::SetRotation(float angle)
{
	m_RotationAngle = angle;
	CalculateMatrix();
}

void Camera::SetOrtho(float left, float top, float width, float height)
{
	m_Left = left;
	m_Top = top;
	m_Width = width;
	m_Height = height;
	CalculateMatrix();
}

Matrix3f Camera::GetProjectionMatrix()
{
	return m_ProjectionMatrix;
}

Matrix3f Camera::GetViewMatrix()
{
	return m_ViewMatrix;
}

Matrix3f Camera::GetViewProjMatrix()
{
	return m_ViewProjMatrix;
}

void Camera::CalculateMatrix()
{
	Vector2 position = { m_Left,m_Top};
	Vector2 center = { m_Width * 0.5f,m_Height * 0.5f };

	Matrix3f cameraTransform = Matrix3f::Translate(position+center)
	* Matrix3f::Scale({m_Scale,m_Scale})	  
	* Matrix3f::Rotate(Math::Deg2Rad(m_RotationAngle))
	* Matrix3f::Translate(-center);

	m_ViewMatrix = Matrix3f::Inverse(cameraTransform);
	m_ProjectionMatrix = {
		1.0f / m_Width,0,0,
		0,1.0f / m_Height,0,
		0,0,1
	};

	m_ViewProjMatrix =  m_ProjectionMatrix * m_ViewMatrix;
}
