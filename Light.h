#pragma once
#include "glm\glm.hpp"
class Light
{
public:
	Light(const glm::vec3 &d, const glm::vec3 &c) :
		dir(d), color(c) {}
	glm::vec3 dir;
	glm::vec3 color;
};

