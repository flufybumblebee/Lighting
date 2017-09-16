#pragma once

#include "NewModel.h"

class HexPrism : public Model
{
public:
	HexPrism(const float size = 1.0f)
	{
		const float side = size / 2.0f;
		
		const float hex = sqrt( sq(side) - sq(side / 2) );	

		//		-(side/2)		(side/2)
		//
		//
		//
		//	-side			X--->		side
		//
		//
		//
		//		-(side/2)		(side/2)

		//		-hex		hex
		//
		//				^
		//				|
		//	0.0			Z			0.0
		//
		//
		//
		//		-hex		hex

		Vec4 v0  = {    -side,  side, 0.0f, 1.0f };
		Vec4 v1  = { -(side/2), side,  hex, 1.0f };
		Vec4 v2  = {  (side/2), side,  hex, 1.0f };
		Vec4 v3  = {      side, side, 0.0f, 1.0f };
		Vec4 v4  = {  (side/2), side, -hex, 1.0f };
		Vec4 v5  = { -(side/2), side, -hex, 1.0f };

		Vec4 v6  = {     -side, -side, 0.0f, 1.0f };
		Vec4 v7  = { -(side/2), -side,  hex, 1.0f };
		Vec4 v8  = {  (side/2), -side,  hex, 1.0f };
		Vec4 v9  = {      side, -side, 0.0f, 1.0f };
		Vec4 v10 = {  (side/2), -side, -hex, 1.0f };
		Vec4 v11 = { -(side/2), -side, -hex, 1.0f };

		//		1		2
		//
		//
		//	0		.		3
		//
		//
		//		5		4

		vertices.emplace_back(v0); // 0
		vertices.emplace_back(v1); // 1
		vertices.emplace_back(v2); // 2
		vertices.emplace_back(v3); // 3
		vertices.emplace_back(v4); // 4
		vertices.emplace_back(v5); // 5

		//		7		8
		//
		//
		//	6		.		9
		//
		//
		//		11		10

		vertices.emplace_back(v6); // 6
		vertices.emplace_back(v7); // 7
		vertices.emplace_back(v8); // 8
		vertices.emplace_back(v9); // 9
		vertices.emplace_back(v10); // 10
		vertices.emplace_back(v11); // 11

		indicesLine = {
			0,1, 1,2, 2,3, 3,4, 4,5, 5,0,		// top
			0,6, 1,7, 2,8, 3,9, 4,10, 5,11,		// middle
			6,7, 7,8, 8,9, 9,10, 10,11, 11,6 };	// bottom

		indicesTri = {
			0,1,2, 0,2,3,
			0,3,4, 0,4,5,

			0,7,1, 0,6,7,
			1,8,2, 1,7,8,
			2,9,3, 2,8,9,
			3,10,4, 3,9,10,
			4,11,5, 4,10,11,
			5,6,0, 5,11,6,

			6,8,7, 6,9,8,
			6,10,9, 6,11,10 };

	}

	/*IndexedLineList GetLines() const
	{
		return
		{
			vertices,{
			0,1, 1,2, 2,3, 3,4, 4,5, 5,0,

			0,6, 1,7, 2,8, 3,9, 4,10, 5,11,

			6,7, 7,8, 8,9, 9,10, 10,11, 11,6
			}
		};
	}

	IndexedTriangleList GetTriangles() const
	{
		return
		{
			vertices,{
				0,1,2, 0,2,3,
				0,3,4, 0,4,5,

				0,7,1, 0,6,7,
				1,8,2, 1,7,8,
				2,9,3, 2,8,9,
				3,10,4, 3,9,10,
				4,11,5, 4,10,11,
				5,6,0, 5,11,6,

				6,8,7, 6,9,8,
				6,10,9, 6,11,10	}
		};
	}
private:
	std::vector< Vec4 > vertices;*/
};
