#pragma once

#include "Vec3.h"
#include <vector>
#include "IndexedLineList.h"

class Cube
{
public:
	Cube( const float size )
	{
		const float side = size / 2.0f;
		vertices.emplace_back( -side, -side, -side ); // 0
		vertices.emplace_back(  side, -side, -side ); // 1
		vertices.emplace_back( -side,  side, -side ); // 2
		vertices.emplace_back(  side,  side, -side ); // 3

		vertices.emplace_back( -side, -side, side ); // 4
		vertices.emplace_back(  side, -side, side ); // 5
		vertices.emplace_back( -side,  side, side ); // 6
		vertices.emplace_back(  side,  side, side ); // 7
	}

	IndexedLineList GetLines() const
	{
		return
		{
			vertices,
			{0,1, 1,3, 3,2, 2,0,
			 0,4, 1,5, 3,7, 2,6,
			 4,5, 5,7, 7,6, 6,4}
		};
	}
private:
	std::vector< Vec3 > vertices;
};