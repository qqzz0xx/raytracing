#include "PhongMaterial.h"



PhongMaterial::PhongMaterial()
{
}


PhongMaterial::~PhongMaterial()
{
}

glm::vec3 PhongMaterial::GetColor(const Light & light, const Ray & ray, const glm::vec3 & pos, const glm::vec3 & normal)
{
	float l_dot_n = glm::dot(light.dir, normal);
	float diff = this->diffuse * glm::max(0.0f, l_dot_n);
	glm::vec3 H = glm::normalize(ray.dir + light.dir);
	float h_dot_n = glm::dot(H, normal);
	float spec = this->specular * glm::pow(glm::max(h_dot_n, 0.0f), shininess);
	return (diff + spec)* color * light.color;
}


