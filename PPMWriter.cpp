#include "PPMWriter.h"

#include <iostream>
#include <fstream>

PPMWriter::PPMWriter()
{
	pixels = nullptr;
}


PPMWriter::PPMWriter(int w, int h)
{
	width = w;
	height = h;
	pixels = new glm::vec3[w * h];

}

PPMWriter::~PPMWriter()
{
	delete[] pixels;
}

void PPMWriter::SetPixel(int w, int h, const glm::vec3 & color)
{
	pixels[h * width + w] = color;
}

void PPMWriter::SetName(const std::string & name)
{
	fileName = name;
}

void PPMWriter::Flush()
{
	if (pixels != nullptr)
	{
		std::ofstream ofs(fileName);
	
		ofs << "P3"<< std::endl;
		ofs << width << " " << height << std::endl;
		ofs << "255"<<std::endl;

		for (int i = 0; i < width; i++)
		{
			for (size_t j = 0; j < height; j++)
			{
				ofs <<(int) pixels[j* width + i].x  << " " << (int)pixels[j*width + i].y <<" " << (int)pixels[j*width + i].z<<"  ";

			}
			ofs << std::endl;
		}

		ofs.flush();
		ofs.close();
		ofs.clear();
	}
}
