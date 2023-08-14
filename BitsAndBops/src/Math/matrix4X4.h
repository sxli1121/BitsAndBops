#pragma once
#include"Vector3D.h"
#include<windows.h>
class Matrix4X4
{
	//左手坐标系
	inline void _init();
public:
	float m11;
	float m12;
	float m13;
	float m14;

	float m21;
	float m22;
	float m23;
	float m24;

	float m31;
	float m32;
	float m33;
	float m34;

	float m41;
	float m42;
	float m43;
	float m44;

	Matrix4X4();
	virtual~Matrix4X4();

	Matrix4X4 Normaliation();
	//平移
	Matrix4X4 Translation(float x, float y, float z);
	//旋转
	Matrix4X4 Rotation_A_X(float angle);
	Matrix4X4 Rotation_A_Y(float angle);
	Matrix4X4 Rotation_A_Z(float angle);

	Matrix4X4 Rotation_R_X(float r);
	Matrix4X4 Rotation_R_Y(float r);
	Matrix4X4 Rotation_R_Z(float r);
	//缩放(xyz分别)
	Matrix4X4 Scaling(float x_mulriple, float y_mulriple, float z_mulriple);
	//缩放(整体)
	Matrix4X4 Scaling(float mulriple);
	//矩阵×矩阵
	Matrix4X4 operator*(const Matrix4X4& m);
	Matrix4X4& operator*=(const Matrix4X4& m);
};

inline Vector3D operator*(const Vector3D& v, const Matrix4X4& m)
{
	//向量×矩阵 
	Vector3D v1;
	v1.x = v.x * m.m11 + v.y * m.m21 + v.z * m.m31 + 1 * m.m41;
	v1.y = v.x * m.m12 + v.y * m.m22 + v.z * m.m32 + 1 * m.m42;
	v1.z = v.x * m.m13 + v.y * m.m23 + v.z * m.m33 + 1 * m.m43;
	return v1;
}