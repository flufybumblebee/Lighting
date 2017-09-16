#pragma once

#include <vector>
#include "Vec4.h"
#include "IndexedLineList.h"
#include "IndexedTriangleList.h"

class Model
{
public:
	Model() {}

	Model( Model& model )
		:
		vertices( model.vertices ),
		indicesLine( model.indicesLine ),
		indicesTri( model.indicesTri )
	{}
	Model( std::vector<Vec4> vertices, std::vector<size_t> indicesLine, std::vector<size_t> indicesTri )
		:
		vertices( vertices ),
		indicesLine( indicesLine ),
		indicesTri( indicesTri )
	{}

	IndexedLineList GetLines() const
	{
		return { vertices,indicesLine };
	}

	IndexedTriangleList GetTriangles() const
	{
		return { vertices, indicesTri };
	}

public:
	std::vector< Vec4 >		vertices;
	std::vector< size_t >	indicesLine;
	std::vector< size_t >	indicesTri;
};


