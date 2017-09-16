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
	gfx(wnd)
{
	//polyhedron24   = Tessellate(cube);
	//polyhedron96   = Tessellate(polyhedron24);
	//polyhedron384  = Tessellate(polyhedron96);
	//polyhedron1536 = Tessellate(polyhedron384);
	
	//polyhedron32   = Tessellate(octa);
	//polyhedron128  = Tessellate(polyhedron32);
	//polyhedron512  = Tessellate(polyhedron128);
	//polyhedron2048 = Tessellate(polyhedron512);

	polyhedron80   = Tessellate(icosa);
	//polyhedron320  = Tessellate(polyhedron80);
	//polyhedron1280 = Tessellate(polyhedron320);
	//polyhedron5120 = Tessellate(polyhedron1280);
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
	Scale(0.01f);
	Angle(0.01f);
	Position(0.01f);	
	Light(0.1f);
	Camera();	
}

void Game::ComposeFrame()
{
	const Mat4 trans =
		Mat4::Scaling(scale) *
		Mat4::Rotation(angle) *
		Mat4::Translation(position) *
		Mat4::Camera(cameraPosition, cameraLookAt, cameraUp);

	// ---------------------------------------------------

	Vec3 LP = (lightPosition * Mat4::Camera(cameraPosition, cameraLookAt, cameraUp)).Normalize();

	// ---------------------------------------------------

	//Draw(trans, icosa, modelColor, ambientColor, lightColor, LP);
	DrawModel(false, true, trans, icosa, modelColor, ambientColor, lightColor, LP);
	DrawModel(true, false, trans, axis, modelColor, ambientColor, lightColor, LP);

	// -------------------------------------------------

	DrawCrossHair(Colors::Yellow);
	DrawViewport(Colors::Yellow);
};

void Game::Scale(const float& speed)
{
	// scale x
	if (wnd.kbd.KeyIsPressed('T'))
	{
		scale.x = scale.x + speed;
	}
	else if (wnd.kbd.KeyIsPressed('G'))
	{
		scale.x = scale.x - speed;
		if (scale.x < 0.0f) { scale.x = 0.0f; }
	}

	// scale y
	if (wnd.kbd.KeyIsPressed('Y'))
	{
		scale.y = scale.y + speed;
	}
	else if (wnd.kbd.KeyIsPressed('H'))
	{
		scale.y = scale.y - speed;
		if (scale.y < 0.0f) { scale.y = 0.0f; }
	}

	// scale z
	if (wnd.kbd.KeyIsPressed('U'))
	{
		scale.z = scale.z + speed;
	}
	else if (wnd.kbd.KeyIsPressed('J'))
	{
		scale.z = scale.z - speed;
		if (scale.z < 0.0f) { scale.z = 0.0f; }
	}
}

void Game::Angle(const float& speed)
{
	// rotate around X
	if (wnd.kbd.KeyIsPressed('Q'))
	{
		angle.x -= speed;
	}
	else if (wnd.kbd.KeyIsPressed('A'))
	{
		angle.x += speed;
	}

	// rotate around Y
	if (wnd.kbd.KeyIsPressed('W'))
	{
		angle.y -= speed;
	}
	else if (wnd.kbd.KeyIsPressed('S'))
	{
		angle.y += speed;
	}

	// rotate around Z
	if (wnd.kbd.KeyIsPressed('E'))
	{
		angle.z -= speed;
	}
	else if (wnd.kbd.KeyIsPressed('D'))
	{
		angle.z += speed;
	}
}

void Game::Position(const float& speed)
{

}

void Game::Light(const float& speed)
{
	if (wnd.kbd.KeyIsPressed('1'))
	{
		lightPosition.x -= speed;
	}
	else if (wnd.kbd.KeyIsPressed('2'))
	{
		lightPosition.x += speed;
	}
	if (wnd.kbd.KeyIsPressed('3'))
	{
		lightPosition.y -= speed;
	}
	else if (wnd.kbd.KeyIsPressed('4'))
	{
		lightPosition.y += speed;
	}
	if (wnd.kbd.KeyIsPressed('5'))
	{
		lightPosition.z -= speed;
	}
	else if (wnd.kbd.KeyIsPressed('6'))
	{
		lightPosition.z += speed;
	}
}

