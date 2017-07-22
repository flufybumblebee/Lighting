#pragma once

#include "Vec3.h"
#include <vector>
#include "IndexedLineList.h"

class Environment
{
public:
	Environment()
	{
		vertices.emplace_back(-1.0f,  1.0f, -1.0f); // 0
		vertices.emplace_back( 1.0f,  1.0f, -1.0f); // 1
		vertices.emplace_back( 1.0f, -1.0f, -1.0f); // 2
		vertices.emplace_back(-1.0f, -1.0f, -1.0f); // 3

		vertices.emplace_back(-1.0f,  1.0f, 1.0f); // 0
		vertices.emplace_back( 1.0f,  1.0f, 1.0f); // 1
		vertices.emplace_back( 1.0f, -1.0f, 1.0f); // 2
		vertices.emplace_back(-1.0f, -1.0f, 1.0f); // 3
	}

	IndexedLineList GetLines() const
	{
		return
		{
			vertices,
			{ 0,1, 1,2, 2,3, 3,0,
			0,4, 1,5, 3,7, 2,6,
			4,5, 5,6, 6,7, 7,4 }
		};
	}
private:
	std::vector< Vec3 > vertices;
};
