#pragma once

class CVector
{
public:
	float x;
	float y;

	static CVector left();
	static CVector up();
	CVector(float X = 0, float Y = 0);
	float Length()const;
	CVector Normaliz()const;
	CVector operator+(const CVector& v)const;
	void operator+=(const CVector& v);
	CVector operator-(const CVector& v)const;
	CVector operator-()const;
	void operator-=(const CVector& v);
	float operator*(const CVector& v)const;
	CVector operator*(float f)const;
	CVector operator/(float f)const;
	//两个向量的夹角
	float angle(const CVector& v);
};

inline CVector operator*(float f, const CVector& v)
{
	return CVector(v.x * f, v.y * f);
}