void Game::Camera()
{
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
	if (wnd.kbd.KeyIsPressed('R'))
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
	else if (wnd.kbd.KeyIsPressed('F'))
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

	// cameraLookAt position
	const float lookSpeed = 0.05f;
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

	//-------------------------------------------------

	// camera mouse control

	if (wnd.mouse.IsInWindow() && wnd.mouse.LeftIsPressed())
	{
		if (wnd.mouse.GetPosX() < 320)
		{
			if (isCam0) { cameraPos0.x -= 0.01f; }
			else { cameraPos1.x -= 0.01f; }
		}
		else if (wnd.mouse.GetPosX() > 320)
		{
			if (isCam0) { cameraPos0.x += 0.01f; }
			else { cameraPos1.x += 0.01f; }
		}

		if (wnd.mouse.GetPosY() < 320)
		{
			if (isCam0) { cameraPos0.y += 0.01f; }
			else { cameraPos1.y += 0.01f; }
		}
		else if (wnd.mouse.GetPosY() > 320)
		{

			if (isCam0) { cameraPos0.y -= 0.01f; }
			else { cameraPos1.y -= 0.01f; }
		}
	}

	//-------------------------------------------------

	// Set current camera
	if (isCam0)
	{
		cameraPosition = cameraPos0;
		cameraLookAt = cameraLookAt0;
		cameraUp = cameraUp0;
	}
	else
	{
		cameraPosition = cameraPos1;
		cameraLookAt = cameraLookAt1;
		cameraUp = cameraUp1;
	}
}

void Game::DrawModel( 
	bool lines,
	bool triangles,
	const Mat4& trans,
	const Model& model,
	const Vec3& modelColor,
	const Vec3& ambientColor,
	const Vec3& lightColor,
	const Vec3& lightPosition)
{
	if (triangles)
	{
		auto triangles = model.GetTriangles();

		for (auto& i : triangles.vertices)
		{
			i *= trans;
		}
		
		std::vector< Color > faceColor;

		// set cullflags
		for (size_t i = 0, end = triangles.indices.size() / 3; i < end; i++)
		{
			const Vec3& v0 = triangles.vertices[triangles.indices[i * 3 + 0]];
			const Vec3& v1 = triangles.vertices[triangles.indices[i * 3 + 1]];
			const Vec3& v2 = triangles.vertices[triangles.indices[i * 3 + 2]];
			const Vec3 surfaceNormal = ((v1 - v0).Cross(v2 - v0));
			triangles.cullflags[i] = surfaceNormal.Dot(v0) > 0;

			// ----------------------------------------------------------
			
			// set light intensity
			const Vec3 diffuseColor = lightColor * std::max(0.0f,((-surfaceNormal).Dot(lightPosition)));;
			
			// set surface color
			Vec3 finalColor = modelColor.Hadamard(ambientColor + diffuseColor).Saturation() * 255.0f;

			faceColor.emplace_back(Color(unsigned char(finalColor.x),unsigned char(finalColor.y),unsigned char(finalColor.z)));			
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
					faceColor[i]);				
			}
		}
	}

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
				Colors::White);
		}
	}
}

