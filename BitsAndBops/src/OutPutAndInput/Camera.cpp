#include "Camera.h"
#include "Core/FrameWork.h"
#include "Math/matrix.h"


Camera::Camera()
{
	CFrameWork* framework = CFrameWork::GetFrameWork();
	m_OrthoWeight = framework->GetClientW();
	m_OrthoHeight = framework->GetClientH();
	CalculateMatrix();
}

void Camera::SetAngle(float angle)
{
	m_Angle = angle;
	CalculateMatrix();
}

void Camera::SetPosition(float x, float y)
{
	m_X = x;
	m_Y = y;
	CalculateMatrix();
}

void Camera::SetOrthoSize(float w, float h)
{
	m_OrthoWeight = w;
	m_OrthoHeight = h;
	CalculateMatrix();
}

Matrix33 Camera::GetProjectionMatrix()
{
	return m_ProjectionMatrix;
}

Matrix33 Camera::GetViewMatrix()
{
	return m_ViewMatrix;
}

Matrix33 Camera::GetViewProjMatrix()
{
	return m_ViewProjMatrix;
}

void Camera::CalculateMatrix()
{
	Matrix33 tm,rm;
	tm.Translate(-m_X, -m_Y);
	rm.Rotate_A(-m_Angle);
	m_ViewMatrix = tm * rm;

	Matrix33 sm;
	sm.Scale(1.0f/m_OrthoWeight,1.0f/m_OrthoHeight);
	m_ProjectionMatrix = sm;

	//m_ViewProjMatrix = m_ViewMatrix * m_ProjectionMatrix;
}
