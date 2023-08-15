#include "RenderingPipline.h"
#include "OutputAndInput/GameOutput.h"
#include "Math/Matrix.h"
#include <Windows.h>

struct Pic;


RenderingPipline::RenderingPipline()
{
	//m_CameraX = Vector3D::Right();
	//m_CameraY = Vector3D::Up();
	//m_CameraZ = Vector3D::Front();

	//m_CameraX = Vector::right();
	//m_CameraY = Vector::up();
	
	m_Near = 10.0f;
	m_Far = 1000.0f;
}


void RenderingPipline::SetViewMatrix( int w, int h,int offx, int offy)
{
	//ͶӰ֮����2*2��ͼƬ ��Ϊy����ѧ����ϵ-��Ҫ����
	Matrix33 m1, m2, m3, m4;
	//����
	m1.Scale(1, -1);
	//ê��䵽���Ͻ�
	m2.Translate(1, 1);
	//��Ӧ���ڴ�С
	m3.Scale(w / 2, h / 2);
	m4.Translate(offx, offy);
	m_ViewMatrix = m1 * m2 * m3 * m4;

}

void RenderingPipline::DrawModel(const Model* model)
{
	m_Vector.clear();
	//һ���Կ����ڴ�-ֱ��ʹ���±�
	m_Vector.resize(model->vectorlen);

	//������
	for (int i = 0; i < model->vectorlen; i++)
	{
		//ÿһ������ = ����ı������� * ����任����
		m_Vector[i] = model->vector[i] * model->worldMatrix;
	}
	
	//������任
	for (int i = 0; i < model->vectorlen; i++)
	{
		//ÿһ������ = ������������� * �����������
		m_Vector[i] = m_Vector[i] * m_CameraMatrix;
	}

	//�ӿ�
	for (int i = 0; i < model->vectorlen; i++)
	{
		//ÿһ������ = �����ͶӰ���� * �ӿ�����
		m_Vector[i] = m_Vector[i] * m_ViewMatrix;
	}

}
