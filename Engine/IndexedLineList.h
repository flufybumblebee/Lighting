#pragma once

#include <vector>
#include "Vec4.h"

struct IndexedLineList
{
	std::vector<Vec4> vertices;
	std::vector<unsigned int> indices;
	//std::vector<size_t> indices;
};
