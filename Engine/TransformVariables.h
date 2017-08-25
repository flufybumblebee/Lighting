#pragma once

#include "Vec3.h"

class TransformVariables
{
public:
	TransformVariables() {}
	TransformVariables( const Vec3& scale, const Vec3& angle, const Vec3& position )
		:
		scale( scale ),
		angle( angle ),
		position( position )
	{}
	void SetScale( const float& scale_x, const float& scale_y, const float& scale_z)
	{
		scale.x = scale_x;
		scale.y = scale_y;
		scale.z = scale_z;
	}
	void SetScale(const Vec3& scale)
	{
		this->scale.x = scale.x;
		this->scale.y = scale.y;
		this->scale.z = scale.z;
	}
	void SetRotation(const float& x_angle, const float& y_angle, const float& z_angle)
	{
		angle.x = x_angle;
		angle.y = y_angle;
		angle.z = z_angle;
	}
	void SetRotation( const Vec3& angle )
	{
		this->angle.x = angle.x;
		this->angle.y = angle.y;
		this->angle.z = angle.z;
	}
	void SetPosition(const float& x_position, const float& y_position, const float& z_position)
	{
		position.x = x_position;
		position.y = y_position;
		position.z = z_position;
	}
	void SetPosition(const Vec3& position)
	{
		this->position.x = position.x;
		this->position.y = position.y;
		this->position.z = position.z;
	}

public:
	Vec3 scale;
	Vec3 angle;
	Vec3 position;
};
