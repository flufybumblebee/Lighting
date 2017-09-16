#pragma once

#include "Model.h"
#include "Vec4.h"

#include <cmath>

class Icosahedron : public Model
{
public:
	Icosahedron(const float& size = 1.0f)
	{
		const float goldenRatio = (1.0f + sqrt(5.0f)) / 2.0f;
		const float little = size / 2.0f;
		const float large = (size * goldenRatio) / 2.0f;

		Model::vertices.emplace_back(-large, -little, 0.0f, 1.0f); // 0
		vertices.emplace_back(-large, little, 0.0f, 1.0f); // 1
		vertices.emplace_back(large, little, 0.0f, 1.0f); // 2
		vertices.emplace_back(large, -little, 0.0f, 1.0f); // 3

		vertices.emplace_back(-little, 0.0f, -large, 1.0f); // 4
		vertices.emplace_back(little, 0.0f, -large, 1.0f); // 5
		vertices.emplace_back(little, 0.0f, large, 1.0f); // 6
		vertices.emplace_back(-little, 0.0f, large, 1.0f); // 7

		vertices.emplace_back(0.0f, -large, -little, 1.0f); // 8
		vertices.emplace_back(0.0f, -large, little, 1.0f); // 9
		vertices.emplace_back(0.0f, large, little, 1.0f); // 10
		vertices.emplace_back(0.0f, large, -little, 1.0f); // 11

		indicesLine = {
			0,1, 1,2, 2,3, 3,0,
			4,5, 5,6, 6,7, 7,4,
			8,9, 9,10, 10,11, 11,8 };

		indicesTri = {
			9, 7, 0,
			9, 0, 8,
			0, 4, 8,
			7, 1, 0,
			0, 1, 4,
			1, 10, 11,
			1, 7, 10,
			4, 1, 11,
			11, 10, 2,
			6, 2, 10,
			11, 2, 5,
			2, 6, 3,
			5, 2, 3,
			3, 6, 9,
			5, 3, 8,
			8, 3, 9,
			8, 4, 5,
			4, 11, 5,
			10, 7, 6,
			9, 6, 7	};
	}
};
