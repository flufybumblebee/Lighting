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

#include "Cube.h"
#include "HexPrism.h"
#include "Diamond.h"
#include "Plane.h"
#include "Grid.h"

#include "CameraTransform.h"

#include "TransformVariables.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
private:
	MainWindow&	wnd;
	Graphics	gfx;

	Cube		cube;
	HexPrism	hex;
	Diamond		diamond;
	Plane		plane;
	Grid		grid;

	CameraTransform cam;

	Vec3 angle    = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 scale    = Vec3(1.0f, 1.0f, 1.0f);
	Vec3 position = Vec3(0.0f, 0.0f, 2.0f);
	
	TransformVariables gridVar;

	/*float fov = PI / 2.0f;
	float ratio = Graphics::ScreenWidth / Graphics::ScreenHeight;
	float nearDist = 1.0f;
	float farDist = 10.0f;*/
};