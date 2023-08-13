#pragma once
class Vector3D
{
public:
	float x;
	float y;
	float z;

	//��λ����
	static Vector3D Right();
	static Vector3D Up();
	static Vector3D Front();

	Vector3D(float X=0, float Y=0, float Z=0);
	//===����===
	float Length()const;//����
	Vector3D Normaliz()const;//��λ��
	//����
	Vector3D operator-()const;
	Vector3D operator+()const;
	//�Ӽ�
	Vector3D operator+(const Vector3D& b)const;
	Vector3D& operator+=(const Vector3D& b);
	Vector3D operator-(const Vector3D& b)const;
	Vector3D& operator-=(const Vector3D& b);
	//��
	float Dot(const Vector3D* b)const;
	Vector3D Cross(const Vector3D* b)const;
	Vector3D operator*(float f)const;
	Vector3D& operator*=(float f);
	Vector3D operator/(float f)const;

	//Vector3D Projection(Vector3D& b)const;//ͶӰ
	float GetAngle(const Vector3D* b)const;
};