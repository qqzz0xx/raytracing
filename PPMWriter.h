#pragma once
#include "glm\glm.hpp"

#include <string>

class PPMWriter
{
public:
	PPMWriter();
	PPMWriter(int w, int h);
	~PPMWriter();

	void SetPixel(int w, int h, const glm::vec3& color);
	void SetName(const std::string & name);
	void Flush();
private:
	glm::vec3 *pixels;
	int width, height;
	std::string fileName;
};

