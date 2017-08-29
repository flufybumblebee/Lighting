#pragma once

#include "Vec4.h"
#include "Mat4.h"
#include <cmath>

class Perspective
{
public:
	Perspective(const float& fovX, const float& fovY, const float& nZ, const float& fZ)
		:
		fovX(fovX),
		fovY(fovY),
		nZ(nZ),
		fZ(fZ)
	{}
	Mat4 Transform()
	{
		float x = 1.0f / tan(fovX*0.5f);
		float y = 1.0f / tan(fovY*0.5f);
		float z = fZ / (fZ - nZ);
		float w = -z * nZ;

		return {
			   x, 0.0f, 0.0f, 0.0f,
			0.0f,	 y, 0.0f, 0.0f,
			0.0f, 0.0f,	   z, 1.0f,
			0.0f, 0.0f,    w, 0.0f };
	}
private:
	float fovX;
	float fovY;
	float nZ;
	float fZ;
};

