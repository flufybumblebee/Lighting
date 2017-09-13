#pragma once

#include "Vec4.h"
#include "Graphics.h"
class Triangle
{
public:
	Triangle() {}
	Triangle(Vec4* p0, Vec4* p1, Vec4* p2 )
		:
		p0(p0),
		p1(p1),
		p2(p2)
	{}
	Triangle( Triangle& tri )
		:
		p0(tri.p0),
		p1(tri.p1),
		p2(tri.p2)
	{}
	Triangle GetTriangle()
	{
		return Triangle(*this);
	}
public:
	Vec4* p0;
	Vec4* p1;
	Vec4* p2;
};
