#pragma once

#include <cmath>
#include <vector>

#include "Vec4.h"
#include "Model.h"
//#include "IndexedLineList.h"
//#include "IndexedTriangleList.h"

class Frustum : public Model
{
public:
	Frustum(const float& fovX, const float& fovY, const float& nZ, const float& fZ )
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
	}

	IndexedLineList GetLines() const override
	{
		return
		{
			vertices,{
				0,1, 0,2, 0,3, 0,4,
				1,2, 2,3, 3,4, 4,1,
				1,5, 2,6, 3,7, 4,8,
				5,6, 6,7, 7,8, 8,5 }
		};
	}

	IndexedTriangleList GetTriangles() const override
	{
		return
		{
			vertices,{ 0,1,2 }
		};
	}
private:
	std::vector< Vec4 > vertices;
};

