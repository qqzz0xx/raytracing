#pragma once
#include "Material.h"
#include "Light.h"

class PhongMaterial : public Material
{
public:
	float diffuse, specular, shininess, reflectiveness;
	glm::vec3 color;
public:
	PhongMaterial();
	~PhongMaterial();



	// Í¨¹ý Material ¼Ì³Ð
	virtual glm::vec3 GetColor(const Light & light, const Ray & ray, const glm::vec3 & pos, const glm::vec3 & normal) override;

};

