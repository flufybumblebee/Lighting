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

#include "Vec4.h"
#include "Mat4.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	cube(    1.0f ),
	hex(     1.0f ),
	diamond( 1.0f ),
	plane(   1.0f ),
	grid(	 1.0f )
{
	cubeVar.SetRotation(0.0f, 0.0f, 0.0f);
	cubeVar.SetScale(scale);
	cubeVar.SetPosition(0.0f, 0.5f, 2.0f);

	gridVar.SetRotation(0.0f, 0.0f, 0.0f );
	gridVar.SetScale(3.0f,3.0f,3.0f);
	gridVar.SetPosition(0.0f, 0.0f, 2.0f);
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
	
	//-----------------------------------------
	// scaling 

	// scale x
	if (wnd.kbd.KeyIsPressed('T'))
	{
		cubeVar.scale.x = cubeVar.scale.x + 0.01f;
	}
	else if (wnd.kbd.KeyIsPressed('G'))
	{	
		cubeVar.scale.x = cubeVar.scale.x - 0.01f;
		if (cubeVar.scale.x < 0.0f) { cubeVar.scale.x = 0.0f; }
	}

	// scale y
	if (wnd.kbd.KeyIsPressed('Y'))
	{
		cubeVar.scale.y = cubeVar.scale.y + 0.01f;
	}
	else if (wnd.kbd.KeyIsPressed('H'))
	{
		cubeVar.scale.y = cubeVar.scale.y - 0.01f;
		if (cubeVar.scale.y < 0.0f) { cubeVar.scale.y = 0.0f; }
	}

	// scale z
	if (wnd.kbd.KeyIsPressed('U'))
	{
		cubeVar.scale.z = cubeVar.scale.z + 0.01f;
	}
	else if (wnd.kbd.KeyIsPressed('J'))
	{
		cubeVar.scale.z = cubeVar.scale.z - 0.01f;
		if (cubeVar.scale.z < 0.0f) { cubeVar.scale.z = 0.0f; }
	}
	// ---------------------------------------
	// rotation

	// rotate around X
	if( wnd.kbd.KeyIsPressed( 'Q' ) )
	{
		angle.x -= 0.02f;
	}
	else if( wnd.kbd.KeyIsPressed( 'A' ) )
	{
		angle.x += 0.02f;
	}

	// rotate around Y
	if( wnd.kbd.KeyIsPressed( 'W' ) )
	{
		angle.y -= 0.02f;
	}
	else if( wnd.kbd.KeyIsPressed( 'S' ) )
	{
		angle.y += 0.02f;
	}

	// rotate around Z
	if( wnd.kbd.KeyIsPressed( 'E' ) )
	{
		angle.z -= 0.02f;
	}
	else if( wnd.kbd.KeyIsPressed( 'D' ) )
	{
		angle.z += 0.02f;
	}	

	//-----------------------------------------
	// translation

	// translate along X axis
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		cameraPos.x -= 0.02f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		cameraPos.x += 0.02f;
	}

	// translate along Y axis
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		cameraPos.y += 0.02f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		cameraPos.y -= 0.02f;
	}

	// translate along Z axis
	if( wnd.kbd.KeyIsPressed( 'R' ) )
	{
		cameraPos.z += 0.02f;
	}
	else if( wnd.kbd.KeyIsPressed( 'F' ) )
	{
		cameraPos.z -= 0.02f;
	}	

	const float lookSpeed = 0.05f;
	// cameraLookAt position
	if (wnd.kbd.KeyIsPressed('Z'))
	{
		cameraLookAt.x -= lookSpeed;
	}
	else if (wnd.kbd.KeyIsPressed('X'))
	{
		cameraLookAt.x += lookSpeed;
	}

	if (wnd.kbd.KeyIsPressed('C'))
	{
		cameraLookAt.y += lookSpeed;
	}
	else if (wnd.kbd.KeyIsPressed('V'))
	{
		cameraLookAt.y -= lookSpeed;
	}

	if (wnd.kbd.KeyIsPressed('B'))
	{
		cameraLookAt.z += lookSpeed;
	}
	else if (wnd.kbd.KeyIsPressed('N'))
	{
		cameraLookAt.z -= lookSpeed;
	}
}

