#include "Plane.h"



Plane::Plane()
{
}


Plane::~Plane()
{
}

bool Plane::Hit(const Ray & ray, float tmin, float tmax, HitInfo & t)
{
	float cosa = glm::dot(ray.dir, -this->normal);
	if (cosa < 0) return false;

	float ray2planeDist = glm::dot((ray.origin - this->origin), this->normal);
	t.distance = ray2planeDist / cosa;
	if (t.distance < tmin || t.distance > tmax) return false;
	t.position = ray.GetPoint(t.distance);
	t.normal = this->normal;
	t.hitObject = this;

	return true;
}
