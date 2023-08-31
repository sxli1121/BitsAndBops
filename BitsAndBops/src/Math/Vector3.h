#pragma once
#include <cmath>

struct Vector3
{
	float x{ 0.0f };
	float y{ 0.0f };
	float z{ 0.0f };

	Vector3() = default;
	Vector3(float x, float y,float z)
		:x(x), y(y),z(z)
	{}

	Vector3 operator+=(const Vector3 other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	Vector3 operator-=(const Vector3 other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	Vector3 operator*=(const float f)
	{
		this->x *= f;
		this->y *= f;
		this->z *= f;
	}

	Vector3 operator/=(const float f)
	{
		this->x /= f;
		this->y /= f;
		this->z /= f;
	}

	inline float GetMagnitude()
	{
		return sqrtf(GetSqrMagnitude());
	}

	inline float GetSqrMagnitude()
	{
		return x * x + y * y + z*z;
	}

	inline void Normalize()
	{
		(*this) /= GetMagnitude();
	}

	inline Vector3 GetNormalized()
	{
		float length = GetMagnitude();
		return Vector3(x / length, y / length,z/length);
	}

	inline static float dot(const Vector3& a, const Vector3& b)
	{
		return a.x * b.x + a.y * b.y;
	}

};

inline Vector3 operator+(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x + b.x, a.y + b.y,a.z+b.z);
}
inline Vector3 operator-(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x - b.x, a.y - b.y,a.z-b.z);
}

inline Vector3 operator*(const Vector3& a, float f)
{
	return Vector3(a.x * f, a.y * f,a.z*f);
}
inline Vector3 operator/(const Vector3& a, float f)
{
	return Vector3(a.x / f, a.y / f,a.z/f);
}
inline Vector3 operator*(float f, const Vector3& a)
{
	return a * f;
}