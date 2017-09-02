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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	cameraPos(		0.0f,  0.0f,  0.0f),
	cameraLookAt(	0.0f,  0.0f,  0.0f),
	cameraUp(		0.0f,  0.0f,  0.0f),
	cameraPos0(		0.0f,  0.0f, -10.0f),
	cameraLookAt0(	0.0f,  0.0f,  0.0f),
	cameraUp0(		0.0f,  1.0f,  0.0f),
	cameraPos1(		3.0f,  3.0f, -10.0f),
	cameraLookAt1(	0.0f,  0.0f,  0.0f),
	cameraUp1(		0.0f,  1.0f,  0.0f),
	grid( 1.0f ),
	frustum( fovX, fovY, nZ, fZ ),
	cube( 1.0f )
{}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	

	////-----------------------------------------
	//// scaling 
	//
	//// scale x
	//if (wnd.kbd.KeyIsPressed('T'))
	//{
	//	cubeVar.scale.x = cubeVar.scale.x + 0.01f;
	//}
	//else if (wnd.kbd.KeyIsPressed('G'))
	//{	
	//	cubeVar.scale.x = cubeVar.scale.x - 0.01f;
	//	if (cubeVar.scale.x < 0.0f) { cubeVar.scale.x = 0.0f; }
	//}
	//
	//// scale y
	//if (wnd.kbd.KeyIsPressed('Y'))
	//{
	//	cubeVar.scale.y = cubeVar.scale.y + 0.01f;
	//}
	//else if (wnd.kbd.KeyIsPressed('H'))
	//{
	//	cubeVar.scale.y = cubeVar.scale.y - 0.01f;
	//	if (cubeVar.scale.y < 0.0f) { cubeVar.scale.y = 0.0f; }
	//}
	//
	//// scale z
	//if (wnd.kbd.KeyIsPressed('U'))
	//{
	//	cubeVar.scale.z = cubeVar.scale.z + 0.01f;
	//}
	//else if (wnd.kbd.KeyIsPressed('J'))
	//{
	//	cubeVar.scale.z = cubeVar.scale.z - 0.01f;
	//	if (cubeVar.scale.z < 0.0f) { cubeVar.scale.z = 0.0f; }
	//}
	//// ---------------------------------------
	//// rotation
	//
	//// rotate around X
	//if( wnd.kbd.KeyIsPressed( 'Q' ) )
	//{
	//	angle.x -= 0.02f;
	//}
	//else if( wnd.kbd.KeyIsPressed( 'A' ) )
	//{
	//	angle.x += 0.02f;
	//}
	//
	//// rotate around Y
	//if( wnd.kbd.KeyIsPressed( 'W' ) )
	//{
	//	angle.y -= 0.02f;
	//}
	//else if( wnd.kbd.KeyIsPressed( 'S' ) )
	//{
	//	angle.y += 0.02f;
	//}
	//
	//// rotate around Z
	//if( wnd.kbd.KeyIsPressed( 'E' ) )
	//{
	//	angle.z -= 0.02f;
	//}
	//else if( wnd.kbd.KeyIsPressed( 'D' ) )
	//{
	//	angle.z += 0.02f;
	//}	

	//------------------------------------------------
	// CAMERA CONTROLS	

	// change between cameras
	if (!keyIsPressed)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN) && isCam0)
		{
			keyIsPressed = true;
			isCam0 = false;
		}
		else if (wnd.kbd.KeyIsPressed(VK_RETURN) && !isCam0)
		{
			keyIsPressed = true;
			isCam0 = true;
		}
	}
	else
	{
		if (!wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			keyIsPressed = false;
		}
	}

	//-----------------------------------------
	// camera translation
	
	const float transSpeed = 0.02f;
	// translate along X axis
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (isCam0)
		{
			cameraPos0.x -= transSpeed;
		}
		else
		{
			cameraPos1.x -= transSpeed;
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (isCam0)
		{
			cameraPos0.x += transSpeed;
		}
		else
		{
			cameraPos1.x += transSpeed;
		}
	}

	// translate along Y axis
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (isCam0)
		{
			cameraPos0.y += transSpeed;
		}
		else
		{
			cameraPos1.y += transSpeed;
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (isCam0)
		{
			cameraPos0.y -= transSpeed;
		}
		else
		{
			cameraPos1.y -= transSpeed;
		}
	}

	// translate along Z axis
	if( wnd.kbd.KeyIsPressed( 'R' ) )
	{
		if (isCam0)
		{
			cameraPos0.z += transSpeed;
		}
		else
		{
			cameraPos1.z += transSpeed;
		}
	}
	else if( wnd.kbd.KeyIsPressed( 'F' ) )
	{
		if (isCam0)
		{
			cameraPos0.z -= transSpeed;
		}
		else
		{
			cameraPos1.z -= transSpeed;
		}
	}	

	// ----------------------------------------

	const float lookSpeed = 0.05f;

	// cameraLookAt position

	// X
	if (wnd.kbd.KeyIsPressed('Z'))
	{
		if (isCam0)
		{
			cameraLookAt0.x -= lookSpeed;
		}
		else
		{
			cameraLookAt1.x -= lookSpeed;
		}
	}
	else if (wnd.kbd.KeyIsPressed('X'))
	{
		if (isCam0)
		{
			cameraLookAt0.x += lookSpeed;
		}
		else
		{
			cameraLookAt1.x += lookSpeed;
		}
	}

	// Y
	if (wnd.kbd.KeyIsPressed('C'))
	{
		if (isCam0)
		{
			cameraLookAt0.y += lookSpeed;
		}
		else
		{
			cameraLookAt1.y += lookSpeed;
		}
	}
	else if (wnd.kbd.KeyIsPressed('V'))
	{
		if (isCam0)
		{
			cameraLookAt0.y -= lookSpeed;
		}
		else
		{
			cameraLookAt1.y -= lookSpeed;
		}
	}

	// Z
	if (wnd.kbd.KeyIsPressed('B'))
	{
		if (isCam0)
		{
			cameraLookAt0.z += lookSpeed;
		}
		else
		{
			cameraLookAt1.z += lookSpeed;
		}
	}
	else if (wnd.kbd.KeyIsPressed('N'))
	{
		if (isCam0)
		{
			cameraLookAt0.z -= lookSpeed;
		}
		else
		{
			cameraLookAt1.z -= lookSpeed;
		}
	}

	if (wnd.mouse.IsInWindow() && wnd.mouse.LeftIsPressed())
	{
		if (wnd.mouse.GetPosX() < 320)
		{
			cameraPos.x -= 0.01f;
		}
		else if (wnd.mouse.GetPosX() > 320)
		{
			cameraPos.x += 0.01f;
		}

		if (wnd.mouse.GetPosY() < 320)
		{
			cameraPos.y += 0.01f;
		}
		else if (wnd.mouse.GetPosY() > 320)
		{
			cameraPos.y -= 0.01f;
		}
	}

	//-------------------------------------------------

	// Set the default camera variables to whatever camera is enabled
	if (isCam0)
	{
		cameraPos = cameraPos0;
		cameraLookAt = cameraLookAt0;
		cameraUp = cameraUp0;
	}
	else
	{
		cameraPos = cameraPos1;
		cameraLookAt = cameraLookAt1;
		cameraUp = cameraUp1;
	}
}

