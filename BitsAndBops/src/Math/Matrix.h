#pragma once
#include "vector.h"
#include <windows.h>
class CMatrix33 : public XFORM
{
public:
	CMatrix33();
	//��λ����
	void Identity();
	//���ž���
	void Scale(float x, float y);
	//��ת����
	void Rotate_R(float r);
	void Rotate_A(float a);
	//ƽ�ƾ���
	void Translate(float x, float y);

	CMatrix33 operator *(const CMatrix33& m);
};

inline CVector operator *(const CVector& v, const CMatrix33& m)
{
	CVector v2;
	v2.x = v.x * m.eM11 + v.y * m.eM21 + m.eDx;
	v2.y = v.x * m.eM12 + v.y * m.eM22 + m.eDy;
	return v2;
}


