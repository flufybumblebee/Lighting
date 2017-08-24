#pragma once

#include "Vec3.h"

class TransformVariables
{
public:
	TransformVariables() {}
	TransformVariables( Vec3 angle, Vec3 scale, Vec3 position )
		:
		angle( angle ),
		scale( scale ),
		position( position )
	{}
	void SetRotation(float x_angle, float y_angle, float z_angle)
	{
		angle.x = x_angle;
		angle.y = y_angle;
		angle.z = z_angle;
	}
	void SetScale(float x_scale, float y_scale, float z_scale)
	{
		scale.x = x_scale;
		scale.y = y_scale;
		scale.z = z_scale;
	}
	void SetPosition(float x_position, float y_position, float z_position)
	{
		position.x = x_position;
		position.y = y_position;
		position.z = z_position;
	}

public:
	Vec3 angle;
	Vec3 scale;
	Vec3 position;
};
