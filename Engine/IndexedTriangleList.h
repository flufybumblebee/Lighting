#pragma once

#include <vector>
#include "Vec3.h"

//struct before adding backface culling
//struct IndexedTriangleList
//{
//	std::vector< Vec3 > vertices;
//	std::vector< int > indices;
//};

struct IndexedTriangleList
{
	IndexedTriangleList(std::vector<Vec3> vertices_in, std::vector<unsigned int> indices_in)
		:
		vertices( std::move(vertices_in) ),
		indices( std::move(indices_in) )
	{
		assert(vertices.size() > 2);
		assert(indices.size() % 3 == 0);
		cullflags.resize( indices.size() / 3 , false );
	}
	std::vector< Vec3 > vertices;
	std::vector< unsigned int > indices;
	std::vector< bool > cullflags;
};
