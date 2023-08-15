#pragma once

class Vector
{
public:
	float x;
	float y;

	static Vector right();
	static Vector up();

	Vector(float X = 0, float Y = 0);
	float Length()const;
	Vector Normaliz()const;
	Vector operator+(const Vector& v)const;
	void operator+=(const Vector& v);
	Vector operator-(const Vector& v)const;
	Vector operator-()const;
	void operator-=(const Vector& v);
	float operator*(const Vector& v)const;
	Vector operator*(float f)const;
	Vector operator/(float f)const;
	float Angle(const Vector& v);
};

inline Vector operator*(float f, const Vector& v)
{
	return Vector(v.x * f, v.y * f);
}
