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
		indicesLine = { 0,1, 0,2, 0,3 };
		indicesTri = { 1,2,3 };
	}
};