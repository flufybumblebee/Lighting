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
	// ---------------------------------------
	// rotation

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

	//-----------------------------------------
	// translation

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x_offset = x_offset -= 0.01f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x_offset = x_offset += 0.01f;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y_offset = y_offset += 0.01f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y_offset = y_offset -= 0.01f;
	}
	
	if( wnd.kbd.KeyIsPressed( 'R' ) )
	{
		z_offset = z_offset += 0.01f;
	}
	else if( wnd.kbd.KeyIsPressed( 'F' ) )
	{
		z_offset = z_offset -= 0.01f;
	}
}

void Game::ComposeFrame()
{
	Mat3 rotation = Mat3::RotationZ( angleZ ) * Mat3::RotationY( angleY ) * Mat3::RotationX( angleX );
	
	// ----------------------------------
	// Environment

	auto linesE = e.GetLines();	

	for (auto& v : linesE.vertices)
	{
		//v *= rotation;
		v += { 0.0f, 0.0f, 2.001f };
		trans.Transform(v);
	}

	for (auto i = linesE.indices.begin(),
		end = linesE.indices.end();
		i != end; std::advance(i, 2))
	{
		gfx.DrawLine(
			linesE.vertices[*i],
			linesE.vertices[*std::next(i)],
			Colors::White);
	}

	// ----------------------------------------
	// Cube

	auto linesCube = cube.GetLines();

	/*for (auto i = linesCube.vertices.begin(),
		end = linesCube.vertices.end();
		i != end; i++)
	{
		*i *= rotation;
		*i += { x_offset, y_offset, z_offset };
		trans.Transform(*i);
	}*/

	for( auto& v : linesCube.vertices )
	{
		v *= rotation;
		v += { x_offset, y_offset, z_offset };
		trans.Transform( v );
	}

	for(auto i = linesCube.indices.begin(),
		end = linesCube.indices.end();
		i != end; i+=2)
	{
		gfx.DrawLine(
			linesCube.vertices[*i],
			linesCube.vertices[*(i+1)],
			Colors::White);
	}

	/*for( auto i = linesCube.indices.begin(),
		 end = linesCube.indices.end();
		 i != end; std::advance( i, 2 ) )
	{
		gfx.DrawLine(
			linesCube.vertices[ *i ],
			linesCube.vertices[ *std::next( i ) ],
			Colors::White );
	}*/

	// ----------------------------------------------
}