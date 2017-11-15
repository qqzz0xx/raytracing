#pragma once
#include "glm\glm.hpp"
inline glm::vec3 modulate(const glm::vec3& v1, const glm::vec3& v2)
{
	return glm::vec3(v1.x*v2.x, v1.y*v2.y, v1.z*v2.z);
}