#pragma once

#include "Model.h"

class Octahedron : public Model
{
public:
	Octahedron(const float& size = 1.0f)
	{
		float side = sqrt(size) / 2.0f;

		vertices.emplace_back( 0.0f,  side,  0.0f, 1.0f); // 0
		vertices.emplace_back(-side,  0.0f,  0.0f, 1.0f); // 1
		vertices.emplace_back( 0.0f,  0.0f,  side, 1.0f); // 2
		vertices.emplace_back( side,  0.0f,  0.0f, 1.0f); // 3
		vertices.emplace_back( 0.0f,  0.0f, -side, 1.0f); // 4
		vertices.emplace_back( 0.0f, -side,  0.0f, 1.0f); // 5

		indicesLine = {
			0,1, 0,2, 0,3, 0,4,
			1,2, 2,3, 3,4, 4,1,
			5,1, 5,2, 5,3, 5,4 };

		indicesTri = {
			0,1,2, 0,2,3,
			0,3,4, 0,4,1,
			5,2,1, 5,3,2,
			5,4,3, 5,1,4 };
	}

	/*IndexedLineList GetLines() const
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
	}*/
};
