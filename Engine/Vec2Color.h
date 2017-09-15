#pragma once

#include "Vec2.h"
#include "Colors.h"

class Vec2Color
{
public:
	Vec2Color() {}
	Vec2Color( Vec2 v, Color c )
		:
		v(v),
		c(c)
	{}
	Vec2 v;
	Color c;
};