#pragma once

#include "Vec3.h"
#include <vector>
#include "IndexedLineList.h"

class Plane
{
public:
	Plane( float size )
	{
		const float side = size / 2.0f;
		vertices.emplace_back( -side,  side, 0.0f );
		vertices.emplace_back(  side,  side, 0.0f );
		vertices.emplace_back(  side, -side, 0.0f );
		vertices.emplace_back( -side, -side, 0.0f );
	}
	IndexedLineList GetLines()
	{
		return
		{
			vertices,
			{ 0,1, 1,2, 2,3, 3,0 }
		};
	}
public:
	std::vector<Vec3> vertices;
};
