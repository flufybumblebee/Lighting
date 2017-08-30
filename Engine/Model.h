#pragma once

#include "IndexedLineList.h"
#include "IndexedTriangleList.h"

class Model
{
public:
	virtual IndexedLineList GetLines() const = 0;
	virtual IndexedTriangleList GetTriangles() const = 0;
};
