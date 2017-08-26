#pragma once

#include "Vec4.h"
#include "Mat4.h"

class Viewport
{
public:
	Viewport(const float& x, const float& y, const float& width, const float& height)
		:
		x( x ),
		y( y ),
		width( width ),
		height( height )
	{}
	void Set(const float& x, const float& y, const float& width, const float& height )
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	Mat4 Transform()
	{
		float Ax = width / 2;
		float Ay = height / 2;
		float Bx = x + Ax;
		float By = y + Ay;
		return {
			  Ax, 0.0f, 0.0f, 0.0f,
			0.0f,  -Ay, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			  Bx,   By, 0.0f, 1.0f,
		};
	}
private:
	float x;
	float y;
	float width;
	float height;
};