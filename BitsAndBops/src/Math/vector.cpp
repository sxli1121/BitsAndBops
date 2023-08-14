#include "vector.h"
#include <math.h>
CVector CVector::left()
{
	return CVector(-1, 0);
}
CVector CVector::up()
{
	return CVector(0, -1);
}
CVector::CVector(float X, float Y)
{
	x = X;
	y = Y;
}

float CVector::Length() const
{
	return sqrt(x * x + y * y);
}

CVector CVector::Normaliz() const
{
	float len = sqrt(x * x + y * y);
	if(len == 0)
		return CVector();
	return CVector(x / len, y / len);
}

CVector CVector::operator+(const CVector& v) const
{
	return CVector(x + v.x, y + v.y);
}

void CVector::operator+=(const CVector& v)
{
	x += v.x;
	y += v.y;
}

CVector CVector::operator-(const CVector& v) const
{
	return CVector(x - v.x, y - v.y);
}

CVector CVector::operator-() const
{
	return CVector(-x, -y);
}

void CVector::operator-=(const CVector& v)
{
	x -= v.x;
	y -= v.y;
}

float CVector::operator*(const CVector& v) const
{
	return v.x * x + v.y * y;
}

CVector CVector::operator*(float f) const
{
	return CVector(x * f, y * f);
}

CVector CVector::operator/(float f) const
{
	if (f == 0)
		CVector(0, 0);
	return CVector(x / f, y / f);
}

float CVector::Angle(const CVector& v)
{
	float f1 = acos(x * v.x + y * v.y);
	return f1;
}
