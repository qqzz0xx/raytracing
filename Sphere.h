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

	Sphere(Material* mate, glm::vec3 c, float r) : center(c), radius(r), sqrRadius(r*r), Surface(mate) {}
	Sphere();
	~Sphere();

	// ͨ�� Surface �̳�
	virtual bool Hit(const Ray & ray, float tmin, float tmax, HitInfo & t) override;
};

