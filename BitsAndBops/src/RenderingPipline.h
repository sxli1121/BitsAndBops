#pragma once
#include "Vector3D.h"
#include "matrix4X4.h"
#include <vector>

struct Model
{
	//顶点
	Vector3D* vector;
	//顶点个数
	int vectorlen;
	//线段的下标
	int* index;
	//线段个数
	int iLen;
};

class RenderingPipline
{

	//使用管线
	struct Triangle
	{
		int x1, x2, x3;
		int y1, y2, y3;
		int z;
	};
	//储存模型的三角形
	std::vector<Triangle> m_Triangle;


	//摄像机相关
	Vector3D m_Eye;
	Vector3D m_At;
	Vector3D m_Up;
	//摄像机xyz方向
	Vector3D m_CameraX;
	Vector3D m_CameraY;
	Vector3D m_CameraZ;

	//视口与摄像机矩阵
	Matrix4X4 m_ViewMatrix;
	Matrix4X4 m_CameraMatrix;
	//存储模型的顶点
	std::vector<Vector3D> m_Vector;
public:
	RenderingPipline();
	void SetCameraMatrix(Vector3D eye, Vector3D at, Vector3D up = Vector3D(0, 1, 0));
	void SetViewMatrix(int w,int h,int offx = 0, int offy = 0 );
	void DrawModel(const Model* model,Matrix4X4 world_matrix);


};

