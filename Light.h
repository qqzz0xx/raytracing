#pragma once
#include "glm\glm.hpp"
class Light
{
public:
	Light(const glm::vec3 &d, const glm::vec3 &c) :
		dir(d), color(c) {}
	Light() {
		color = glm::vec3(1, 1, 0);
		dir = glm::normalize(glm::vec3(1, 1, 1));
	}
public:
	glm::vec3 dir;
	glm::vec3 color;
};

