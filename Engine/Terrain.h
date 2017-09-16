#pragma once

#include "Model.h"
#include "Surface.h"

class Terrain : public Model
{
public:
	Terrain(const int& xSize = 10, const int& zSize = 10 )
	{
		// add array of heights and add in the loop
		int width = image.GetWidth();
		int height = image.GetHeight();

		float incrementX = width / float(xSize + 1);
		float incrementY = height / float(zSize + 1);

		int pixelY = 0;
		int i = 0;
		for (int z = -(zSize/2); z <= zSize/2; z++)
		{
			int pixelX = 0;
			for (int x = -(xSize/2); x <= xSize/2; x++)
			{
				float y = image.GetPixel(int(float(pixelX) * incrementX), (height - 1) - int(float(pixelY) * incrementY)).GetG()/20.0f;
				vertices.emplace_back((float)x, y, (float)z, 1.0f);
				
				if (i < (zSize + 1) * (xSize + 1))
				{
					indicesLine.emplace_back(size_t(i));
					if (i > 0 && i != ((zSize + 1) * (xSize + 1) - 1))
					{
						if ((i+1) % (xSize + 1) == 0) i++;
						indicesLine.emplace_back(size_t(i));
					}
					i++;
				}
				pixelX++;
			}
			pixelY++;
		}
		{
			int i = 0;
			int j = 0;
			for (; i < (xSize + 1);)
			{
				indicesLine.emplace_back(size_t(j));
				if (j >= (xSize + 1) * (zSize + 1) - (xSize + 1) && j < (xSize + 1) * (zSize + 1))
				{					
					i++;
					j = i;
				}
				else
				{
					if (j > xSize)
					{
						indicesLine.emplace_back(size_t(j));
					}
					j = j + (xSize + 1);
				}
			}
		}

		indicesTri = { 0,1,2 };
	}
/*
	IndexedLineList GetLines() const
	{		
		return { vertices, indicesLine };
	}

	IndexedTriangleList GetTriangles() const
	{
		return { vertices, indicesTri };
	}*/
private:
	/*std::vector<Vec4> vertices;
	std::vector<size_t> indicesLine;
	std::vector<size_t> indicesTri;*/

	Surface image = Surface::FromFile(L"HeightMapTerrain.jpg");
};
