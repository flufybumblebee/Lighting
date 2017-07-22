#pragma once

#include "Vec3.h"
#include <vector>
#include "IndexedLineList.h"

class Star
{
public:
	Star()
	{
		vertices.emplace_back(0.0f, 0.0f, -0.25f); // 0

		vertices.emplace_back(0.0f,  0.75f,   0.0f); // 1
		vertices.emplace_back(0.25f,  0.25f, 0.0f); // 2
		vertices.emplace_back(0.75f,   0.0f,  0.0f); // 3
		vertices.emplace_back(0.25f, -0.25f, 0.0f); // 4

		vertices.emplace_back( 0.0f,  -0.75f,  0.0f); // 5
		vertices.emplace_back(-0.25f, -0.25f, 0.0f); // 6
		vertices.emplace_back(-0.75f,   0.0f,  0.0f); // 7
		vertices.emplace_back(-0.25f,  0.25f, 0.0f); // 8
	}

	IndexedLineList GetLines() const
	{
		return
		{
			vertices,
			{ 0,1, 0,2, 0,3, 0,4,
			0,5, 0,6, 0,7, 0,8,

			1,2, 2,3, 3,4, 4,5,
			5,6, 6,7, 7,8, 8,1}
		};
	}
private:
	std::vector< Vec3 > vertices;
};
