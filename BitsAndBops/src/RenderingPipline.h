#pragma once
#include "Vector3D.h"
#include "matrix4X4.h"
#include <vector>

struct Model
{
	//����
	Vector3D* vector;
	//�������
	int vectorlen;
	//�߶ε��±�
	int* index;
	//�߶θ���
	int iLen;
};

class RenderingPipline
{

	//ʹ�ù���
	struct Triangle
	{
		int x1, x2, x3;
		int y1, y2, y3;
		int z;
	};
	//����ģ�͵�������
	std::vector<Triangle> m_Triangle;


	//��������
	Vector3D m_Eye;
	Vector3D m_At;
	Vector3D m_Up;
	//�����xyz����
	Vector3D m_CameraX;
	Vector3D m_CameraY;
	Vector3D m_CameraZ;

	//�ӿ������������
	Matrix4X4 m_ViewMatrix;
	Matrix4X4 m_CameraMatrix;
	//�洢ģ�͵Ķ���
	std::vector<Vector3D> m_Vector;
public:
	RenderingPipline();
	void SetCameraMatrix(Vector3D eye, Vector3D at, Vector3D up = Vector3D(0, 1, 0));
	void SetViewMatrix(int w,int h,int offx = 0, int offy = 0 );
	void DrawModel(const Model* model,Matrix4X4 world_matrix);


};

