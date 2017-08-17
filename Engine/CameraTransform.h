#pragma once

#include "Vec4.h"
#include "Graphics.h"

class CameraTransform
{
public:
	Vec4& Transform(Vec4& v) const
	{
		const float zInv = 1.0f / v.z;

		v.x = (v.x * zInv + 1.0f) * float((Graphics::ScreenWidth) / 2.0f);
		v.y = (-v.y * zInv + 1.0f) * float((Graphics::ScreenHeight) / 2.0f);

		/*// no z still but factored out to use simpler formulas
		v.x = (  v.x + 1.0f ) * float( ( Graphics::ScreenWidth  ) / 2.0f );
		v.y = ( -v.y + 1.0f ) * float( ( Graphics::ScreenHeight ) / 2.0f );*/

		/*// no z but basic formula for transforming to screen space from ndc space
		v.x = (  v.x * ( Graphics::ScreenWidth  / 2.0f ) + ( Graphics::ScreenWidth  / 2.0f ) );
		v.y = ( -v.y * ( Graphics::ScreenHeight / 2.0f ) + ( Graphics::ScreenHeight / 2.0f ) );*/
		return v;
	}
};
