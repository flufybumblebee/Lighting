#pragma once

#include "IndexedLineList.h"
#include "IndexedTriangleList.h"
#include <vector>

class Model
{
public:
	virtual IndexedLineList GetLines() const = 0;
	virtual IndexedTriangleList GetTriangles() const = 0;
};
