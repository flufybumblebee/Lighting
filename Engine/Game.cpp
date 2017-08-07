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

#include "Mat2.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	cube( 1.0f ),
	pic( Surface::FromFile( L"mario.png" ) )
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
	/*for( unsigned int y = 0; y < pic.GetHeight(); y++ )
		for (unsigned int x = 0; x < pic.GetWidth(); x++)
			gfx.PutPixel(x, y, pic.GetPixel(x, y));*/

	const Mat3 rotate =
		Mat3::RotationZ(angleZ) *
		Mat3::RotationY(angleY) *
		Mat3::RotationX(angleX);

	const Vec3 translate = { x_offset, y_offset, z_offset };

	/*const Color colors[12] =
	{
		Colors::Magenta,
		Colors::Magenta,
		Colors::Red,
		Colors::Red,
		Colors::Blue,
		Colors::Blue,
		Colors::Green,
		Colors::Green,
		Colors::Yellow,
		Colors::Yellow,
		Colors::Cyan,
		Colors::Cyan
	};*/

	const Color colors[12] =
	{
		Colors::Magenta,
		Colors::Red,
		Colors::Cyan,
		Colors::White,
		Colors::Blue,
		Colors::LightBlue,
		Colors::Green,
		Colors::LightGreen,
		Colors::LightGray,
		Colors::Gray,
		Colors::Orange,
		Colors::Yellow
	};
	
	// ----------------------------------------
	// Landscape
	//for( unsigned int y = 0; y < 320; y++ )
	//	for (unsigned int x = 0; x < 640; x++)
	//		gfx.PutPixel(x, y, Colors::White );

	// Triangle Drawing with Cube ( multi color )

	auto cubeTri = cube.GetTriangles();

	for (auto i = cubeTri.vertices.begin(),
	end = cubeTri.vertices.end();
	i != end; i++)
	{
	*i *= rotate;
	*i += translate;
	trans.Transform(*i);
	}

	for (int i = 0, end = cubeTri.indices.size() / 3;
		i != end; i++)
	{
		gfx.DrawTriangle(
			cubeTri.vertices[cubeTri.indices[i * 3 + 0] ],
			cubeTri.vertices[cubeTri.indices[i * 3 + 1] ],
			cubeTri.vertices[cubeTri.indices[i * 3 + 2] ],
			colors[i]);
	}

	/*// Triangle Drawing with Cube ( one color )

	auto cubeTri = cube.GetTriangles();

	for (auto i = cubeTri.vertices.begin(),
		   end = cubeTri.vertices.end();
		 i != end; i++)
	{
		*i *= rotate;
		*i += translate;
		trans.Transform(*i);
	}

	for (auto i = cubeTri.indices.begin(),
		end = cubeTri.indices.end();
		i != end; std::advance(i, 3))
	{
		gfx.DrawTriangle( cubeTri.vertices[*i],
						  cubeTri.vertices[*std::next(i)],
						  cubeTri.vertices[*std::next(i+1)],
						  Colors::White);
	}*/
	
	
	

	//// ----------------------------------------
	//// Cube ( with Backface Culling )
	//{
	//	if (drawTriangles)
	//	{
	//		auto cubeTriangles = cube.GetTriangles();
	//
	//		for (auto& v : cubeTriangles.vertices)
	//		{
	//			v *= rotate;
	//			v += translate;
	//		}
	//
	//		// set cullflags
	//		for (size_t i = 0, end = cubeTriangles.indices.size() / 3;
	//			i < end; i++)
	//		{
	//			const Vec3& v0 = cubeTriangles.vertices[cubeTriangles.indices[i * 3 + 0]];
	//			const Vec3& v1 = cubeTriangles.vertices[cubeTriangles.indices[i * 3 + 1]];
	//			const Vec3& v2 = cubeTriangles.vertices[cubeTriangles.indices[i * 3 + 2]];
	//			cubeTriangles.cullflags[i] = (v1 - v0).Cross(v2 - v0) * v0 > 0;
	//		}
	//
	//		for (auto& v : cubeTriangles.vertices)
	//		{
	//			trans.Transform(v);
	//		}
	//
	//		for (size_t i = 0, end = cubeTriangles.indices.size() / 3; i < end; i++)
	//		{
	//			if (!cubeTriangles.cullflags[i])
	//			{
	//				gfx.DrawTriangle(
	//					cubeTriangles.vertices[cubeTriangles.indices[i * 3 + 0]],
	//					cubeTriangles.vertices[cubeTriangles.indices[i * 3 + 1]],
	//					cubeTriangles.vertices[cubeTriangles.indices[i * 3 + 2]],
	//					colors[i]);
	//			}
	//		}
	//	}
	//}
	////------------------------------------------------------------------
	
	if (drawLines)
	{
		auto cubeLines = cube.GetLines();
	
		for (auto i = cubeLines.vertices.begin(),
			end = cubeLines.vertices.end();
			i != end; i++)
		{
			*i *= rotate;
			*i += translate;
			trans.Transform(*i);
		}
	
		for (auto i = cubeLines.indices.begin(),
			end = cubeLines.indices.end();
			i != end; std::advance(i, 2))
		{
			gfx.DrawLine(
				cubeLines.vertices[*i],
				cubeLines.vertices[*std::next(i)],
				Colors::Black);
		}
	}
	//---------------------------------------------------------------------

	/*// Triangle Drawing Function Test 2D
	
	const Vec2 v0 = { -100.0f, -100.0f };
	const Vec2 v1 = {  100.0f, -100.0f };
	const Vec2 v2 = { -100.0f,  100.0f };

	const Vec2 v3 = {  100.0f, -100.0f };
	const Vec2 v4 = {  100.0f,  100.0f };
	const Vec2 v5 = { -100.0f,  100.0f };

	gfx.DrawTriangle(
		(v0 * Mat2::Rotation(angleZ)) + Vec2{ 320, 320 },
		(v1 * Mat2::Rotation(angleZ)) + Vec2{ 320, 320 },
		(v2 * Mat2::Rotation(angleZ)) + Vec2{ 320, 320 },
		Colors::White);

	gfx.DrawTriangle(
		(v3 * Mat2::Rotation(angleZ) ) + Vec2{ 320, 320 },
		(v4 * Mat2::Rotation(angleZ) ) + Vec2{ 320, 320 },
		(v5 * Mat2::Rotation(angleZ) ) + Vec2{ 320, 320 },
		Colors::Gray);*/
}