#pragma once
#include "glm\glm.hpp"
#include "Ray.h"
#include "Light.h"
enum MaterialType
{
	None,
	Grid,
	Phong,

};
class Material
{
public:
	glm::vec3 color;
	float reflectiveness;
	MaterialType type;
public:
	Material() { color = glm::vec3(1); type = MaterialType::None; }
	Material(const glm::vec3& c): Material(c, 0) { }
	Material(const glm::vec3& c, float refl) : color(c), reflectiveness(refl) {}
	virtual glm::vec3 GetColor(const LightInfo& light, const Ray& ray, const glm::vec3 &pos, const glm::vec3& normal) = 0;
};