Model Game::Tessellate(const Model& model)
{
	std::vector<Vec4> vertices;
	std::vector<size_t> indicesLine;
	std::vector<size_t> indicesTri;

	for (size_t i = 0; i < model.GetTriangles().vertices.size(); i++)
	{
		vertices.emplace_back(model.GetTriangles().vertices[i]);
	}
		
	const float radius = model.GetTriangles().vertices[0].Len();

	for (size_t i = 0; i < model.GetTriangles().indices.size() / 3; i++)
	{
		Vec4 v0 = vertices[model.GetTriangles().indices[i * 3 + 0]];
		Vec4 v1 = vertices[model.GetTriangles().indices[i * 3 + 1]];
		Vec4 v2 = vertices[model.GetTriangles().indices[i * 3 + 2]];

		Vec4 e0 = (v0 + ((v1 - v0) * 0.5f)).Normalize() * radius;
		Vec4 e1 = (v1 + ((v2 - v1) * 0.5f)).Normalize() * radius;
		Vec4 e2 = (v0 + ((v2 - v0) * 0.5f)).Normalize() * radius;

		vertices.emplace_back(e0);
		vertices.emplace_back(e1);
		vertices.emplace_back(e2);

		//---------------------------------------------------------------

		indicesTri.emplace_back(model.GetTriangles().indices[i * 3 + 0]);
		indicesTri.emplace_back(vertices.size() - 3);
		indicesTri.emplace_back(vertices.size() - 1);

		indicesTri.emplace_back(vertices.size() - 1);
		indicesTri.emplace_back(vertices.size() - 2);
		indicesTri.emplace_back(model.GetTriangles().indices[i * 3 + 2]);

		indicesTri.emplace_back(vertices.size() - 1);
		indicesTri.emplace_back(vertices.size() - 3);
		indicesTri.emplace_back(vertices.size() - 2);

		indicesTri.emplace_back(vertices.size() - 3);
		indicesTri.emplace_back(model.GetTriangles().indices[i * 3 + 1]);
		indicesTri.emplace_back(vertices.size() - 2);
		
		// -----------------------------------------

		indicesLine.emplace_back(model.GetTriangles().indices[i * 3 + 0]);
		indicesLine.emplace_back(vertices.size() - 3);

		indicesLine.emplace_back(vertices.size() - 3);
		indicesLine.emplace_back(model.GetTriangles().indices[i * 3 + 1]);


		indicesLine.emplace_back(model.GetTriangles().indices[i * 3 + 1]);
		indicesLine.emplace_back(vertices.size() - 2);

		indicesLine.emplace_back(vertices.size() - 2);
		indicesLine.emplace_back(vertices.size() - 3);

		indicesLine.emplace_back(vertices.size() - 3);
		indicesLine.emplace_back(vertices.size() - 1);

		indicesLine.emplace_back(vertices.size() - 1);
		indicesLine.emplace_back(vertices.size() - 2);

		indicesLine.emplace_back(vertices.size() - 2);
		indicesLine.emplace_back(model.GetTriangles().indices[i * 3 + 2]);
		
		indicesLine.emplace_back(model.GetTriangles().indices[i * 3 + 2]);
		indicesLine.emplace_back(vertices.size() - 1);

		indicesLine.emplace_back(vertices.size() - 1);
		indicesLine.emplace_back(model.GetTriangles().indices[i * 3 + 0]);
	}

	Model newmodel = Model(vertices, indicesLine, indicesTri);

	return newmodel;
}

void Game::Draw(
	const Mat4& trans,
	const Model& model,
	const Vec3& modelColor,
	const Vec3& ambientColor,
	const Vec3& lightColor,
	const Vec3& lightPosition)
{	
	auto triangles = model.GetTriangles();

	for (auto& i : triangles.vertices)
	{
		i *= trans;
	}

	std::vector< Color > color0;
	std::vector< Color > color1;
	std::vector< Color > color2;

	// set cullflags
	for (size_t i = 0, end = triangles.indices.size() / 3; i < end; i++)
	{
		const Vec3& v0 = triangles.vertices[triangles.indices[i * 3 + 0]];
		const Vec3& v1 = triangles.vertices[triangles.indices[i * 3 + 1]];
		const Vec3& v2 = triangles.vertices[triangles.indices[i * 3 + 2]];
		const Vec3 surfaceNormal = ((v1 - v0).Cross(v2 - v0));
		triangles.cullflags[i] = surfaceNormal.Dot(v0) > 0;

		// ----------------------------------------------------------

		// set light intensity
		const Vec3 diffuseColor0 = lightColor * std::max(0.0f, ((v0.GetNormalized()).Dot(lightPosition)));
		const Vec3 diffuseColor1 = lightColor * std::max(0.0f, ((v1.GetNormalized()).Dot(lightPosition)));
		const Vec3 diffuseColor2 = lightColor * std::max(0.0f, ((v2.GetNormalized()).Dot(lightPosition)));

		// set surface color
		Vec3 finalColor0 = modelColor.Hadamard(ambientColor + diffuseColor0).Saturation() * 255.0f;
		Vec3 finalColor1 = modelColor.Hadamard(ambientColor + diffuseColor1).Saturation() * 255.0f;
		Vec3 finalColor2 = modelColor.Hadamard(ambientColor + diffuseColor2).Saturation() * 255.0f;

		color0.emplace_back(Color(unsigned char(finalColor0.x), unsigned char(finalColor0.y), unsigned char(finalColor0.z)));
		color1.emplace_back(Color(unsigned char(finalColor1.x), unsigned char(finalColor1.y), unsigned char(finalColor1.z)));
		color2.emplace_back(Color(unsigned char(finalColor2.x), unsigned char(finalColor2.y), unsigned char(finalColor2.z)));
	}

	for (auto& i : triangles.vertices)
	{
		view.Transform(i);
	}

	for (size_t i = 0, end = triangles.indices.size() / 3; i < end; i++)
	{
		if (!triangles.cullflags[i])
		{
			DrawTriangleThreeColor(
				Vec2Color(triangles.vertices[triangles.indices[i * 3 + 0]], color0[i]),
				Vec2Color(triangles.vertices[triangles.indices[i * 3 + 1]], color1[i]),
				Vec2Color(triangles.vertices[triangles.indices[i * 3 + 2]], color2[i]));
		}
	}	
}

