#pragma once
#include "glm\glm.hpp"

class Ray
{
public:
	Ray(const glm::vec3& o, const glm::vec3& d)
		: origin(o), dir(d) {}

	glm::vec3 GetPoint(const float t)const;

public:
	glm::vec3 origin;
	glm::vec3 dir;
};

