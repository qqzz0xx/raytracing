#pragma once
#include "glm\glm.hpp"
#include "Ray.h"
#include "Light.h"
class Material
{
public:
	glm::vec3 color;
public:
	Material() {}
	Material(const glm::vec3& c) : color(c) {}
	virtual glm::vec3 GetColor(const Light& light, const Ray& ray, const glm::vec3 &pos, const glm::vec3& normal) = 0;
};