void Game::DrawTriangleThreeColor(const Vec2Color& v0, const Vec2Color& v1, const Vec2Color& v2)
{
	const Vec2Color* pv0 = &v0;
	const Vec2Color* pv1 = &v1;
	const Vec2Color* pv2 = &v2;

	// sorting vertices by y
	if (pv1->v.y < pv0->v.y) { std::swap(pv1, pv0); }
	if (pv2->v.y < pv1->v.y) { std::swap(pv2, pv1); }
	if (pv1->v.y < pv0->v.y) { std::swap(pv1, pv0); }

	if (pv0->v == pv1->v) // flat top triangle
	{
		// sort x's left to right
		//if (pv1->v.x < pv0->v.x) { std::swap(pv1, pv0); }
		//
		//DrawFlatTopTriangleThreeColor(*pv0, *pv1, *pv2);
	}
	else if (pv1->v == pv2->v) // flat bottom triangle
	{
		// sort x's left to right
		//if (pv2->v.x < pv1->v.x) { std::swap(pv2, pv1); }
		//
		//DrawFlatBottomTriangleThreeColor(*pv0, *pv1, *pv2 );
	}
	else // general triangle
	{
		// find the splitting vertex
		const float alpha = (pv1->v.y - pv0->v.y) / (pv2->v.y - pv0->v.y);
		const Vec2 vi = pv0->v + ((pv2->v - pv0->v) * alpha);

		const float majorLen = (pv2->v - pv0->v).Len();

		const float   redChange = -(float(pv0->c.GetR() - pv2->c.GetR()));
		const float greenChange = -(float(pv0->c.GetG() - pv2->c.GetG()));
		const float  blueChange = -(float(pv0->c.GetB() - pv2->c.GetB()));

		const float   redIncrement = redChange / majorLen;
		const float greenIncrement = greenChange / majorLen;
		const float  blueIncrement = blueChange / majorLen;

		const float splitLen = (vi - pv0->v).Len();

		const Color c = Color(
			unsigned char(pv0->c.GetR() + redIncrement * splitLen),
			unsigned char(pv0->c.GetG() + greenIncrement * splitLen),
			unsigned char(pv0->c.GetB() + blueIncrement * splitLen));

		Vec2Color Vi;
		Vi.v = vi;
		Vi.c = c;

		if (pv1->v.x < vi.x) // major right
		{
			DrawFlatBottomTriangleThreeColor(*pv0, *pv1, Vi);
			DrawFlatTopTriangleThreeColor(*pv1, Vi, *pv2);
		}
		else // major left
		{
			DrawFlatBottomTriangleThreeColor(*pv0, Vi, *pv1);
			DrawFlatTopTriangleThreeColor(Vi, *pv1, *pv2);
		}
	}
}

