#include "Matrix.h"

#include <math.h>


CMatrix33::CMatrix33()
{
	eM11 = 1; eM12 = 0;
	eM21 = 0; eM22 = 1;
	eDx = 0; eDy = 0;
}

void CMatrix33::Identity()
{
	eM11 = 1; eM12 = 0;
	eM21 = 0; eM22 = 1;
	eDx = 0; eDy = 0;
}

void CMatrix33::Scale(float x, float y)
{
	eM11 = x; eM12 = 0;
	eM21 = 0; eM22 = y;
	eDx = 0; eDy = 0;
}

void CMatrix33::Rotate_R(float r)
{
	eM11 = cos(r); eM12 = sin(r);
	eM21 = -eM12; eM22 = eM11;
	eDx = 0; eDy = 0;
}

void CMatrix33::Rotate_A(float a)
{
	float r = a * 3.14f / 180.0f;
	eM11 = cos(r); eM12 = sin(r);
	eM21 = -eM12; eM22 = eM11;
	eDx = 0; eDy = 0;
}

void CMatrix33::Translate(float x, float y)
{
	eM11 = 1; eM12 = 0;
	eM21 = 0; eM22 = 1;
	eDx = x; eDy = y;
}

CMatrix33 CMatrix33::operator*(const CMatrix33& m)
{
	CMatrix33 m2;
	m2.eM11 = eM11 * m.eM11 + eM12 * m.eM21;
	m2.eM12 = eM11 * m.eM12 + eM12 * m.eM22;

	m2.eM21 = eM21 * m.eM11 + eM22 * m.eM21;
	m2.eM22 = eM21 * m.eM12 + eM22 * m.eM22;

	m2.eDx = eDx * m.eM11 + eDy * m.eM21 + m.eDx;
	m2.eDy = eDx * m.eM12 + eDy * m.eM22 + m.eDy;
	return m2;
}
