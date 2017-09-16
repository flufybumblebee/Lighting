#pragma once

#include "Model.h"

class Plane: public Model
{
public:
	Plane( const float& size = 1.0f )
	{
		const float side = size / 2.0f;
		vertices.emplace_back( -side, 0.0f,  side, 1.0f); // 0
		vertices.emplace_back(  side, 0.0f,  side, 1.0f); // 1
		vertices.emplace_back(  side, 0.0f, -side, 1.0f); // 2
		vertices.emplace_back( -side, 0.0f, -side, 1.0f); // 3

		indicesLine = { 0,1, 1,2, 2,3, 3,0 };

		indicesTri = { 2,1,0, 3,2,0, 0,1,2, 0,2,3 };
	}
	/*IndexedLineList GetLines() const
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
	std::vector<Vec4> vertices;*/
};
