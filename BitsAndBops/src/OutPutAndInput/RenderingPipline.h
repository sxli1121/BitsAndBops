#pragma once
#include "Math/Vector3D.h"
#include "Math/matrix4X4.h"
#include "Math/matrix.h"
#include "Math/Vector.h"
#include <vector>

struct Pic;
//ͼƬ-�ĸ�����
struct Model
{
	//����-�ĸ�
	Vector vector[4];
	//Vector* vector;
	//�������
	int vectorlen;
	//�߶ε��±�/��ɫ
	//int* index;
	//�߶θ���
	//int iLen;
	Matrix33 worldMatrix;
};

class RenderingPipline
{

	//ʹ�ù���
	//struct Triangle
	//{
	//	int x1, x2, x3;
	//	int y1, y2, y3;
	//	int z;
	//};
	//����ģ�͵�������
	//std::vector<Triangle> m_Triangle;

	//��������
	//Vector3D m_Eye;
	//Vector3D m_At;
	//Vector3D m_Up;
	
	//Vector m_Eye;    //λ��
	//Vector m_Up;     //�Ϸ�

	//�����xyz����
	//Vector3D m_CameraX;
	//Vector3D m_CameraY;
	//Vector3D m_CameraZ;
	

	//Vector m_CameraX;   
	//Vector m_CameraY;
	
	//��Զ����
	float m_Near;
	float m_Far;

	//�ӿ������������
	Matrix33 m_ViewMatrix;
	Matrix33 m_CameraMatrix;
	//�洢ģ�͵Ķ���
	std::vector<Vector> m_Vector;
public:
	RenderingPipline();
	void SetViewMatrix(int w,int h,int offx = 0, int offy = 0);
	void DrawModel(const Model* pic);

};

