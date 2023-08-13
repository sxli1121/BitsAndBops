#include "matrix4X4.h"
#include <math.h>

inline void Matrix4X4::_init()
{
	m11 = 1;   m12 = 0;   m13 = 0;  m14 = 0;
	m21 = 0;   m22 = 1;   m23 = 0;  m24 = 0;
	m31 = 0;   m32 = 0;   m33 = 1;  m34 = 0;
	m41 = 0;   m42 = 0;   m43 = 0;  m44 = 1;
}

Matrix4X4::Matrix4X4()
{
    _init();
}

Matrix4X4::~Matrix4X4()
{
}

Matrix4X4 Matrix4X4::Normaliation()
{
    _init();
    return *this;
}

Matrix4X4 Matrix4X4::Translation(float x, float y, float z)
{
	_init();
	m41 = x;   m42 = y;   m43 = z;
	return *this;
}

Matrix4X4 Matrix4X4::Rotation_A_X(float angle)
{
	_init();
	float r = angle * 3.14f / 180;
	float mcos = cos(r);
	float msin = sin(r);
	m22 = mcos; m23 = msin;
	m32 = -msin; m33 = mcos;
	return *this;
}

Matrix4X4 Matrix4X4::Rotation_A_Y(float angle)
{
	_init();
	float r = angle * 3.14f / 180;
	float mcos = cos(r);
	float msin = sin(r);
	m11 = mcos; m13 = -msin;
	m31 = msin; m33 = mcos;
	return *this;
}

Matrix4X4 Matrix4X4::Rotation_A_Z(float angle)
{
	_init();
	float r = angle * 3.14f / 180;
	float mcos = cos(r);
	float msin = sin(r);
	m11 = mcos; m12 = msin;
	m21 = -msin; m22 = mcos;
	return *this;
}

Matrix4X4 Matrix4X4::Rotation_R_X(float r)
{
	_init();
	float mcos = cos(r);
	float msin = sin(r);
	m22 = mcos; m23 = msin;
	m32 = -msin; m33 = mcos;
	return *this;
}

Matrix4X4 Matrix4X4::Rotation_R_Y(float r)
{
	_init();
	float mcos = cos(r);
	float msin = sin(r);
	m11 = mcos; m13 = -msin;
	m31 = msin; m33 = mcos;
	return *this;
}

Matrix4X4 Matrix4X4::Rotation_R_Z(float r)
{
	_init();
	float mcos = cos(r);
	float msin = sin(r);
	m11 = mcos; m12 = msin;
	m21 = -msin; m22 = mcos;
	return *this;
}

Matrix4X4 Matrix4X4::Scaling(float x_mulriple, float y_mulriple, float z_mulriple)
{
	_init();
	m11 = x_mulriple;
	m22 = y_mulriple;
	m33 = z_mulriple;
	return *this;
}

Matrix4X4 Matrix4X4::Scaling(float mulriple)
{
	_init();
	m11 = mulriple;
	m22 = mulriple;
	m33 = mulriple;
	return *this;
}

Matrix4X4 Matrix4X4::operator*(const Matrix4X4& m)
{
	Matrix4X4 m2;
	m2.m11 = m11 * m.m11 + m12 * m.m21 + m13 * m.m31 + m14 * m.m41;
	m2.m12 = m11 * m.m12 + m12 * m.m22 + m13 * m.m32 + m14 * m.m42;
	m2.m13 = m11 * m.m13 + m12 * m.m23 + m13 * m.m33 + m14 * m.m43;
	m2.m14 = m11 * m.m14 + m12 * m.m24 + m13 * m.m34 + m14 * m.m44;

	m2.m21 = m21 * m.m11 + m22 * m.m21 + m23 * m.m31 + m24 * m.m41;
	m2.m22 = m21 * m.m12 + m22 * m.m22 + m23 * m.m32 + m24 * m.m42;
	m2.m23 = m21 * m.m13 + m22 * m.m23 + m23 * m.m33 + m24 * m.m43;
	m2.m24 = m21 * m.m14 + m22 * m.m24 + m23 * m.m34 + m24 * m.m44;

	m2.m31 = m31 * m.m11 + m32 * m.m21 + m33 * m.m31 + m34 * m.m41;
	m2.m32 = m31 * m.m12 + m32 * m.m22 + m33 * m.m32 + m34 * m.m42;
	m2.m33 = m31 * m.m13 + m32 * m.m23 + m33 * m.m33 + m34 * m.m43;
	m2.m34 = m31 * m.m14 + m32 * m.m24 + m33 * m.m34 + m34 * m.m44;

	m2.m41 = m41 * m.m11 + m42 * m.m21 + m43 * m.m31 + m44 * m.m41;
	m2.m42 = m41 * m.m12 + m42 * m.m22 + m43 * m.m32 + m44 * m.m42;
	m2.m43 = m41 * m.m13 + m42 * m.m23 + m43 * m.m33 + m44 * m.m43;
	m2.m44 = m41 * m.m14 + m42 * m.m24 + m43 * m.m34 + m44 * m.m44;
	return m2;
}

Matrix4X4& Matrix4X4::operator*=(const Matrix4X4& m)
{
	Matrix4X4 m2;
	m2.m11 = m11 * m.m11 + m12 * m.m21 + m13 * m.m31 + m14 * m.m41;
	m2.m12 = m11 * m.m12 + m12 * m.m22 + m13 * m.m32 + m14 * m.m42;
	m2.m13 = m11 * m.m13 + m12 * m.m23 + m13 * m.m33 + m14 * m.m43;
	m2.m14 = m11 * m.m14 + m12 * m.m24 + m13 * m.m34 + m14 * m.m44;

	m2.m21 = m21 * m.m11 + m22 * m.m21 + m23 * m.m31 + m24 * m.m41;
	m2.m22 = m21 * m.m12 + m22 * m.m22 + m23 * m.m32 + m24 * m.m42;
	m2.m23 = m21 * m.m13 + m22 * m.m23 + m23 * m.m33 + m24 * m.m43;
	m2.m24 = m21 * m.m14 + m22 * m.m24 + m23 * m.m34 + m24 * m.m44;

	m2.m31 = m31 * m.m11 + m32 * m.m21 + m33 * m.m31 + m34 * m.m41;
	m2.m32 = m31 * m.m12 + m32 * m.m22 + m33 * m.m32 + m34 * m.m42;
	m2.m33 = m31 * m.m13 + m32 * m.m23 + m33 * m.m33 + m34 * m.m43;
	m2.m34 = m31 * m.m14 + m32 * m.m24 + m33 * m.m34 + m34 * m.m44;

	m2.m41 = m41 * m.m11 + m42 * m.m21 + m43 * m.m31 + m44 * m.m41;
	m2.m42 = m41 * m.m12 + m42 * m.m22 + m43 * m.m32 + m44 * m.m42;
	m2.m43 = m41 * m.m13 + m42 * m.m23 + m43 * m.m33 + m44 * m.m43;
	m2.m44 = m41 * m.m14 + m42 * m.m24 + m43 * m.m34 + m44 * m.m44;

	*this = m2;
	return *this;
}


