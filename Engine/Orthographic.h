#pragma once

#include "Vec4.h"
#include "Mat4.h"
#include <cmath>

class OrthoGraphic
{
public:
	OrthoGraphic(const float& fovX, const float& fovY, const float& nearDist, const float& farDist)
		:
		fovX(fovX),
		fovY(fovY),
		nearDist(nearDist),
		farDist(farDist)
	{}
	Mat4 Transform()
	{
		return {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f,	1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f };
	}
private:
	float fovX;
	float fovY;
	float nearDist;
	float farDist;
};
