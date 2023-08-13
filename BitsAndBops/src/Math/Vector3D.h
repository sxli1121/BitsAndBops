#pragma once
class Vector3D
{
public:
	float x;
	float y;
	float z;

	//单位向量
	static Vector3D Right();
	static Vector3D Up();
	static Vector3D Front();

	Vector3D(float X=0, float Y=0, float Z=0);
	//===计算===
	float Length()const;//长度
	Vector3D Normaliz()const;//单位化
	//正负
	Vector3D operator-()const;
	Vector3D operator+()const;
	//加减
	Vector3D operator+(const Vector3D& b)const;
	Vector3D& operator+=(const Vector3D& b);
	Vector3D operator-(const Vector3D& b)const;
	Vector3D& operator-=(const Vector3D& b);
	//乘
	float Dot(const Vector3D* b)const;
	Vector3D Cross(const Vector3D* b)const;
	Vector3D operator*(float f)const;
	Vector3D& operator*=(float f);
	Vector3D operator/(float f)const;

	//Vector3D Projection(Vector3D& b)const;//投影
	float GetAngle(const Vector3D* b)const;
};