#pragma once

#include <vector>
#include "Model.h"
#include "Vec4.h"
#include "IndexedLineList.h"

class Terrain : public Model
{
public:
	Terrain(const int xSize, const int zSize )
	{
		int i = 0;
		for (int z = -(zSize/2); z <= zSize/2; z++)
		{
			for (int x = -(xSize/2); x <= xSize/2; x++)
			{
				vertices.emplace_back((float)x, (float)0, (float)z, (float)1);
				
				if (i < (zSize + 1) * (xSize + 1))
				{
					indices.emplace_back(size_t(i));
					if (i > 0 && i != ((zSize + 1) * (xSize + 1) - 1))
					{
						if ((i+1) % (xSize + 1) == 0) i++;
						indices.emplace_back(size_t(i));						
					}
					i++;
				}
			}
		}
		{
			int i = 0;
			int j = 0;
			for (; i < (xSize + 1);)
			{
				indices.emplace_back(size_t(j));
				if (j >= (xSize + 1) * (zSize + 1) - (xSize + 1) && j < (xSize + 1) * (zSize + 1))
				{					
					i++;
					j = i;
				}
				else
				{
					if (j > xSize)
					{
						indices.emplace_back(size_t(j));
					}
					j = j + (xSize + 1);
				}
			}
		}
	}

	IndexedLineList GetLines() const override
	{		
		return { vertices, indices };
	}

	IndexedTriangleList GetTriangles() const override
	{
		return { vertices, indices };
	}
private:

	std::vector<Vec4> vertices;
	std::vector<size_t> indices;
};
