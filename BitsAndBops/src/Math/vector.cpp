#include "vector.h"
#include <math.h>
Vector Vector::right()
{
	return Vector(1, 0);
}
Vector Vector::up()
{
	return Vector(0, 1);
}
Vector::Vector(float X, float Y)
{
	x = X;
	y = Y;
}

float Vector::Length() const
{
	return sqrt(x * x + y * y);
}

Vector Vector::Normaliz() const
{
	float len = sqrt(x * x + y * y);
	if(len == 0)
		return Vector();
	return Vector(x / len, y / len);
}

Vector Vector::operator+(const Vector& v) const
{
	return Vector(x + v.x, y + v.y);
}

void Vector::operator+=(const Vector& v)
{
	x += v.x;
	y += v.y;
}

Vector Vector::operator-(const Vector& v) const
{
	return Vector(x - v.x, y - v.y);
}

Vector Vector::operator-() const
{
	return Vector(-x, -y);
}

void Vector::operator-=(const Vector& v)
{
	x -= v.x;
	y -= v.y;
}

float Vector::operator*(const Vector& v) const
{
	return v.x * x + v.y * y;
}

Vector Vector::operator*(float f) const
{
	return Vector(x * f, y * f);
}

Vector Vector::operator/(float f) const
{
	if (f == 0)
		Vector(0, 0);
	return Vector(x / f, y / f);
}

float Vector::Angle(const Vector& v)
{
	float f1 = acos(x * v.x + y * v.y);
	return f1;
}