void Game::ComposeFrame()
{
	// -------------------------------------------------
	const Mat4 Transformation =
		Mat4::Transformation( scale, angle, position );

	/*const Mat4 Transformation =
		Mat4::Rotation( angle ) *
		Mat4::Scaling( scale ) *
		Mat4::Translation(position) *
		Mat4::Camera( cameraPos, cameraUp, cameraLookAt );*/
	/*Mat4::Translation(Vec4( position ) * Mat4::Rotation(angle)) *
		Mat4::Translation(position)*/
	// -------------------------------------------------

	if ( true /* cube */ )
	{
		const Color colors[12] = {
			Colors::Magenta,
			Colors::Purple,
			Colors::Pink,
			Colors::Red,
			Colors::Blue,
			Colors::LightBlue,
			Colors::LightGreen,
			Colors::Green,
			Colors::LightGray,
			Colors::Gray,
			Colors::Orange,
			Colors::Yellow };
		
		/*const Color colors[12] = {
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
			Colors::Cyan };*/

		const Mat4 Transformation =
			Mat4::Rotation(cubeVar.angle) *
			Mat4::Scaling(cubeVar.scale) *
			Mat4::Translation(cubeVar.position) *
			Mat4::Camera(cameraPos, cameraUp, cameraLookAt)/* *
			Mat4::Pespective(width, height, nearDist, farDist)*/;

		if (true)
		{
			auto triangles = cube.GetTriangles();

			for (auto& i : triangles.vertices)
			{
				i *= Transformation;
			}

			// set cullflags
			for (size_t i = 0, end = triangles.indices.size() / 3;
				i < end; i++)
			{
				const Vec3& v0 = triangles.vertices[triangles.indices[i * 3 + 0]];
				const Vec3& v1 = triangles.vertices[triangles.indices[i * 3 + 1]];
				const Vec3& v2 = triangles.vertices[triangles.indices[i * 3 + 2]];
				triangles.cullflags[i] = ((v1 - v0).Cross(v2 - v0)).Dot(v0) > 0;
			}
			
			for (auto& i : triangles.vertices)
			{
				cam.Transform(i);
			}

			for (size_t i = 0, end = triangles.indices.size() / 3; i < end; i++)
			{
				if (!triangles.cullflags[i])
				{
					gfx.DrawTriangle(
						triangles.vertices[triangles.indices[i * 3 + 0]],
						triangles.vertices[triangles.indices[i * 3 + 1]],
						triangles.vertices[triangles.indices[i * 3 + 2]],
						colors[i]);
				}
			}
		}

		// ---------------------------------------------------

		if (false)
		{
			auto lines = cube.GetLines();

			for (auto i = lines.vertices.begin(),
				end = lines.vertices.end();
				i != end; i++)
			{
				*i *= Transformation;
				cam.Transform(*i);
			}

			for (auto i = lines.indices.begin(),
				end = lines.indices.end();
				i != end; std::advance(i, 2))
			{
				gfx.DrawLine(
					lines.vertices[*i],
					lines.vertices[*std::next(i)],
					Colors::Black);
			}
		}
	}

	// -------------------------------------------------

	if ( false /* diamond */ )
	{
		const Color colors[8] =	{
				Colors::Pink,
				Colors::Red,
				Colors::LightGreen,
				Colors::Green,
				Colors::LightGray,
				Colors::Gray,
				Colors::Orange,
				Colors::Yellow };

		if (true)
		{	
			auto triangles = diamond.GetTriangles();
	
			for (auto& i : triangles.vertices)
			{
				i *= Transformation;
			}
	
			// set cullflags
			for (size_t i = 0, end = triangles.indices.size() / 3;
				i < end; i++)
			{
				const Vec3& v0 = triangles.vertices[triangles.indices[i * 3 + 0]];
				const Vec3& v1 = triangles.vertices[triangles.indices[i * 3 + 1]];
				const Vec3& v2 = triangles.vertices[triangles.indices[i * 3 + 2]];
				triangles.cullflags[i] = ((v1 - v0).Cross(v2 - v0)).Dot(v0) > 0;
			}
	
			for (auto& i : triangles.vertices)
			{
				cam.Transform(i);
			}
	
			for (size_t i = 0, end = triangles.indices.size() / 3; i < end; i++)
			{
				if (!triangles.cullflags[i])
				{
					gfx.DrawTriangle(
						triangles.vertices[triangles.indices[i * 3 + 0]],
						triangles.vertices[triangles.indices[i * 3 + 1]],
						triangles.vertices[triangles.indices[i * 3 + 2]],
						colors[i]);
				}
			}
		}
	
		if (false)
		{
			auto lines = diamond.GetLines();
	
			for (auto i = lines.vertices.begin(),
				end = lines.vertices.end();
				i != end; i++)
			{
				*i *= Transformation;
				cam.Transform(*i);
			}
	
			for (auto i = lines.indices.begin(),
				end = lines.indices.end();
				i != end; std::advance(i, 2))
			{
				gfx.DrawLine(
					lines.vertices[*i],
					lines.vertices[*std::next(i)],
					Colors::Black);
			}
		}
	}

	// -------------------------------------------------

	if ( false /* hex prism */ )
	{	
		const Color colors[24] = {
			Colors::Magenta,
			Colors::Purple,
			Colors::Pink,
			Colors::Red,
			Colors::Blue,
			Colors::LightBlue,
			Colors::LightGreen,
			Colors::Green,
			Colors::LightGray,
			Colors::Gray,
			Colors::Orange,
			Colors::Yellow,
			Colors::Magenta,
			Colors::Purple,
			Colors::Pink,
			Colors::Red,
			Colors::Blue,
			Colors::LightBlue,
			Colors::LightGreen,
			Colors::Green,
			Colors::LightGray,
			Colors::Gray,
			Colors::Orange,
			Colors::Yellow };

		if (true)
		{
			auto triangles = hex.GetTriangles();
	
			for (auto& i : triangles.vertices)
			{
				i *= Transformation;
			}
	
			// set cullflags
			for (size_t i = 0, end = triangles.indices.size() / 3;
				i < end; i++)
			{
				const Vec3& v0 = triangles.vertices[triangles.indices[i * 3 + 0]];
				const Vec3& v1 = triangles.vertices[triangles.indices[i * 3 + 1]];
				const Vec3& v2 = triangles.vertices[triangles.indices[i * 3 + 2]];
				triangles.cullflags[i] = ((v1 - v0).Cross(v2 - v0)).Dot(v0) > 0;
			}
	
			for (auto& i : triangles.vertices)
			{
				cam.Transform(i);
			}
	
			for (size_t i = 0, end = triangles.indices.size() / 3; i < end; i++)
			{
				if (!triangles.cullflags[i])
				{
					gfx.DrawTriangle(
						triangles.vertices[triangles.indices[i * 3 + 0]],
						triangles.vertices[triangles.indices[i * 3 + 1]],
						triangles.vertices[triangles.indices[i * 3 + 2]],
						colors[i]);
				}
			}
		}
	
		if (false)
		{
			auto lines = hex.GetLines();
	
			for (auto i = lines.vertices.begin(),
				end = lines.vertices.end();
				i != end; i++)
			{
				*i *= Transformation;
				cam.Transform(*i);
			}
	
			for (auto i = lines.indices.begin(),
				end = lines.indices.end();
				i != end; std::advance(i, 2))
			{
				gfx.DrawLine(
					lines.vertices[*i],
					lines.vertices[*std::next(i)],
					Colors::White);
			}
		}
	}

	// -------------------------------------------------

	if ( false  /* plane */ )
	{
		Color colors[4] = {
			Colors::Red,
			Colors::Pink,
			Colors::Green,
			Colors::LightGreen };

		if (true)
		{
			auto triangles = plane.GetTriangles();
	
			for (auto& i : triangles.vertices)
			{
				i *= Transformation;
			}
	
			// set cullflags
			for (size_t i = 0, end = triangles.indices.size() / 3;
				i < end; i++)
			{
				const Vec3& v0 = triangles.vertices[triangles.indices[i * 3 + 0]];
				const Vec3& v1 = triangles.vertices[triangles.indices[i * 3 + 1]];
				const Vec3& v2 = triangles.vertices[triangles.indices[i * 3 + 2]];
				triangles.cullflags[i] = ((v1 - v0).Cross(v2 - v0)).Dot(v0) > 0;
			}
	
			for (auto& i : triangles.vertices)
			{
				cam.Transform(i);
			}
	
			for (size_t i = 0, end = triangles.indices.size() / 3; i < end; i++)
			{
				if (!triangles.cullflags[i])
				{
					gfx.DrawTriangle(
						triangles.vertices[triangles.indices[i * 3 + 0]],
						triangles.vertices[triangles.indices[i * 3 + 1]],
						triangles.vertices[triangles.indices[i * 3 + 2]],
						colors[i]);
				}
			}
		}
	
		if (false)
		{
			auto lines = plane.GetLines();
	
			for (auto i = lines.vertices.begin(),
				end = lines.vertices.end();
				i != end; i++)
			{
				*i *= Transformation;
				cam.Transform(*i);
			}
	
			for (auto i = lines.indices.begin(),
				end = lines.indices.end();
				i != end; std::advance(i, 2))
			{
				gfx.DrawLine(
					lines.vertices[*i],
					lines.vertices[*std::next(i)],
					Colors::Black);
			}
		}
	}
	
	// -------------------------------------------------

	if (true   /* grid */ )
	{
		const Mat4 Transformation =
			Mat4::Scaling(gridVar.scale) *
			Mat4::Rotation(gridVar.angle) *
			Mat4::Translation(gridVar.position) *
			Mat4::Camera(cameraPos, cameraUp, cameraLookAt);

		auto lines = grid.GetLines();

		for (auto i = lines.vertices.begin(),
			end = lines.vertices.end();
			i != end; i++)
		{
			*i *= Transformation;
			cam.Transform(*i);
		}

		for (auto i = lines.indices.begin(),
			end = lines.indices.end();
			i != end; std::advance(i, 2))
		{
			gfx.DrawLine(
				lines.vertices[*i],
				lines.vertices[*std::next(i)],
				Colors::LightGray);
		}
	}

	// -------------------------------------------------
	// cross hair ( center of screen )
	const float midX = float(Graphics::ScreenWidth / 2);
	const float midY = float(Graphics::ScreenHeight / 2);
	gfx.DrawLine({ midX, midY - 10 }, { midX, midY + 10 }, Colors::Black);
	gfx.DrawLine({ midX - 10, midY }, { midX + 10, midY }, Colors::Black);
}