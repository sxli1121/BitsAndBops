#pragma once
#include "Math/Vector3D.h"
#include "Math/matrix4X4.h"
#include "OutputAndInput/RenderingPipline.h"
#include "Math/matrix.h"
struct PIC;

//struct Model
//{
//	Vector vector[4];
//	int vectorlen;
//	Matrix33 worldMatrix;
//};

class Camera
{
	//Vector3D m_Eye;
	//Vector3D m_At;
	//Vector3D m_Up;
	
	//初始化0
	float m_X;
	float m_Y;
	float m_Weight;             //摄像机的大小  非视口的大小
	float m_Hight;

	float m_OffsetAngle;
	float m_OffsetX;
	float m_OffsetY;
	Matrix33 m_CameraMatrix;


public:
	Camera();
	void Init();
	void Run(const Model* pic);
	void End();

	void SetCameraMatrix();                    //3*3矩阵
	void CameraRotate(float angle);            //旋转
	void CameraMove(float x, float y);         //移动
	Matrix33 GetCameraMatrix();

	void SetCameraSize(float offsetx, float offsety, float w, float h);      //大小
	void SetViewCamera(float w,float h);                      //
};