void Game::DrawFlatBottomTriangleThreeColor(const Vec2Color& A, const Vec2Color& B, const Vec2Color& C)
{
	// color stuff --------------------------------------

	// AB - top to bottom left
	const float   redChangeAB = -(float(A.c.GetR() - B.c.GetR()));
	const float greenChangeAB = -(float(A.c.GetG() - B.c.GetG()));
	const float  blueChangeAB = -(float(A.c.GetB() - B.c.GetB()));

	const float sizeAB = (B.v - A.v).Len();

	const float   redIncrementAB = redChangeAB / sizeAB;
	const float greenIncrementAB = greenChangeAB / sizeAB;
	const float  blueIncrementAB = blueChangeAB / sizeAB;

	// AC - top to bottom right
	const float   redChangeAC = -(float(A.c.GetR() - C.c.GetR()));
	const float greenChangeAC = -(float(A.c.GetG() - C.c.GetG()));
	const float  blueChangeAC = -(float(A.c.GetB() - C.c.GetB()));

	const float sizeAC = (C.v - A.v).Len();

	const float   redIncrementAC = redChangeAC / sizeAC;
	const float greenIncrementAC = greenChangeAC / sizeAC;
	const float  blueIncrementAC = blueChangeAC / sizeAC;

	//-----------------------------------------------------

	const float slopeAB = (B.v.x - A.v.x) / (B.v.y - A.v.y);
	const float slopeAC = (C.v.x - A.v.x) / (C.v.y - A.v.y);

	// set the top rule
	const int yStart = int(ceil(A.v.y - 0.5f));
	const int yEnd = int(ceil(C.v.y - 0.5f));

	for (int y = yStart; y < yEnd; y++)
	{
		// set the start and end x pixels ( before setting the left rule )
		const float px0 = slopeAB * (float(y) + 0.5f - A.v.y) + A.v.x;
		const float px1 = slopeAC * (float(y) + 0.5f - A.v.y) + A.v.x;

		// set left rule
		const int xStart = int(ceil(px0 - 0.5f));
		const int xEnd = int(ceil(px1 - 0.5f));

		// color stuff ------------------------------------------------

		const float lengthAB = sqrt(sq(A.v.x - xStart) + sq(y - A.v.y));

		const float   redStart = A.c.GetR() + (lengthAB *   redIncrementAB);
		const float greenStart = A.c.GetG() + (lengthAB * greenIncrementAB);
		const float  blueStart = A.c.GetB() + (lengthAB *  blueIncrementAB);

		//-------------------------------------------------------------

		const float lengthAC = sqrt(sq(A.v.x - xEnd) + sq(y - A.v.y));

		const float   redEnd = A.c.GetR() + (lengthAC *   redIncrementAC);
		const float greenEnd = A.c.GetG() + (lengthAC * greenIncrementAC);
		const float  blueEnd = A.c.GetB() + (lengthAC *  blueIncrementAC);

		//--------------------------------------------------------------

		const float   redChange = -(redStart - redEnd);
		const float greenChange = -(greenStart - greenEnd);
		const float  blueChange = -(blueStart - blueEnd);

		//--------------------------------------------------------------

		const float lengthBC = float(xEnd - xStart);

		const float   redIncrement = redChange / lengthBC;
		const float greenIncrement = greenChange / lengthBC;
		const float  blueIncrement = blueChange / lengthBC;

		// -----------------------------------------------

		for (int x = xStart; x < xEnd; x++)
		{
			const int lengthX = x - xStart;

			const unsigned char red = unsigned char(redStart + (lengthX * redIncrement));
			const unsigned char green = unsigned char(greenStart + (lengthX * greenIncrement));
			const unsigned char blue = unsigned char(blueStart + (lengthX * blueIncrement));

			const Color c = Color(red, green, blue);

			gfx.PutPixel(x, y, c);
		}
	}
}

