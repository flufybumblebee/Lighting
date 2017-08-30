#pragma once

#include "Vec4.h"
#include <vector>
#include "Model.h"
//#include "IndexedLineList.h"
//#include "IndexedTriangleList.h"

class Grid : public Model
{
public:
	Grid(float size)
	{
		const float bSize = size / 10.0f;

		// -x to x
		vertices.emplace_back(-(bSize * 5), 0.0f,  (bSize * 5), 1.0f); //  0
		vertices.emplace_back( (bSize * 5), 0.0f,  (bSize * 5), 1.0f); //  1

		vertices.emplace_back(-(bSize * 5), 0.0f,  (bSize * 4), 1.0f); //  2
		vertices.emplace_back( (bSize * 5), 0.0f,  (bSize * 4), 1.0f); //  3

		vertices.emplace_back(-(bSize * 5), 0.0f,  (bSize * 3), 1.0f); //  4
		vertices.emplace_back( (bSize * 5), 0.0f,  (bSize * 3), 1.0f); //  5

		vertices.emplace_back(-(bSize * 5), 0.0f,  (bSize * 2), 1.0f); //  6
		vertices.emplace_back( (bSize * 5), 0.0f,  (bSize * 2), 1.0f); //  7

		vertices.emplace_back(-(bSize * 5), 0.0f,  (bSize * 1), 1.0f); //  8
		vertices.emplace_back( (bSize * 5), 0.0f,  (bSize * 1), 1.0f); //  9

		vertices.emplace_back(-(bSize * 5), 0.0f,         0.0f, 1.0f); // 10
		vertices.emplace_back( (bSize * 5), 0.0f,         0.0f, 1.0f); // 11

		vertices.emplace_back(-(bSize * 5), 0.0f, -(bSize * 1), 1.0f); // 12
		vertices.emplace_back( (bSize * 5), 0.0f, -(bSize * 1), 1.0f); // 13

		vertices.emplace_back(-(bSize * 5), 0.0f, -(bSize * 2), 1.0f); // 14
		vertices.emplace_back( (bSize * 5), 0.0f, -(bSize * 2), 1.0f); // 15

		vertices.emplace_back(-(bSize * 5), 0.0f, -(bSize * 3), 1.0f); // 16
		vertices.emplace_back( (bSize * 5), 0.0f, -(bSize * 3), 1.0f); // 17

		vertices.emplace_back(-(bSize * 5), 0.0f, -(bSize * 4), 1.0f); // 18
		vertices.emplace_back( (bSize * 5), 0.0f, -(bSize * 4), 1.0f); // 19

		vertices.emplace_back(-(bSize * 5), 0.0f, -(bSize * 5), 1.0f); // 20
		vertices.emplace_back( (bSize * 5), 0.0f, -(bSize * 5), 1.0f); // 21

		// z to z-
		vertices.emplace_back(-(bSize * 5), 0.0f,  (bSize * 5), 1.0f); // 22
		vertices.emplace_back(-(bSize * 5), 0.0f, -(bSize * 5), 1.0f); // 23

		vertices.emplace_back(-(bSize * 4), 0.0f,  (bSize * 5), 1.0f); // 24
		vertices.emplace_back(-(bSize * 4), 0.0f, -(bSize * 5), 1.0f); // 25

		vertices.emplace_back(-(bSize * 3), 0.0f,  (bSize * 5), 1.0f); // 26
		vertices.emplace_back(-(bSize * 3), 0.0f, -(bSize * 5), 1.0f); // 27

		vertices.emplace_back(-(bSize * 2), 0.0f,  (bSize * 5), 1.0f); // 28
		vertices.emplace_back(-(bSize * 2), 0.0f, -(bSize * 5), 1.0f); // 29

		vertices.emplace_back(-(bSize * 1), 0.0f,  (bSize * 5), 1.0f); // 30
		vertices.emplace_back(-(bSize * 1), 0.0f, -(bSize * 5), 1.0f); // 31

		vertices.emplace_back(        0.0f, 0.0f,  (bSize * 5), 1.0f); // 32
		vertices.emplace_back(        0.0f, 0.0f, -(bSize * 5), 1.0f); // 33

		vertices.emplace_back( (bSize * 1), 0.0f,  (bSize * 5), 1.0f); // 34
		vertices.emplace_back( (bSize * 1), 0.0f, -(bSize * 5), 1.0f); // 35

		vertices.emplace_back( (bSize * 2), 0.0f,  (bSize * 5), 1.0f); // 36
		vertices.emplace_back( (bSize * 2), 0.0f, -(bSize * 5), 1.0f); // 37

		vertices.emplace_back( (bSize * 3), 0.0f,  (bSize * 5), 1.0f); // 38
		vertices.emplace_back( (bSize * 3), 0.0f, -(bSize * 5), 1.0f); // 39

		vertices.emplace_back( (bSize * 4), 0.0f,  (bSize * 5), 1.0f); // 40
		vertices.emplace_back( (bSize * 4), 0.0f, -(bSize * 5), 1.0f); // 41

		vertices.emplace_back( (bSize * 5), 0.0f,  (bSize * 5), 1.0f); // 42
		vertices.emplace_back( (bSize * 5), 0.0f, -(bSize * 5), 1.0f); // 43
	}
	IndexedLineList GetLines() const override
	{
		return
		{
			vertices, {
				0,1,
				2,3,
				4,5,
				6,7,
				8,9,
				10,11,
				12,13,
				14,15,
				16,17,
				18,19,
				20,21,
			
				22,23,
				24,25,
				26,27,
				28,29,
				30,31,
				32,33,
				34,35,
				36,37,
				38,39,
				40,41,
				42,43 }
		};
	}
	IndexedTriangleList GetTriangles() const override
	{
		return IndexedTriangleList(vertices, { 0,1,2 });
	}

public:
	std::vector<Vec4> vertices;
};
