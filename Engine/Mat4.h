/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	Mat2.h																				  *
*	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once

#include "Vec3.h"
#include "Vec4.h"
#include <cmath>

template <typename T>
class _Mat4
{
public:
	_Mat4& operator=(const _Mat4& rhs)
	{
		memcpy(matrix, rhs.matrix, sizeof(matrix));
		return *this;
	}
	_Mat4& operator*=(T rhs)
	{
		for (auto& row : matrix)
		{
			for (T& i : row)
			{
				i *= rhs;
			}
		}
		return *this;
	}
	_Mat4 operator*(T rhs) const
	{
		_Mat4 result = *this;
		return result *= rhs;
	}
	_Mat4 operator*(const _Mat4& rhs) const
	{
		_Mat4 result;
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t k = 0; k < 4; k++)
			{
				T sum = (T)0.0;
				for (size_t i = 0; i < 4; i++)
				{
					sum += matrix[j][i] * rhs.matrix[i][k];
				}
				result.matrix[j][k] = sum;
			}
		}
		return result;
	}

	// -------------------------------------------------------
	// Transformation Matrixes

	static _Mat4 Identity()
	{
		return {
			(T)1.0, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, (T)1.0, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, (T)1.0, (T)0.0,
			(T)0.0, (T)0.0, (T)0.0, (T)1.0 };
	}

	static _Mat4 RotationX(T angle)
	{
		const T sinAngle = sin(angle);
		const T cosAngle = cos(angle);
		return {
			(T)1.0,    (T)0.0,   (T)0.0, (T)0.0,
			(T)0.0,  cosAngle, sinAngle, (T)0.0,
			(T)0.0, -sinAngle, cosAngle, (T)0.0,
			(T)0.0,    (T)0.0,   (T)0.0, (T)1.0	};
	}
	static _Mat4 RotationY(T angle)
	{
		const T sinAngle = sin(angle);
		const T cosAngle = cos(angle);

		return {
			cosAngle, (T)0.0,-sinAngle, (T)0.0,
			  (T)0.0, (T)1.0,   (T)0.0, (T)0.0,
			sinAngle, (T)0.0, cosAngle, (T)0.0,
			(T)0.0,   (T)0.0,   (T)0.0, (T)1.0 };
	}
	static _Mat4 RotationZ(T angle)
	{
		T sinAngle = sin(angle);
		T cosAngle = cos(angle);

		return {
			 cosAngle, sinAngle, (T)0.0, (T)0.0,
			-sinAngle, cosAngle, (T)0.0, (T)0.0,
			   (T)0.0,   (T)0.0, (T)1.0, (T)0.0,
			   (T)0.0,   (T)0.0, (T)0.0, (T)1.0	};
	}
	static _Mat4 Scaling(T scaleX, T scaleY, T scaleZ )
	{
		return {
			scaleX, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, scaleY, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, scaleZ, (T)0.0,
			(T)0.0, (T)0.0, (T)0.0, (T)1.0 };
	}
	static _Mat4 Translation(T x, T y, T z)
	{
		return {
			(T)1.0, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, (T)1.0, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, (T)1.0, (T)0.0,
			     x,      y,      z, (T)1.0 };
	}

	static _Mat4 Rotation(const _Vec3<T>& angle)
	{
		return _Mat4(RotationX(angle.x) * RotationY(angle.y) * RotationZ(angle.z));
	}
	static _Mat4 Scaling( const _Vec3<T>& scale )
	{
		return {
			scale.x,  (T)0.0,  (T)0.0, (T)0.0,
			 (T)0.0, scale.y,  (T)0.0, (T)0.0,
			 (T)0.0,  (T)0.0, scale.z, (T)0.0,
			 (T)0.0,  (T)0.0,  (T)0.0, (T)1.0 };
	}
	static _Mat4 Translation(const _Vec3<T>& pos)
	{
		return {
			(T)1.0, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, (T)1.0, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, (T)1.0, (T)0.0,
			 pos.x,  pos.y,  pos.z, (T)1.0 };
	}

	static _Mat4 Transformation( const _Vec3<T> angle, const _Vec3<T>& scale, const _Vec3<T> pos)
	{
		return _Mat4(Rotation(angle) * Scaling(scale) * Translation(pos));
	}

	// -------------------------------------------------------

	// Camera & Perspective Matrixes (unfinished)
	
	/*static _Mat4 Camera( const _Vec3<T>& pos, const _Vec3<T>& up, const _Vec3<T>& direction )
	{
		// stuff
		return {
			(T)1.0, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, (T)1.0, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, (T)1.0, (T)1.0,
			(T)0.0, (T)0.0, (T)0.0, (T)0.0 };
	}*/

	/*static _Mat4 Pespective( T nearDist, T farDist, T fov, T ratio )
	{
		T A = (T)1.0 / tan( fov / (T)2.0 );
		T B = ratio / tan( fov / (T)2.0 );
		T C = nearDist + farDist / nearDist - farDist;
		T D = (T)2.0 * (nearDist * farDist) / (nearDist - farDist);

		return {
			     A, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0,	     B, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0,		 C, (T)-1.0,
			(T)0.0, (T)0.0,      D, (T)0.0 };
	}*/

	// -------------------------------------------------------

public:
	// [ row ][ col ]
	T matrix[4][4];
};

template<typename T>
_Vec4<T>& operator*=(_Vec4<T>& lhs, const _Mat4<T>& rhs)
{
	return lhs = lhs * rhs;
}

template<typename T>
_Vec4<T> operator*(const _Vec4<T>& lhs, const _Mat4<T>& rhs)
{
	return
	{
		lhs.x * rhs.matrix[0][0] + lhs.y * rhs.matrix[1][0] + lhs.z * rhs.matrix[2][0] + lhs.w * rhs.matrix[3][0],
		lhs.x * rhs.matrix[0][1] + lhs.y * rhs.matrix[1][1] + lhs.z * rhs.matrix[2][1] + lhs.w * rhs.matrix[3][1],
		lhs.x * rhs.matrix[0][2] + lhs.y * rhs.matrix[1][2] + lhs.z * rhs.matrix[2][2] + lhs.w * rhs.matrix[3][2],
		lhs.x * rhs.matrix[0][3] + lhs.y * rhs.matrix[1][3] + lhs.z * rhs.matrix[2][3] + lhs.w * rhs.matrix[3][3]
	};
}

typedef _Mat4<float> Mat4;
typedef _Mat4<double> Mad4;