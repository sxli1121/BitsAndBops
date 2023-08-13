#include "RenderingPipline.h"
#include "GameOutput.h"
#include <Windows.h>

RenderingPipline::RenderingPipline()
{
	m_CameraX = Vector3D::Right();
	m_CameraY = Vector3D::Up();
	m_CameraZ = Vector3D::Front();
	

}

void RenderingPipline::SetCameraMatrix(Vector3D eye, Vector3D at, Vector3D up)
{
	//Matrix4X4 tm,rm;
	////������ķ�����-��������ԭ��
	////ƽ��
	//tm.Translation(-eye.x, -eye.y, -eye.z);
	//��ת
	//�������xyzֵ ���ջ����������xyzһ���Ĵ���-���ɵ�λ����--ת����ǰ��--
	//ÿһ������ * һ����ͬ����ת���� = ��λ���� �������  A * A������� = 1
	//�໥��ֱ�ľ��������� ���� �Լ���ת�þ������л�����
	//��ǰ�������������--���ת�þ���

	//���������ǰ��Z
	m_CameraZ = at - eye;
	m_CameraZ = m_CameraZ.Normaliz();
	up = up.Normaliz();
	m_CameraX = up.Cross(&m_CameraZ);     //��������ϵ
	m_CameraY = m_CameraZ.Cross(&m_CameraX);

	/*��ת����-ת��
	rm.m11 = m_CameraX.x;
	rm.m21 = m_CameraX.y;
	rm.m31 = m_CameraX.z;
	rm.m41 = 0;

	rm.m12 = m_CameraY.x;
	rm.m22 = m_CameraY.y;
	rm.m32 = m_CameraY.z;
	rm.m42 = 0;

	rm.m13 = m_CameraZ.x;
	rm.m23 = m_CameraZ.y;
	rm.m33 = m_CameraZ.z;
	rm.m43 = 0;

	rm.m14 = 0;
	rm.m24 = 0;
	rm.m34 = 0;
	rm.m44 = 1;*/

	//�����˵Ľ��
	m_CameraMatrix.m11 = m_CameraX.x;
	m_CameraMatrix.m12 = m_CameraY.x;
	m_CameraMatrix.m13 = m_CameraZ.x;
	m_CameraMatrix.m14 = 0;

	m_CameraMatrix.m21 = m_CameraX.y;
	m_CameraMatrix.m22 = m_CameraY.y;
	m_CameraMatrix.m23 = m_CameraZ.y;
	m_CameraMatrix.m24 = 0;

	m_CameraMatrix.m31 = m_CameraX.z;
	m_CameraMatrix.m32 = m_CameraY.z;
	m_CameraMatrix.m33 = m_CameraZ.z;
	m_CameraMatrix.m34 = 0;

	m_CameraMatrix.m41 = -eye.Dot(&m_CameraX);
	m_CameraMatrix.m42 = -eye.Dot(&m_CameraY);
	m_CameraMatrix.m43 = -eye.Dot(&m_CameraZ);
	m_CameraMatrix.m44 = 1;

}

void RenderingPipline::SetViewMatrix( int w, int h,int offx, int offy)
{
	//ͶӰ֮����2*2��ͼƬ ��Ϊy����ѧ����ϵ-��Ҫ����
	Matrix4X4 m1, m2, m3, m4;
	//����
	m1.Scaling(1, -1, 1);
	//ê��䵽���Ͻ�
	m2.Translation(1, 1, 0);
	//��Ӧ���ڴ�С
	m3.Scaling(w, h, 1);
	m4.Translation(offx, offy, 0);
	m_ViewMatrix = m1 * m2 * m3 * m4;

}

void RenderingPipline::DrawModel(const Model* model, Matrix4X4 world_matrix)
{
	m_Vector.clear();
	//һ���Կ����ڴ�-ֱ��ʹ���±�
	m_Vector.resize(model->vectorlen);
	//������
	for (int i = 0; i < model->vectorlen; i++)
	{
		//ÿһ������ = ����ı������� * ����任����
		m_Vector[i] = model->vector[i] * world_matrix;
	}
	
	//������任
	for (int i = 0; i < model->vectorlen; i++)
	{
		//ÿһ������ = ������������� * �����������
		m_Vector[i] = m_Vector[i] * m_CameraMatrix;
	}

	//ͶӰ���--1��1
	for (int i = 0; i < model->vectorlen; i++)
	{
		//���������� m_Vector[i].x / z��ͶӰ���� = m_Vector[i].x / m_Vector[i].z;
		//ͶӰ�Ƕ�45--zֵ������ ���������zֵ ���ڵ���ϵ��
		m_Vector[i].x = m_Vector[i].x / m_Vector[i].z;
		m_Vector[i].y = m_Vector[i].y / m_Vector[i].z;
	}

	//�ӿ�
	for (int i = 0; i < model->vectorlen; i++)
	{
		//ÿһ������ = �����ͶӰ���� * �ӿ�����
		m_Vector[i] = m_Vector[i] * m_ViewMatrix;
	}

	//�߶λ���
	CGO* go = CGO::GetGO();
	for (int i = 0; i < model->iLen; i++)
	{
		int i1 = model->index[i * 2 + 0];
		int i2 = model->index[i * 2 + 1];
		go->DrawLine(m_Vector[i1].x, m_Vector[i1].y, m_Vector[i2].x, m_Vector[i2].y);
	}


}