void Game::DrawFlatTopTriangleThreeColor(const Vec2Color& A, const Vec2Color& B, const Vec2Color& C)
{
	// color stuff --------------------------------------

	// AC - top left to bottom
	const float   redChangeAC = -(float(A.c.GetR() - C.c.GetR()));
	const float greenChangeAC = -(float(A.c.GetG() - C.c.GetG()));
	const float  blueChangeAC = -(float(A.c.GetB() - C.c.GetB()));

	const float sizeAC = (C.v - A.v).Len();

	const float   redIncrementAC = redChangeAC / sizeAC;
	const float greenIncrementAC = greenChangeAC / sizeAC;
	const float  blueIncrementAC = blueChangeAC / sizeAC;

	// BC - top right to bottom
	const float   redChangeBC = -(float(B.c.GetR() - C.c.GetR()));
	const float greenChangeBC = -(float(B.c.GetG() - C.c.GetG()));
	const float  blueChangeBC = -(float(B.c.GetB() - C.c.GetB()));

	const float sizeBC = (C.v - B.v).Len();

	const float   redIncrementBC = redChangeBC / sizeBC;
	const float greenIncrementBC = greenChangeBC / sizeBC;
	const float  blueIncrementBC = blueChangeBC / sizeBC;

	//-----------------------------------------------------

	const float slopeAC = (C.v.x - A.v.x) / (C.v.y - A.v.y);
	const float slopeBC = (C.v.x - B.v.x) / (C.v.y - B.v.y);

	// set the top rule
	const int yStart = int(ceil(A.v.y - 0.5f));
	const int yEnd = int(ceil(C.v.y - 0.5f));

	for (int y = yStart; y < yEnd; y++)
	{
		// set the start and end x pixels ( before setting the left rule )
		const float px0 = slopeAC * (float(y) + 0.5f - A.v.y) + A.v.x;
		const float px1 = slopeBC * (float(y) + 0.5f - B.v.y) + B.v.x;

		// set left rule
		const int xStart = int(ceil(px0 - 0.5f));
		const int xEnd = int(ceil(px1 - 0.5f));

		// color stuff ------------------------------------------------

		const float lengthAC = sqrt(sq(A.v.x - xStart) + sq(y - A.v.y));

		const float   redStart = A.c.GetR() + (lengthAC *   redIncrementAC);
		const float greenStart = A.c.GetG() + (lengthAC * greenIncrementAC);
		const float  blueStart = A.c.GetB() + (lengthAC *  blueIncrementAC);

		//--------------------------------------------------------------

		const float lengthBC = sqrt(sq(B.v.x - xEnd) + sq(y - B.v.y));

		const float   redEnd = B.c.GetR() + (lengthBC *   redIncrementBC);
		const float greenEnd = B.c.GetG() + (lengthBC * greenIncrementBC);
		const float  blueEnd = B.c.GetB() + (lengthBC *  blueIncrementBC);

		//--------------------------------------------------------------

		const float   redChange = -(redStart - redEnd);
		const float greenChange = -(greenStart - greenEnd);
		const float  blueChange = -(blueStart - blueEnd);

		//--------------------------------------------------------------

		const float lengthAB = float(xEnd - xStart);

		const float   redIncrement = redChange / lengthAB;
		const float greenIncrement = greenChange / lengthAB;
		const float  blueIncrement = blueChange / lengthAB;

		// -----------------------------------------------

		for (int x = xStart; x < xEnd; x++)
		{
			const int lengthX = x - xStart;
			const unsigned char   red = unsigned char(redStart + (lengthX *   redIncrement));
			const unsigned char green = unsigned char(greenStart + (lengthX * greenIncrement));
			const unsigned char  blue = unsigned char(blueStart + (lengthX *  blueIncrement));

			const Color c = Color(red, green, blue);

			gfx.PutPixel(x, y, c);
		}
	}
}

void Game::DrawCrossHair( const Color& c )
{
	const float midX = vX + (vW * 0.5f);
	const float midY = vY + (vH * 0.5f);
	const float size = 10;
	gfx.DrawLine({ midX, midY - size }, { midX, midY + size }, c);
	gfx.DrawLine({ midX - size, midY }, { midX + size, midY }, c);
}

void Game::DrawViewport(const Color& c)
{
	// horizontal lines
	gfx.DrawLine({ vX, vY }, { vX + vW, vY }, c);
	gfx.DrawLine({ vX, vY + vH }, { vX + vW, vY + vH }, c);
	// verticle lines
	gfx.DrawLine({ vX, vY }, { vX, vY + vH }, c);
	gfx.DrawLine({ vX + vW, vY }, { vX + vW, vY + vH }, c);
}