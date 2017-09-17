/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	Game.h																				  *
*	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
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

#include "Graphics.h"
#include "Colors.h"

#include "ViewTransform.h"

//#include "Model.h"

#include "Grid.h"
#include "Frustum.h"
#include "Terrain.h"
#include "EqualateralTriangle.h"
#include "Plane.h"

#include "Tetrahedron.h"
#include "Cube.h"
#include "Octahedron.h"
#include "Dodecahedron.h"
#include "Icosahedron.h"

#include "Mat4.h"
#include "Model.h"

#include "Triangle.h"
#include "AxisUnitVectors.h"

#include "Vec2Color.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();

	void Scale(const float& speed);
	void Angle(const float& speed);
	void Position(const float& speed);
	void Light(const float& speed);
	void Camera();

	Model Tessellate(const Model& model);

	void DrawFlat(bool lines, bool triangles, const Mat4& trans, const Model& model, const Vec3& modelColor, const Vec3& ambientColor, const Vec3& lightColor, const Vec3& lightPosition);
	void DrawGouraud(const Mat4& trans, const Model& model, const Vec3& modelColor, const Vec3& ambientColor, const Vec3& lightColor, const Vec3& lightPosition);
	void DrawPhong(
		const Mat4&		trans,
		const Model&	model,
		const Vec3&		modelColor,
		const Vec3&		ambientColor,
		const float&	ambientCoefficient,
		const float&	diffuseCoefficient,
		const float&	specularCoefficient,
		const float&	specularExponent,
		const Vec3&		lightColor,
		const Vec3&		lightPosition,
		const float&	lightRadius,
		const Vec3&		cameraPosition);
	void DrawTriangleThreeColor(const Vec2Color& v0, const Vec2Color& v1, const Vec2Color& v2);
	void DrawFlatBottomTriangleThreeColor(const Vec2Color& A, const Vec2Color& B, const Vec2Color& C);
	void DrawFlatTopTriangleThreeColor(const Vec2Color& A, const Vec2Color& B, const Vec2Color& C);

	void DrawCrossHair(const Color& c);
	void DrawViewport(const Color& c);
private:
	MainWindow&	wnd;
	Graphics	gfx;

	//------------------------------------------------------------

	// camera variables
	Vec3 cameraPosition	= { 0.0f, 0.0f, 0.0f };
	Vec3 cameraLookAt	= { 0.0f, 0.0f, 0.0f };
	Vec3 cameraUp		= { 0.0f, 0.0f, 0.0f };

	Vec3 cameraPos0		= { 0.0f, 0.0f, -3.0f };
	Vec3 cameraLookAt0	= { 0.0f, 0.0f,  0.0f };
	Vec3 cameraUp0		= { 0.0f, 1.0f,  0.0f };

	Vec3 cameraPos1		= { 3.0f, 3.0f, -10.0f };
	Vec3 cameraLookAt1	= { 0.0f, 0.0f,   0.0f };
	Vec3 cameraUp1		= { 0.0f, 1.0f,   0.0f };

	bool isCam0 = true;
	bool keyIsPressed = false;

	// --------------------------------------------

	ViewTransform view;	

	// model transform variables
	Vec3 scale    = { 1.0f, 1.0f, 1.0f };
	Vec3 angle    = { 0.0f, 0.0f, 0.0f };
	Vec3 position = { 0.0f, 0.0f, 0.0f };

	// perspective variables
	const float fovX = PI/2;
	const float fovY = PI/2;
	const float nZ = 1.0f;
	const float fZ = 10.0f;
	const float nW = 2 * (nZ * tan(fovX / 2));
	const float nH = 2 * (nZ * tan(fovY / 2));

	// viewport variables
	const float vX = 0.0f;
	const float vY = 0.0f;
	const float vW = (float)Graphics::ScreenWidth  / 1.0f - 1.0f;
	const float vH = (float)Graphics::ScreenHeight / 1.0f - 1.0f;
	
	//-------------------------------------------------------

	// models
	AxisUnitVectors axis;
	Plane plane;
	Grid grid;
	Frustum frustum;
	Terrain terrain;
	EqualateralTriangle tri;
	Tetrahedron tetra;
	Cube cube;
	Octahedron octa;
	Dodecahedron dodeca;
	Icosahedron icosa;

	Model polyhedron24;
	Model polyhedron96;
	Model polyhedron384;
	Model polyhedron1536;

	Model polyhedron32;
	Model polyhedron128;
	Model polyhedron512;
	Model polyhedron2048;

	Model polyhedron48;

	Model polyhedron80;
	Model polyhedron320;
	Model polyhedron1280;
	Model polyhedron5120;
	// ---------------------------------------------------------
	
	// light variables

	Vec4 lightPosition = { 5.0f, 5.0f, -5.0f, 1.0f };

	// color variables
	const Vec3	modelColor			= { 0.0f,1.0f,1.0f };
	const Vec3	ambientColor		= { 0.1f,0.1f,0.1f };
	const float ambientCoefficient	= 1.0f;
	const float diffuseCoefficient	= 1.0f;
	const float specularCoefficient = 1.0f;
	const float specularExponent	= 1.0f;
	const Vec3	lightColor			= { 1.0f,1.0f,1.0f };
	const float lightRadius			= 5.0f;
};