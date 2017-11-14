#pragma once
#include "Material.h"
#include "Light.h"

class PhongMaterial : public Material
{
public:
	float diffuse, specular, shininess, reflectiveness;
public:
	PhongMaterial();
	~PhongMaterial();

	PhongMaterial(const glm::vec3& color, float diff, float spec, float shin, float refl) :
		Material(color), diffuse(diff), specular(spec), shininess(shin), reflectiveness(refl) {}

	// Í¨¹ý Material ¼Ì³Ð
	virtual glm::vec3 GetColor(const Light & light, const Ray & ray, const glm::vec3 & pos, const glm::vec3 & normal) override;

};

