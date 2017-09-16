#pragma once

#include <cmath>
#include "Model.h"

class Frustum : public Model
{
public:
	Frustum(const float& fovX = PI/2, const float& fovY = PI / 2, const float& nZ = 0.1f, const float& fZ = 10.0f )
	{
		float nX = nZ * tan(fovX / 2);
		float nY = nZ * tan(fovY / 2);
		float fX = fZ * tan(fovX / 2);
		float fY = fZ * tan(fovY / 2);

		vertices.emplace_back(0.0f, 0.0f, 0.0f, 1.0f); // 0

		//near plane
		vertices.emplace_back(-nX,  nY, nZ, 1.0f); // 1
		vertices.emplace_back( nX,  nY, nZ, 1.0f); // 2
		vertices.emplace_back( nX, -nY, nZ, 1.0f); // 3
		vertices.emplace_back(-nX, -nY, nZ, 1.0f); // 4

		// far plane
		vertices.emplace_back(-fX,  fY, fZ, 1.0f); // 5
		vertices.emplace_back( fX,  fY, fZ, 1.0f); // 6
		vertices.emplace_back( fX, -fY, fZ, 1.0f); // 7
		vertices.emplace_back(-fX, -fY, fZ, 1.0f); // 8

		indicesLine = {
			0,1, 0,2, 0,3, 0,4,
			1,2, 2,3, 3,4, 4,1,
			1,5, 2,6, 3,7, 4,8,
			5,6, 6,7, 7,8, 8,5 };

		indicesTri = { 0,1,2 };
	}
};

