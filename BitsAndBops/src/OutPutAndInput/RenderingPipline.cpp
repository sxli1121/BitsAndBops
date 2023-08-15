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
	//投影之后是2*2的图片 因为y是数学坐标系-需要镜像
	Matrix33 m1, m2, m3, m4;
	//镜像
	m1.Scale(1, -1);
	//锚点变到左上角
	m2.Translate(1, 1);
	//适应窗口大小
	m3.Scale(w / 2, h / 2);
	m4.Translate(offx, offy);
	m_ViewMatrix = m1 * m2 * m3 * m4;

}

void RenderingPipline::DrawModel(const Model* model)
{
	m_Vector.clear();
	//一次性开好内存-直接使用下标
	m_Vector.resize(model->vectorlen);

	//世界变幻
	for (int i = 0; i < model->vectorlen; i++)
	{
		//每一个顶点 = 顶点的本地坐标 * 世界变换矩阵
		m_Vector[i] = model->vector[i] * model->worldMatrix;
	}
	
	//摄像机变换
	for (int i = 0; i < model->vectorlen; i++)
	{
		//每一个顶点 = 顶点的世界坐标 * 摄像机的坐标
		m_Vector[i] = m_Vector[i] * m_CameraMatrix;
	}

	//视口
	for (int i = 0; i < model->vectorlen; i++)
	{
		//每一个顶点 = 顶点的投影坐标 * 视口坐标
		m_Vector[i] = m_Vector[i] * m_ViewMatrix;
	}

}
