#pragma once
#include "glm\glm.hpp"
#include "Surface.h"
class Plane :
	public Surface
{
public:
	glm::vec3 normal, origin;
public:
	Plane();
	~Plane();
	Plane(Material* mate, const glm::vec3& n, const glm::vec3& o) :
		Surface(mate), normal(n), origin(o) {}
	// Í¨¹ý Surface ¼Ì³Ð
	virtual bool Hit(const Ray & ray, float tmin, float tmax, HitInfo & t) override;
};

