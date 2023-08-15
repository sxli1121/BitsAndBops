#include "Camera.h"
#include "Core/FrameWork.h"
#include "Math/matrix.h"

Camera::Camera()
{
}

void Camera::Init()
{
	//��ʼ���������λ������
	m_X = 0;
	m_Y = 0;
	CFrameWork* framework = CFrameWork::GetFrameWork();
	m_Weight = framework->GetClientW();
	m_Hight = framework->GetClientH();
	//ƫ����
	m_OffsetAngle = 0;
	m_OffsetX = 0;
	m_OffsetY = 0;
}

void Camera::Run(const Model* pic)
{
	//�����ӿڵľ���
	//m_RenderPipline.SetViewMatrix(m_X, m_Y);
	//������ˮ����
	//m_RenderPipline.DrawModel(pic);
}								 

void Camera::End()
{

}

void Camera::CameraRotate(float angle)
{
	m_OffsetAngle += angle;
	if (m_OffsetAngle > 360)
		m_OffsetAngle -= 360;
	if (m_OffsetAngle < -360)
		m_OffsetAngle += 360;
}

void Camera::CameraMove(float x, float y)
{
	m_OffsetX += x;
	m_OffsetY += y;
}

Matrix33 Camera::GetCameraMatrix()
{
	return m_CameraMatrix;
}

void Camera::SetCameraSize(float offsetx, float offsety, float w, float h)
{
	m_OffsetX = m_OffsetX + offsetx;
	m_OffsetY = m_OffsetY + offsety;
	m_Weight = w;
	m_Hight = h;
}

void Camera::SetViewCamera(float w, float h)
{
	m_Weight = w;
	m_Hight = h;
}

void Camera::SetCameraMatrix()
{
	Matrix33 tm, rm;
	//ƽ�� ��ת
	tm.Translate(-m_OffsetX, -m_OffsetY);
	rm.Rotate_A(-m_OffsetAngle);
	m_CameraMatrix = tm * rm;

}

