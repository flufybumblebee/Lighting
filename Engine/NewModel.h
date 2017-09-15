#pragma once

#include <vector>
#include "Vec4.h"

#include "Model.h"

class NewModel : public Model
{
public:
	NewModel() {}

	NewModel( NewModel& model )
		:
		vertices( model.vertices ),
		indicesLine( model.indicesLine ),
		indicesTri( model.indicesTri )
	{}
	NewModel( std::vector<Vec4> vertices, std::vector<size_t> indicesLine, std::vector<size_t> indicesTri )
		:
		vertices( vertices ),
		indicesLine( indicesLine ),
		indicesTri( indicesTri )
	{}

	IndexedLineList GetLines() const override
	{
		return { vertices,indicesLine };
	}

	IndexedTriangleList GetTriangles() const override
	{
		return { vertices, indicesTri };
	}

private:
	std::vector< Vec4 >		vertices;
	std::vector< size_t >	indicesLine;
	std::vector< size_t >	indicesTri;
};


