#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

bool Scene::Hit(const Ray & ray, float tmin, float tmax, HitInfo & t)
{
	float distMin = tmax;
	HitInfo temp;
	for each (const auto& var in surfaces)
	{
		if (var->Hit(ray, tmin, tmax, temp))
		{
			if (temp.distance < distMin)
			{
				t = temp;
				distMin = temp.distance;
			}
		}
	}
	return distMin != tmax;
}

bool Scene::Hit(const Ray & ray, float tmin, float tmax, HitInfo & t) const
{
	float distMin = tmax;
	HitInfo temp;
	for each (const auto& var in surfaces)
	{
		if (var->Hit(ray, tmin, tmax, temp))
		{
			if (temp.distance < distMin)
			{
				t = temp;
				distMin = temp.distance;
			}
		}
	}
	return distMin != tmax;
}
