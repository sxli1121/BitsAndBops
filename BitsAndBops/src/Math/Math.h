#pragma once

#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Matrix.h"

#include<cmath>

namespace Math
{
	inline constexpr float pi = 3.141592654f;
	constexpr float Deg2Rad(float deg)
	{
		return  pi / 180.0f * deg;
	}

	constexpr float Rad2Deg(float rad)
	{
		return 180.0f / pi * rad;
	}
}