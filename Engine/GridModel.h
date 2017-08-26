#pragma once

#include "Model.h"
#include "Grid.h"
#include "Vec4.h"
#include "Mat4.h"
#include "ViewTransform.h"

class GridModel : public Model
{
public:
	GridModel(bool drawLines, bool drawTriangles)
		:
		drawLines(drawLines),
		drawTriangles(drawTriangles)
	{}
	void Update(const Vec3& scale, const Vec3& angle, const Vec3& position) override
	{
		this->scale = scale;
		this->angle = angle;
		this->position = position;
	}
	void Draw(Camera& cam, Perspective& per, Viewport& port, Graphics& gfx) const override
	{
		const Mat4 Transformation =
			Mat4::Scaling(scale) *
			Mat4::Rotation(angle) *
			Mat4::Translation(position)/* *
			cam.Transform()*/;

		// ---------------------------------------------------

		if (drawLines)
		{
			auto lines = grid.GetLines();

			for (auto i = lines.vertices.begin(),
				end = lines.vertices.end();
				i != end; i++)
			{
				*i *= Transformation;
				view.Transform(*i);
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
	}
private:
	Grid grid = Grid(1.0f);
	ViewTransform view;
	Vec3 scale;
	Vec3 angle;
	Vec3 position;

	bool drawLines = true;
	bool drawTriangles = true;
};


