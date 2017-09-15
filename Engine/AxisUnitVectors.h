#pragma once

#include "Model.h"
#include "Vec4.h"

class AxisUnitVectors : public Model
{
public:
	AxisUnitVectors()
	{
		vertices.emplace_back(0.0f, 0.0f, 0.0f, 1.0f);
		vertices.emplace_back(1.0f, 0.0f, 0.0f, 1.0f);
		vertices.emplace_back(0.0f, 1.0f, 0.0f, 1.0f);
		vertices.emplace_back(0.0f, 0.0f, 1.0f, 1.0f);
	}

	IndexedLineList GetLines() const override
	{
		return { vertices,{0,1, 0,2, 0,3} };
	}

	IndexedTriangleList GetTriangles() const override
	{
		return  { vertices,{ 1,2,3 } };
	}
private:
	std::vector<Vec4> vertices;
	std::vector<size_t> indicesLine;
	std::vector<size_t> indicesTri;
};