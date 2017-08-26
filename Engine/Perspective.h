#pragma once

#include "Vec4.h"
#include "Mat4.h"
#include <cmath>

class Perspective
{
public:
	Perspective(const float& fovX, const float& fovY, const float& nearDist, const float& farDist)
		:
		fovX(fovX),
		fovY(fovY),
		nearDist(nearDist),
		farDist(farDist)
	{}
	Mat4 Transform()
	{
		float x = 1.0f / tan(fovX*0.5f);
		float y = 1.0f / tan(fovY*0.5f);
		float z = farDist / (farDist - nearDist);
		float w = -z * nearDist;

		return {
			   x, 0.0f, 0.0f, 0.0f,
			0.0f,	 y, 0.0f, 0.0f,
			0.0f, 0.0f,	   z, 1.0f,
			0.0f, 0.0f,    w, 0.0f };
	}
private:
	float fovX;
	float fovY;
	float nearDist;
	float farDist;
};

