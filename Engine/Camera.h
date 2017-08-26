#pragma once

#include "Vec3.h"
#include "Mat4.h"

class Camera
{
public:
	Camera( const Vec3& position, const Vec3& lookAt, const Vec3& up )
		:
		position( position ),
		lookAt( lookAt ),
		up( up )
	{}
	~Camera(){};
	void Update(const Vec3& position, const Vec3& lookAt, const Vec3& up)
	{
		this->position = position;
		this->lookAt = lookAt;
		this->up = up;
	}
	Mat4 Transform()
	{
		Vec3 zAxis = (lookAt - position).Normalize();
		Vec3 xAxis = (up.Cross(zAxis)).Normalize();
		Vec3 yAxis = zAxis.Cross(xAxis);

		return {
			xAxis.x, yAxis.x, zAxis.x, 0.0f,
			xAxis.y, yAxis.y, zAxis.y, 0.0f,
			xAxis.z, yAxis.z, zAxis.z, 0.0f,
			-(xAxis.Dot(position)), -(yAxis.Dot(position)), -(zAxis.Dot(position)), 1.0f, };
	}
	Vec3 GetPosition() const { return position; }
	Vec3 GetLookAt() const { return lookAt; }
	Vec3 GetUp() const { return up; }
private:
	Vec3 position;
	Vec3 lookAt;
	Vec3 up;
};