void Game::ComposeFrame()
{
	const Mat4 gridTrans =
		Mat4::Scaling(10.0f) *
		Mat4::Rotation(angle) *
		Mat4::Translation(position) *
		Mat4::Camera(cameraPos, cameraLookAt, cameraUp);

	const Mat4 frustumTrans =
		Mat4::Scaling(1.0f) *
		Mat4::Rotation(angle) *
		Mat4::Translation(position) *
		Mat4::Camera(cameraPos, cameraLookAt, cameraUp);
	
	const Mat4 cube0Trans =
		Mat4::Scaling(scale) *
		Mat4::Rotation(0.0f, 0.0f, 0.0f) *
		Mat4::Translation(-0.5f, 0.0f, 3.0f) *
		Mat4::Camera(cameraPos, cameraLookAt, cameraUp);

	const Mat4 cube1Trans =
		Mat4::Scaling(scale) *
		Mat4::Rotation(angle) *
		Mat4::Translation(0.5f, 0.0f, 3.0f) *
		Mat4::Camera(cameraPos, cameraLookAt, cameraUp);

	// ---------------------------------------------------

	DrawModel(true, false, gridTrans, grid, Colors::White);
	DrawModel(true, false, frustumTrans, frustum, Colors::White);
	DrawModel(false, true, cube0Trans, cube, Colors::White);
	DrawModel(false, true, cube1Trans, cube, Colors::White);
	
	// -------------------------------------------------

	const Color c = Colors::Yellow;

	if (true /* cross hair */)
	{
		const float midX = vX + (vW * 0.5f);
		const float midY = vY + (vH * 0.5f);
		gfx.DrawLine({ midX, midY - 10 }, { midX, midY + 10 }, c);
		gfx.DrawLine({ midX - 10, midY }, { midX + 10, midY }, c);
	}

	if (true /* viewport window */)
	{		
		// horizontal lines
		gfx.DrawLine({ vX, vY }, { vX + vW, vY }, c);
		gfx.DrawLine({ vX, vY + vH }, { vX + vW, vY + vH }, c);
		// verticle lines
		gfx.DrawLine({ vX, vY }, { vX, vY + vH }, c);
		gfx.DrawLine({ vX + vW, vY }, { vX + vW, vY + vH }, c);
	}
};

void Game::DrawModel( bool lines, bool triangles, const Mat4& trans, const Model& model, const Color& lineColor )
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

	if (lines)
	{
		auto lines = model.GetLines();

		for (auto i = lines.vertices.begin(),
			end = lines.vertices.end();
			i != end; i++)
		{
			*i *= trans;
			view.Transform(*i);
		}

		for (auto i = lines.indices.begin(),
			end = lines.indices.end();
			i != end; std::advance(i, 2))
		{
			gfx.DrawLine(
				lines.vertices[*i],
				lines.vertices[*std::next(i)],
				lineColor);
		}
	}

	if (triangles)
	{
		auto triangles = model.GetTriangles();

		for (auto& i : triangles.vertices)
		{
			i *= trans;
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
			view.Transform(i);
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
}