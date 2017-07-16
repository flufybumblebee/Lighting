/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	plane( 1.0f ),
	cube( 1.0f )
{

}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if( wnd.kbd.KeyIsPressed( 'Q' ) )
	{
		angleZ = angleZ - 0.01f;
	}
	else if( wnd.kbd.KeyIsPressed( 'A' ) )
	{
		angleZ = angleZ + 0.01f;
	}

	if( wnd.kbd.KeyIsPressed( 'W' ) )
	{
		angleY = angleY - 0.01f;
	}
	else if( wnd.kbd.KeyIsPressed( 'S' ) )
	{
		angleY = angleY + 0.01f;
	}

	if( wnd.kbd.KeyIsPressed( 'E' ) )
	{
		angleX = angleX - 0.01f;
	}
	else if( wnd.kbd.KeyIsPressed( 'D' ) )
	{
		angleX = angleX + 0.01f;
	}

	if( wnd.kbd.KeyIsPressed( 'R' ) )
	{
		scale = scale += 0.01f;
	}
	else if( wnd.kbd.KeyIsPressed( 'F' ) )
	{
		scale = scale -= 0.01f;
	}
}

void Game::ComposeFrame()
{
	Mat3 rotation = Mat3::RotationZ( angleZ ) * Mat3::RotationY( angleY ) * Mat3::RotationX( angleX );

	auto lines = cube.GetLines();

	for( auto& v : lines.vertices )
	{
		v *= rotation;
		v += { 0.0f, 0.0f, scale };
		trans.Transform( v );
	}

	for( auto i = lines.indices.begin(),
		 end = lines.indices.end();
		 i != end; std::advance( i, 2 ) )
	{
		gfx.DrawLine(
			lines.vertices[ *i ],
			lines.vertices[ *std::next( i ) ],
			Colors::White );

		// optional: makes it easier to understand
		if( false )
		{
			gfx.DrawLine(
				lines.vertices[*i],
				Vec2(Graphics::ScreenWidth / 2.0f, Graphics::ScreenHeight / 2.0f),
				Colors::White);
		}
	}
}