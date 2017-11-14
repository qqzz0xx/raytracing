#pragma once
#include "Ray.h"
#include "Material.h"

class Surface;

struct HitInfo
{
	Surface* hitObject;
	glm::vec3 position;
	glm::vec3 normal;
	float distance;
};

class Surface
{
public:

	virtual bool Hit(const Ray& ray, float tmin, float tmax, HitInfo& t) = 0;
	Surface(Material* mate) : material(mate) {}
	Surface() { material = nullptr; }
public:
	glm::vec4 color;
	glm::vec3 emissive;

	Material* material;
};

