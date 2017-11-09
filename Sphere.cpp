#include "Sphere.h"



Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

bool Sphere::Hit(const Ray & ray, float tmin, float tmax, HitInfo & t)
{
	glm::vec3 v = ray.origin - this->center;

	//a x^2 + b x + c = 0
	float c = glm::dot(v, v) - sqrRadius;
	float d_dot_v = glm::dot(ray.dir, v);
	if (d_dot_v <= 0)
	{
		float discr = d_dot_v * d_dot_v - c;
		if (discr >= 0)
		{
			t.hitObject = this;
			t.distance = -d_dot_v - glm::sqrt(discr);
			t.position = ray.GetPoint(t.distance);
			t.normal = t.position - this->center;

			return true;
		}
	}


	return false;
}
