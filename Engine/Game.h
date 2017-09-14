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

#include "Model.h"

#include "Grid.h"
#include "Frustum.h"
#include "Terrain.h"
#include "EqualateralTriangle.h"

#include "Tetrahedron.h"
#include "Cube.h"
#include "Octahedron.h"
#include "Dodecahedron.h"
#include "Icosahedron.h"

#include "Mat4.h"
#include "NewModel.h"

#include "Triangle.h"

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
	void DrawModel(bool lines, bool triangles, const Mat4& trans, const Model& model, const Vec3& modelColor, const Vec3& ambientColor, const Vec3& lightColor, const Vec3& lightPosition);
	NewModel Tessellate(const Model& model);
private:
	MainWindow&	wnd;
	Graphics	gfx;

	//------------------------------------------------------------

	// camera matrix variables
	Vec3 cameraPos;
	Vec3 cameraLookAt;
	Vec3 cameraUp;

	Vec3 cameraPos0;
	Vec3 cameraLookAt0;
	Vec3 cameraUp0;

	Vec3 cameraPos1;
	Vec3 cameraLookAt1;
	Vec3 cameraUp1;

	bool isCam0 = true;
	bool keyIsPressed = false;

	// --------------------------------------------

	ViewTransform view;	

	// model transform variables
	Vec3 scale    = { 1.0f, 1.0f, 1.0f };
	Vec3 angle    = { 0.0f, 0.0f, 0.0f };
	Vec3 position = { 0.0f, 0.0f, 0.0f };

	// perspective matrix variables
	const float fovX = PI/2;
	const float fovY = PI/2;
	const float nZ = 1.0f;
	const float fZ = 10.0f;
	const float nW = 2 * (nZ * tan(fovX / 2));
	const float nH = 2 * (nZ * tan(fovY / 2));

	// viewport matrix variables
	const float vX = 0.0f;
	const float vY = 0.0f;
	const float vW = (float)Graphics::ScreenWidth / 1 - 1;
	const float vH = (float)Graphics::ScreenHeight / 1 - 1;
	
	//-------------------------------------------------------

	// models
	Grid grid;
	Frustum frustum;
	Cube cube;
	Terrain terrain;
	EqualateralTriangle tri;
	Icosahedron icosa;
	Octahedron octa;
	Tetrahedron tetra;
	Dodecahedron dodeca;
	NewModel polyhedron80;
	NewModel polyhedron320;
	NewModel polyhedron1280;
	NewModel polyhedron5120;
	NewModel polyhedron32;
	NewModel polyhedron128;
	NewModel polyhedron512;
	NewModel polyhedron2048;
	NewModel polyhedron24;
	NewModel polyhedron96;
	NewModel polyhedron384;
	NewModel polyhedron1536;
	// ---------------------------------------------------------
	Vec4 lightsource;

	float lightX;
	float lightY;
	float lightZ;
};