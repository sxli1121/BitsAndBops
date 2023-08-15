#pragma once
#include "vector.h"
#include <windows.h>
class Matrix33 : public XFORM
{
public:
	Matrix33();
	//��λ����
	void Identity();
	//���ž���
	void Scale(float x, float y);
	//��ת����
	void Rotate_R(float r);
	void Rotate_A(float a);
	//ƽ�ƾ���
	void Translate(float x, float y);

	Matrix33 operator * (const Matrix33& m);

	inline static Matrix33 MakeTranslate(float x, float y)
	{
		Matrix33 m;
		m.Translate(x, y);
		return m;
	}
};

inline Vector operator *(const Vector& v, const Matrix33& m)
{
	Vector v2;
	v2.x = v.x * m.eM11 + v.y * m.eM21 + m.eDx;
	v2.y = v.x * m.eM12 + v.y * m.eM22 + m.eDy;
	return v2;
}


