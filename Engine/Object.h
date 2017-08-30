#pragma once

#include "Graphics.h"
#include "Vec3.h"
#include "Camera.h"
#include "Perspective.h"
#include "Viewport.h"

class Object
{
public:
	virtual void Update(const Vec3& scale, const Vec3& angle, const Vec3& position) = 0;
	virtual void Draw( Camera& cam, Perspective& per, Viewport& port, Graphics& gfx ) const = 0;
};