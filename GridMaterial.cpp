#include "GridMaterial.h"
#include "glm\ext.hpp"


glm::vec3 GridMaterial::GetColor(const Light & light, const Ray & ray, const glm::vec3 & pos, const glm::vec3 & normal)
{
	if ((int)(glm::floor(pos.x * 0.1f) + glm::floor(pos.z * 0.1f)) % 2 == 0)
	{
		return glm::vec3(1) * this->color;
	}
	else
	{
		return glm::vec3(0) * this->color;
	}
}
