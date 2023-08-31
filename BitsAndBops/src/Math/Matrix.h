#pragma once

#include "Vector3.h"
#include "Vector2.h"
#include <cmath>

	struct Matrix3f;
	Matrix3f operator*(const Matrix3f& a, const Matrix3f& b);
	Vector2 operator*(const Matrix3f& m, const Vector2& v);

	// row-major
	struct Matrix3f
	{
		union
		{
			float data[9]{ 1,0,0,0,1,0,0,0,1 };
			Vector3 rows[3];
		};
		
		float& operator()(int row, int col)
		{
			return data[col+3*row];
		}

		const float& operator()(int row, int col) const
		{
			return data[col + 3 * row];
		}

		inline static Matrix3f Translate(const Vector2& v)
		{
			Matrix3f m{
				1,	  0,	v.x,
				0,	  1,	v.y,
				0,	  0,    1
			};
			return m;
		}

		inline static Matrix3f Scale(const Vector2& v)
		{
			Matrix3f m{
				v.x,0, 0,
				0,v.y, 0,
				0, 0, 1
			};
			return m;
		}

		inline static Matrix3f Rotate(float radian)
		{
			Matrix3f m{
				cos(radian),-sin(radian), 0,
				sin(radian),cos(radian), 0,
				0, 0, 1
			};
			return m;
		}

		inline static Matrix3f Inverse(const Matrix3f& m)
		{
			// computes the inverse of a matrix m
			double det = m(0, 0) * (m(1, 1) * m(2, 2) - m(2, 1) * m(1, 2)) -
				m(0, 1) * (m(1, 0) * m(2, 2) - m(1, 2) * m(2, 0)) +
				m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0));

			double invdet = 1 / det;

			Matrix3f minv; // inverse of matrix m
			minv(0, 0) = (m(1, 1) * m(2, 2) - m(2, 1) * m(1, 2)) * invdet;
			minv(0, 1) = (m(0, 2) * m(2, 1) - m(0, 1) * m(2, 2)) * invdet;
			minv(0, 2) = (m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1)) * invdet;
			minv(1, 0) = (m(1, 2) * m(2, 0) - m(1, 0) * m(2, 2)) * invdet;
			minv(1, 1) = (m(0, 0) * m(2, 2) - m(0, 2) * m(2, 0)) * invdet;
			minv(1, 2) = (m(1, 0) * m(0, 2) - m(0, 0) * m(1, 2)) * invdet;
			minv(2, 0) = (m(1, 0) * m(2, 1) - m(2, 0) * m(1, 1)) * invdet;
			minv(2, 1) = (m(2, 0) * m(0, 1) - m(0, 0) * m(2, 1)) * invdet;
			minv(2, 2) = (m(0, 0) * m(1, 1) - m(1, 0) * m(0, 1)) * invdet;
			
			return minv;
		}

		inline static Matrix3f TSR(const Vector2& translation, const Vector2& scale = { 1,1 }, float rotation = 0.0f)
		{
			Matrix3f t = Translate(translation);
			Matrix3f s = Scale(scale);
			Matrix3f r = Rotate(rotation);
			return t * s * r;
		}

		static Matrix3f Identity;
	};

	
	inline Matrix3f operator*(const Matrix3f& a, const Matrix3f& b)
    {
	    Matrix3f c;
		for (size_t row = 0; row < 3; row++)
		{
			for (size_t col = 0; col < 3; col++)
			{
				c(row, col) = 
					  a(row, 0) * b(0, col) 
					+ a(row, 1) * b(1, col)
					+ a(row, 2) * b(2, col);
			}
		}
		return c;
    }

	inline static Vector3 operator*(const Matrix3f& m, const Vector3& v)
	{
		Vector3 c;
		c.x = v.x * m(0, 0) + v.y * m(0, 1) + v.z * m(0, 2);
		c.y = v.x * m(1, 0) + v.y * m(1, 1) + v.z * m(1, 2);
		c.z = v.x * m(2, 0) + v.y * m(2, 1) + v.z * m(2, 2);
		return c;
	}
	inline static Vector2 operator*(const Matrix3f& m, const Vector2& v)
	{
		Vector2 c;
		c.x = v.x * m(0, 0) + v.y * m(0, 1) + 1.0f * m(0, 2);
		c.y = v.x * m(1, 0) + v.y * m(1, 1) + 1.0f * m(1, 2);
		return c;
	}

