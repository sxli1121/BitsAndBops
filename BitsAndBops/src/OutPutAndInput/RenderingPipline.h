#pragma once
#include "Math/Vector3D.h"
#include "Math/matrix4X4.h"
#include "Math/matrix.h"
#include "Math/Vector.h"
#include <vector>

struct Pic;
//图片-四个顶点
struct Model
{
	//顶点-四个
	Vector vector[4];
	//Vector* vector;
	//顶点个数
	int vectorlen;
	//线段的下标/颜色
	//int* index;
	//线段个数
	//int iLen;
	Matrix33 worldMatrix;
};

class RenderingPipline
{

	//使用管线
	//struct Triangle
	//{
	//	int x1, x2, x3;
	//	int y1, y2, y3;
	//	int z;
	//};
	//储存模型的三角形
	//std::vector<Triangle> m_Triangle;

	//摄像机相关
	//Vector3D m_Eye;
	//Vector3D m_At;
	//Vector3D m_Up;
	
	//Vector m_Eye;    //位置
	//Vector m_Up;     //上方

	//摄像机xyz方向
	//Vector3D m_CameraX;
	//Vector3D m_CameraY;
	//Vector3D m_CameraZ;
	

	//Vector m_CameraX;   
	//Vector m_CameraY;
	
	//近远截面
	float m_Near;
	float m_Far;

	//视口与摄像机矩阵
	Matrix33 m_ViewMatrix;
	Matrix33 m_CameraMatrix;
	//存储模型的顶点
	std::vector<Vector> m_Vector;
public:
	RenderingPipline();
	void SetViewMatrix(int w,int h,int offx = 0, int offy = 0);
	void DrawModel(const Model* pic);

};

