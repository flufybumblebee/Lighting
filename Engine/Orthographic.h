#pragma once

#include "Vec4.h"
#include "Mat4.h"
#include <cmath>

class OrthoGraphic
{
public:
	OrthoGraphic(const float& nW, const float& nH, const float& nZ, const float& fZ)
		:
		nW(nW),
		nH(nH),
		nZ(nZ),
		fZ(fZ)
	{}
	Mat4 Transform()
	{
		return {
			2/nW, 0.0f, 0.0f, 0.0f,
			0.0f, 2/nH, 0.0f, 0.0f,
			0.0f, 0.0f,	1/(fZ-nZ), 0.0f,
			0.0f, 0.0f, nZ/(nZ-fZ), 1.0f };
	}
private:
	float nW;
	float nH;
	float nZ;
	float fZ;
};
