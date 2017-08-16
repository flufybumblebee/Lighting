#pragma once

#include <vector>
#include "Vec4.h"
#include "IndexedLineList.h"
#include "IndexedTriangleList.h"

class Cube
{
public:
	Cube( const float size )
	{
		const float side = size / 2.0f;

		vertices.emplace_back( -side, -side, -side, 1.0f ); // 0
		vertices.emplace_back(  side, -side, -side, 1.0f ); // 1
		vertices.emplace_back( -side,  side, -side, 1.0f ); // 2
		vertices.emplace_back(  side,  side, -side, 1.0f ); // 3

		vertices.emplace_back( -side, -side, side, 1.0f ); // 4
		vertices.emplace_back(  side, -side, side, 1.0f ); // 5
		vertices.emplace_back( -side,  side, side, 1.0f ); // 6
		vertices.emplace_back(  side,  side, side, 1.0f ); // 7
	}

	IndexedLineList GetLines() const
	{
		return
		{
			vertices,{
			0,1, 1,3, 3,2, 2,0,
			0,4, 1,5, 3,7, 2,6,
			4,5, 5,7, 7,6, 6,4 }
		};
	}

	IndexedTriangleList GetTriangles() const
	{
		return
		{
			vertices,{
			0,2,1, 2,3,1,
			1,3,5, 3,7,5,
			2,6,3, 3,6,7,
			4,5,7, 4,7,6,
			0,4,6, 0,6,2,
			0,5,4, 0,1,5 }
		};
	}
private:
	std::vector< Vec4 > vertices;
};
