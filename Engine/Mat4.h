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

	static _Mat4 Scaling(const T scale)
	{
		return {
			 scale, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0,  scale, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0,  scale, (T)0.0,
			(T)0.0, (T)0.0, (T)0.0, (T)1.0 };
	}
	static _Mat4 Scaling(const T scaleX, const T scaleY, const T scaleZ)
	{
		return {
			scaleX, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, scaleY, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, scaleZ, (T)0.0,
			(T)0.0, (T)0.0, (T)0.0, (T)1.0 };
	}
	static _Mat4 Scaling(const _Vec3<T>& scale)
	{
		return {
			scale.x, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, scale.y, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, scale.z, (T)0.0,
			(T)0.0, (T)0.0, (T)0.0, (T)1.0 };
	}

	static _Mat4 RotationX(const T angle)
	{
		const T sinAngle = sin(angle);
		const T cosAngle = cos(angle);
		return {
			(T)1.0,    (T)0.0,   (T)0.0, (T)0.0,
			(T)0.0,  cosAngle, sinAngle, (T)0.0,
			(T)0.0, -sinAngle, cosAngle, (T)0.0,
			(T)0.0,    (T)0.0,   (T)0.0, (T)1.0	};
	}
	static _Mat4 RotationY(const T angle)
	{
		const T sinAngle = sin(angle);
		const T cosAngle = cos(angle);

		return {
			cosAngle, (T)0.0,-sinAngle, (T)0.0,
			  (T)0.0, (T)1.0,   (T)0.0, (T)0.0,
			sinAngle, (T)0.0, cosAngle, (T)0.0,
			(T)0.0,   (T)0.0,   (T)0.0, (T)1.0 };
	}
	static _Mat4 RotationZ(const T angle)
	{
		const T sinAngle = sin(angle);
		const T cosAngle = cos(angle);

		return {
			 cosAngle, sinAngle, (T)0.0, (T)0.0,
			-sinAngle, cosAngle, (T)0.0, (T)0.0,
			   (T)0.0,   (T)0.0, (T)1.0, (T)0.0,
			   (T)0.0,   (T)0.0, (T)0.0, (T)1.0	};
	}
	static _Mat4 Rotation(const T angleX, const T angleY, const T angleZ)
	{
		return _Mat4(RotationX(angleX) * RotationY(angleY) * RotationZ(angleZ));
	}
	static _Mat4 Rotation(const _Vec3<T>& angle)
	{
		return _Mat4(RotationX(angle.x) * RotationY(angle.y) * RotationZ(angle.z));
	}

	static _Mat4 Translation(const T x, const  T y, const  T z)
	{
		return {
			(T)1.0, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, (T)1.0, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, (T)1.0, (T)0.0,
			     x,      y,      z, (T)1.0 };
	}
	static _Mat4 Translation(const _Vec3<T>& pos)
	{
		return {
			(T)1.0, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, (T)1.0, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, (T)1.0, (T)0.0,
			 pos.x,  pos.y,  pos.z, (T)1.0 };
	}

	static _Mat4 Transformation(_Vec3<T> scale, const _Vec3<T> angle, const _Vec3<T> pos)
	{
		return _Mat4(Scaling(scale) * Rotation(angle) * Translation(pos));
	}

	// -------------------------------------------------------

	// Camera, Perspective, Orthographic, & Viewport Matrixes
	
	static _Mat4 Camera( const _Vec3<T>& position, const _Vec3<T>& lookAt, const _Vec3<T>& up )
	{
		const _Vec3<T> zAxis = (lookAt - position).Normalize();
		const _Vec3<T> xAxis = (up.Cross( zAxis )).Normalize();
		const _Vec3<T> yAxis = zAxis.Cross( xAxis );
		
		return {
			xAxis.x, yAxis.x, zAxis.x, (T)0.0,
			xAxis.y, yAxis.y, zAxis.y, (T)0.0,
			xAxis.z, yAxis.z, zAxis.z, (T)0.0,
			-(xAxis.Dot(position)), -(yAxis.Dot(position)), -(zAxis.Dot(position)), (T)1.0, };
	}
	static _Mat4 Pespective(const T fovX, const T fovY, const T nZ, const T fZ)
	{
		const T x = (T)1.0 / tan(fovX*(T)0.5);
		const T y = (T)1.0 / tan(fovY*(T)0.5);
		const T z = fZ / (fZ - nZ);
		const T w = -z * nZ;

		return {
			     x, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0,	     y, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0,		 z, (T)1.0,
			(T)0.0, (T)0.0,      w, (T)0.0 };
	}
	static _Mat4 Orthographic( const float& nW, const float& nH, const float& nZ, const float& fZ )
	{
		return {
			2 / nW, 0.0f, 0.0f, 0.0f,
			0.0f, 2 / nH, 0.0f, 0.0f,
			0.0f, 0.0f,	1 / (fZ - nZ), 0.0f,
			0.0f, 0.0f, nZ / (nZ - fZ), 1.0f };
	}
	static _Mat4 Viewport(const T x, const T y, const T width, const T height )
	{
		const T Ax = width / 2;
		const T Ay = height / 2;
		const T Bx = x + Ax;
		const T By = y + Ay;
		return {
			  Ax, 0.0f, 0.0f, 0.0f,
			0.0f,  -Ay, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			  Bx,   By, 0.0f, 1.0f,
		};
	}
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
