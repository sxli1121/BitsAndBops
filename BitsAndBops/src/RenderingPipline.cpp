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
	////摄像机的反向量-返回世界原点
	////平移
	//tm.Translation(-eye.x, -eye.y, -eye.z);
	//旋转
	//摄像机的xyz值 最终会变成与世界的xyz一样的存在-会变成单位向量--转到正前方--
	//每一个向量 * 一个相同的旋转矩阵 = 单位向量 进行组合  A * A的逆矩阵 = 1
	//相互垂直的矩阵的逆矩阵 就是 自己的转置矩阵（行列互换）
	//求当前摄像机的三个轴--变成转置矩阵

	//摄像机的正前方Z
	m_CameraZ = at - eye;
	m_CameraZ = m_CameraZ.Normaliz();
	up = up.Normaliz();
	m_CameraX = up.Cross(&m_CameraZ);     //左手坐标系
	m_CameraY = m_CameraZ.Cross(&m_CameraX);

	/*旋转矩阵-转置
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

	//最后相乘的结果
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
	//投影之后是2*2的图片 因为y是数学坐标系-需要镜像
	Matrix4X4 m1, m2, m3, m4;
	//镜像
	m1.Scaling(1, -1, 1);
	//锚点变到左上角
	m2.Translation(1, 1, 0);
	//适应窗口大小
	m3.Scaling(w, h, 1);
	m4.Translation(offx, offy, 0);
	m_ViewMatrix = m1 * m2 * m3 * m4;

}

void RenderingPipline::DrawModel(const Model* model, Matrix4X4 world_matrix)
{
	m_Vector.clear();
	//一次性开好内存-直接使用下标
	m_Vector.resize(model->vectorlen);
	//世界变幻
	for (int i = 0; i < model->vectorlen; i++)
	{
		//每一个顶点 = 顶点的本地坐标 * 世界变换矩阵
		m_Vector[i] = model->vector[i] * world_matrix;
	}
	
	//摄像机变换
	for (int i = 0; i < model->vectorlen; i++)
	{
		//每一个顶点 = 顶点的世界坐标 * 摄像机的坐标
		m_Vector[i] = m_Vector[i] * m_CameraMatrix;
	}

	//投影变幻--1比1
	for (int i = 0; i < model->vectorlen; i++)
	{
		//相似三角形 m_Vector[i].x / z的投影距离 = m_Vector[i].x / m_Vector[i].z;
		//投影角度45--z值不计算 保存摄像机z值 （遮挡关系）
		m_Vector[i].x = m_Vector[i].x / m_Vector[i].z;
		m_Vector[i].y = m_Vector[i].y / m_Vector[i].z;
	}

	//视口
	for (int i = 0; i < model->vectorlen; i++)
	{
		//每一个顶点 = 顶点的投影坐标 * 视口坐标
		m_Vector[i] = m_Vector[i] * m_ViewMatrix;
	}

	//线段绘制
	CGO* go = CGO::GetGO();
	for (int i = 0; i < model->iLen; i++)
	{
		int i1 = model->index[i * 2 + 0];
		int i2 = model->index[i * 2 + 1];
		go->DrawLine(m_Vector[i1].x, m_Vector[i1].y, m_Vector[i2].x, m_Vector[i2].y);
	}


}
