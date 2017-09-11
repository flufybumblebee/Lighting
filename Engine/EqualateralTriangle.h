#pragma once

#include "Model.h"
#include "Vec4.h"
#include "Mat4.h"
#include <vector>
#include <cmath>

class EqualateralTriangle : public Model
{
public:
	EqualateralTriangle( const float& size )
	{
		float side = sqrt(sq(size) - sq(size / 2));
		const float little = size/2 * tan(PI / 6);
		const float large = side - little;

		vertices.emplace_back(0.0f, large, 0.0f, 1.0f); // 0
		vertices.emplace_back(large, -little, 0.0f, 1.0f); // 1
		vertices.emplace_back(-large, -little, 0.0f, 1.0f); // 2

		indicesLines.emplace_back(0);
		indicesLines.emplace_back(1);
		indicesLines.emplace_back(1);
		indicesLines.emplace_back(2);
		indicesLines.emplace_back(2);
		indicesLines.emplace_back(0);

		indicesTriangles.emplace_back(0);
		indicesTriangles.emplace_back(1);
		indicesTriangles.emplace_back(2);
	}
	
	IndexedLineList GetLines() const override
	{
		return { vertices, indicesLines };
	}

	IndexedTriangleList GetTriangles() const override
	{
		return { vertices, indicesTriangles };
	}
private:
	std::vector<Vec4> vertices;
	std::vector<size_t> indicesLines;
	std::vector<size_t> indicesTriangles;
};


