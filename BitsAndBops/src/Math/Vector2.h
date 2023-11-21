#pragma once
#include <cmath>
struct Vector2
{
	float x{ 0.0f };
	float y{ 0.0f };

	Vector2() = default;
	Vector2(float x, float y)
		:x(x),y(y)
	{}

	void operator+=(const Vector2 other)
	{
		this->x += other.x;
		this->y += other.y;
	}

	void operator-=(const Vector2 other)
	{
		this->x -= other.x;
		this->y -= other.y;
	}

	void operator*=(const float f)
	{
		this->x *= f;
		this->y *= f;
	}

	void operator/=(const float f)
	{
		this->x /= f;
		this->y /= f;
	}

	Vector2 operator-() const
	{
		return Vector2(-this->x, -this->y);
	}

	inline float GetMagnitude()
	{
		return sqrtf(GetSqrMagnitude());
	}

	inline float GetSqrMagnitude()
	{
		return x * x + y * y;
	}

	inline void Normalize()
	{
		(*this) /= GetMagnitude();
	}

	inline Vector2 GetNormalized()
	{
		float length = GetMagnitude();
		return Vector2(x / length, y / length);
	}

	inline static float dot(const Vector2& a, const Vector2& b)
	{
		return a.x * b.x + a.y * b.y;
	}

};

inline Vector2 operator+(const Vector2& a, const Vector2& b)
{
	return Vector2(a.x+b.x,a.y+b.y);
}
inline Vector2 operator-(const Vector2& a, const Vector2& b)
{
	return Vector2(a.x - b.x, a.y - b.y);
}

inline Vector2 operator*(const Vector2& a, float f)
{
	return Vector2(a.x * f, a.y * f);
}
inline Vector2 operator/(const Vector2& a, float f)
{
	return Vector2(a.x / f, a.y / f);
}
inline Vector2 operator*(float f, const Vector2& a)
{
	return Vector2(a.x * f, a.y * f);
}
