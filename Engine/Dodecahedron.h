#pragma once

#include "Model.h"
#include "Vec4.h"

#include <cmath>

class Dodecahedron : public Model
{
public:
	Dodecahedron(const float& size = 1.0f)
	{
		const float goldenRatio = (1.0f + sqrt(5.0f)) / 2.0f;
		const float orangeX = size;
		const float orangeY = size;
		const float orangeZ = size;
		const float pinkX = size * goldenRatio;
		const float pinkY = 0.0f;
		const float pinkZ = size * (1/goldenRatio);
		const float greenX = 0.0f;
		const float greenY = size * (1 / goldenRatio);
		const float greenZ = size * goldenRatio;
		const float blueX = size * (1 / goldenRatio);
		const float blueY = size * goldenRatio;
		const float blueZ = 0.0f;

		vertices.emplace_back(-orangeX, -orangeY, -orangeZ, 1.0f); // 0
		vertices.emplace_back(-orangeX, -orangeY,  orangeZ, 1.0f); // 1
		vertices.emplace_back( orangeX, -orangeY,  orangeZ, 1.0f); // 2
		vertices.emplace_back( orangeX, -orangeY, -orangeZ, 1.0f); // 3
		vertices.emplace_back(-orangeX,  orangeY, -orangeZ, 1.0f); // 4
		vertices.emplace_back(-orangeX,  orangeY,  orangeZ, 1.0f); // 5
		vertices.emplace_back( orangeX,  orangeY,  orangeZ, 1.0f); // 6
		vertices.emplace_back( orangeX,  orangeY, -orangeZ, 1.0f); // 7

		vertices.emplace_back(-pinkX, pinkY, -pinkZ, 1.0f); // 8
		vertices.emplace_back(-pinkX, pinkY,  pinkZ, 1.0f); // 9
		vertices.emplace_back( pinkX, pinkY,  pinkZ, 1.0f); // 10
		vertices.emplace_back( pinkX, pinkY, -pinkZ, 1.0f); // 11

		vertices.emplace_back(greenX, -greenY, -greenZ, 1.0f); // 12
		vertices.emplace_back(greenX,  greenY, -greenZ, 1.0f); // 13
		vertices.emplace_back(greenX,  greenY,  greenZ, 1.0f); // 14
		vertices.emplace_back(greenX, -greenY,  greenZ, 1.0f); // 15

		vertices.emplace_back(-blueX, -blueY, blueZ, 1.0f); // 16
		vertices.emplace_back(-blueX,  blueY, blueZ, 1.0f); // 17
		vertices.emplace_back( blueX,  blueY, blueZ, 1.0f); // 18
		vertices.emplace_back( blueX, -blueY, blueZ, 1.0f); // 19

		indicesLine = {
			0,1, 1,2, 2,3, 3,0, //
			4,5, 5,6, 6,7, 7,4, // cube (orange)
			0,4, 1,5, 2,6, 3,7, //

			8,9, 9,10, 10,11, 11,8, // x axis plane (pink)
			12,13, 13,14, 14,15, 15,12, // z axis plane (green)
			16,17, 17,18, 18,19, 19,16 }; // y axis plane (blue)
	
		indicesTri = {
			0,8,4,
			0,4,12,
			12,4,13,

			4,17,18,
			4,18,13,
			13,18,7,

			12,13,7,
			12,7,3,
			3,7,11,

			0,12,3,
			0,3,16,
			16,3,19,

			3,11,10,
			3,10,19,
			19,10,2,

			11,7,18,
			11,18,10,
			10,18,6,

			9,5,17,
			9,17,8,
			8,17,4,

			1,5,9,
			1,14,5,
			1,15,14,

			14,6,18,
			14,18,5,
			5,18,17,

			9,8,0,
			9,0,1,
			1,0,16,

			19,1,16,
			19,15,1,
			19,2,15,

			10,6,14,
			10,14,2,
			2,14,15 };	
	}
};

