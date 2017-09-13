#pragma once

#include "Vec3.h"

template < typename T >
class _Vec4: public _Vec3<T>
{
public:
	_Vec4(){}
	_Vec4( T x, T y, T z, T w )
		:
		_Vec3(x, y, z),
		w(w)
	{}
	_Vec4(const _Vec4& vec)
		:
		_Vec3(vec.x, vec.y, vec.z),
		w(vec.w)
	{}
	_Vec4(const _Vec3& vec)
		:
		_Vec4(vec.x, vec.y, vec.z, (T)1.0)
	{}
	template <typename T2>
	explicit operator _Vec4<T2>() const
	{
		return{ (T2)x,(T2)y,(T2)z,(T2)w };
	}

	_Vec4&	operator+=(const _Vec4 &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}
	_Vec4&	operator-=(const _Vec4 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		//w -= rhs.w;
		return *this;
	}
	_Vec4	operator-(const _Vec4 &rhs) const
	{
		return _Vec4(*this) -= rhs;
	}
	//T		Dot(const _Vec4 &rhs) const
	//{
	//	return x * rhs.x + y * rhs.y + z * rhs.z;// +w * rhs.w;
	//}
	//_Vec4	Cross(const _Vec4& rhs) const
	//{
	//	return Vec4(
	//		y * rhs.z - z * rhs.y,
	//		z * rhs.x - x * rhs.z,
	//		x * rhs.y - y * rhs.x,
	//		1);
	//}

	_Vec4 Midpoint(const _Vec4 &rhs) const
	{
		/*return Vec4((x - rhs.x)/2, (y - rhs.y)/2, (z - rhs.z)/2, 1.0f );*/
		return (rhs + *this)/2;
	}

public:
	T w;
};

typedef _Vec4<float> Vec4;
