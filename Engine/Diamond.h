#pragma once


#include "Model.h"
#include <vector>
#include "Vec3.h"

class Diamond : public Model
{
public:
	Diamond(const float size)
	{
		const float side = size / 2.0f;
		const float zero = 0.0f;

		vertices.emplace_back( zero,  side,  zero); // 0
		vertices.emplace_back(-side,  zero,  side); // 1
		vertices.emplace_back( side,  zero,  side); // 2
		vertices.emplace_back( side,  zero, -side); // 3
		vertices.emplace_back(-side,  zero, -side); // 4
		vertices.emplace_back( zero, -side,  zero); // 5
	}

	IndexedLineList GetLines() const
	{
		return
		{
			vertices,{
				0,1, 0,2, 0,3, 0,4,
				1,2, 2,3, 3,4, 4,1,
				5,1, 5,2, 5,3, 5,4 }
		};
	}

	IndexedTriangleList GetTriangles() const
	{
		return
		{
			vertices,{
				0,1,2, 0,2,3,
				0,3,4, 0,4,1,
				5,2,1, 5,3,2,
				5,4,3, 5,1,4 }
		};
	}
private:
	std::vector< Vec3 > vertices;
};
