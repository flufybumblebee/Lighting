#pragma once
template < typename T >
class _Vec4
{
public:
	_Vec4( T x, T y, T z, T w )
		:
		x(x),y(y),z(z),w(w)
	{}
public:
	T x;
	T y;
	T z;
	T w;
};

typedef _Vec4<float> Vec4;
