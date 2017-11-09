#pragma once
#include "Surface.h"
class Sphere :
	public Surface
{
public:
	float radius;
	float sqrRadius;
	glm::vec3 center;
public:

	Sphere(glm::vec3 c, float r) : center(c), radius(r), sqrRadius(r*r) {}
	Sphere();
	~Sphere();

	// Í¨¹ý Surface ¼Ì³Ð
	virtual bool Hit(const Ray & ray, float tmin, float tmax, HitInfo & t) override;
};

