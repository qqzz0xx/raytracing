#include "ColorMaterial.h"



ColorMaterial::ColorMaterial()
{
}


ColorMaterial::~ColorMaterial()
{
}

glm::vec3 ColorMaterial::GetColor(const LightInfo & light, const Ray & ray, const glm::vec3 & pos, const glm::vec3 & normal)
{
	if (light.isShadow == true) return light.color;
	return this->color;
}
