#pragma once
#include "Math/Vector3D.h"
#include "Math/matrix4X4.h"

class Camera
{
	//Vector3D m_Eye;
	//Vector3D m_At;
	//Vector3D m_Up;
	float m_X;
	float m_Y;
	float m_Weight;
	float m_Hight;

public:
	Camera();
	void SetCameraMatrix();

};

