#pragma once

#include "Object.h"
#include "Cube.h"
#include "Vec4.h"
#include "Mat4.h"
#include "ViewTransform.h"

class CubeModel : public Object
{
public:
	CubeModel( bool drawLines, bool drawTriangles )
		:
		drawLines( drawLines ),
		drawTriangles( drawTriangles )
	{}
	void Update(const Vec3& scale, const Vec3& angle, const Vec3& position ) override
	{
		this->scale = scale;
		this->angle = angle;
		this->position = position;
	}
	void Draw( Camera& cam, Perspective& per, Viewport& port, Graphics& gfx ) const override
	{
		const Mat4 Transformation =
				Mat4::Scaling(scale) *
				Mat4::Rotation(angle) *
				Mat4::Translation(position) *
				cam.Transform();

		// ---------------------------------------------------

		if (drawTriangles)
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

		// ---------------------------------------------------

		if (drawLines)
		{
			auto lines = cube.GetLines();

			for (auto i = lines.vertices.begin(),
				end = lines.vertices.end();
				i != end; i++)
			{
				*i *= Transformation;
				//view.Transform(*i);
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
private:
	Cube cube = Cube(1.0f);
	ViewTransform view;
	Vec3 scale;
	Vec3 angle;
	Vec3 position;
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

	bool drawLines = true;
	bool drawTriangles = true;
};
