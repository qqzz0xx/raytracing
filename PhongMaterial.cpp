#include "PhongMaterial.h"

#include "Comm.h"

glm::vec3 PhongMaterial::GetColor(const Light & light, const Ray & ray, const glm::vec3 & pos, const glm::vec3 & normal)
{
	float l_dot_n = glm::dot(light.dir, normal);
	float diff = this->diffuse * glm::max(0.0f, l_dot_n);
	glm::vec3 H = glm::normalize(-ray.dir + light.dir);
	float h_dot_n = glm::dot(H, normal);
	float spec = this->specular * glm::pow(glm::max(h_dot_n, 0.0f), shininess);
	glm::vec3 col = (diff * this->color + glm::vec3(1) *spec) * light.color;
	return glm::clamp (col,  glm::vec3(0), glm::vec3(1));
}


