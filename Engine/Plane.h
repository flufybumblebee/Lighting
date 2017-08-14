#pragma once

#include "Model.h"
#include "Vec3.h"
#include <vector>

class Plane: public Model
{
public:
	Plane( float size )
	{
		const float side = size / 2.0f;
		vertices.emplace_back( -side, 0.0f,  side ); // 0
		vertices.emplace_back(  side, 0.0f,  side ); // 1
		vertices.emplace_back(  side, 0.0f, -side ); // 2
		vertices.emplace_back( -side, 0.0f, -side ); // 3
	}
	IndexedLineList GetLines() const
	{
		return
		{
			vertices,
			{ 0,1, 1,2, 2,3, 3,0 }
		};
	}

	IndexedTriangleList GetTriangles() const
	{
		return
		{
			vertices,{
				2,1,0, 3,2,0,
				0,1,2, 0,2,3 }
		};
	}
public:
	std::vector<Vec3> vertices;
};
