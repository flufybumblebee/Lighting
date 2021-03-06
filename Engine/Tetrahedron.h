#pragma once

#include "Model.h"

#include <cmath>

class Tetrahedron : public Model
{
public:
	Tetrahedron(const float& size = 1.0f)
	{
		float side = sqrt(sq(size) - sq(size / 2));
		const float little = size / 2 * tan(PI / 6);
		const float large = side - little;

		vertices.emplace_back(-(size/2), -little, -little, 1.0f); // 0
		vertices.emplace_back(  0.0f, -little,   large, 1.0f); // 1
		vertices.emplace_back( size/2, -little, -little, 1.0f); // 2
		vertices.emplace_back(  0.0f,   large,    0.0f, 1.0f); // 3

		indicesLine = {	0,1, 1,2, 2,0, 0,3,	1,3, 2,3 };

		indicesTri = { 2,1,0, 0,3,2, 1,3,0, 2,3,1 };
	}
};

