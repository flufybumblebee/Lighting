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

#include "Mat4.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	cameraPos(		0.0f, 0.0f, 0.0f ),
	cameraLookAt(	0.0f, 0.0f, 2.0f ),
	cameraUp(		0.0f, 1.0f, 0.0f ),
	grid( 1.0f ),
	frustum( fovX, fovY, nZ, fZ )/*,
	cam(cameraPos, cameraLookAt, cameraUp),
	per( fovX, fovY, nZ, fZ),
	port( x, y, width, height ),
	cube(	false,	true ),
	cube2(	false,	true ),
	plane(	false,	true ),
	grid(	true,	true )*/
{
	/*cubeVar.SetScale(   0.5f, 0.5f, 0.5f);
	cubeVar.SetRotation(0.0f, 0.0f, 0.0f);
	cubeVar.SetPosition(0.0f, 0.75f, 2.0f);
	
	cube2Var.SetScale(   0.5f, 0.5f,  0.5f);
	cube2Var.SetRotation(0.0f, 0.0f,  0.0f);
	cube2Var.SetPosition(0.0f, 0.25f, 2.0f);

	gridVar.SetScale(   10.0f, 10.0f, 10.0f);
	gridVar.SetRotation(0.0f, 0.0f, 0.0f);
	gridVar.SetPosition(0.0f, 0.0f, 2.0f);*/
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

	//-----------------------------------------
	// camera translation

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

	// ----------------------------------------

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

	//cubeVar.angle = angle;
	//cam.Update(cameraPos, cameraLookAt, cameraUp);
	/*cube.Update(cubeVar.scale, cubeVar.angle, cubeVar.position);
	cube2.Update(cube2Var.scale, cube2Var.angle, cube2Var.position);
	plane.Update(gridVar.scale, gridVar.angle, gridVar.position);
	grid.Update(gridVar.scale, gridVar.angle, gridVar.position);*/
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
}

void Game::ComposeFrame()
{
	//plane.Draw(cam, gfx);
	//grid.Draw(cam, per, view, gfx);
	//cube2.Draw(cam, per, view, gfx);
	//cube.Draw(cam, gfx);
	
	/*Mat4::Translation(Vec4( position ) * Mat4::Rotation(angle)) *
		Mat4::Translation(position)*/

	const Mat4 Transformation =
		Mat4::Scaling(scale) *
		Mat4::Rotation(angle) *
		Mat4::Translation(position) *
		Mat4::Camera( cameraPos, cameraLookAt, cameraUp ) *
		Mat4::Pespective( fovX, fovY, nZ, fZ ) * 
		Mat4::Orthographic( nW, nH, nZ, fZ ) *
		Mat4::Viewport( vX, vY, vW, vH );
	
	// ---------------------------------------------------

	if (true)
	{
		auto lines = grid.GetLines();

		for (auto i = lines.vertices.begin(),
			end = lines.vertices.end();
			i != end; i++)
		{
			*i *= Transformation;
			//view.Transform(*i);
			i->x *= 1 / i->z;
			i->y *= 1 / i->z;
		}

		for (auto i = lines.indices.begin(),
			end = lines.indices.end();
			i != end; std::advance(i, 2))
		{
			gfx.DrawLine(
				lines.vertices[*i],
				lines.vertices[*std::next(i)],
				Colors::Gray);
		}
	}

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