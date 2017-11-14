#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

bool Scene::Hit(const Ray & ray, float tmin, float tmax, HitInfo & t)
{
	for each (const auto& var in surfaces)
	{
		if (var->Hit(ray, tmin, tmax, t))
		{
			return true;
		}
	}
	return false;
}

bool Scene::Hit(const Ray & ray, float tmin, float tmax, HitInfo & t) const
{
	for each (const auto& var in surfaces)
	{
		if (var->Hit(ray, tmin, tmax, t))
		{
			return true;
		}
	}
	return false;
}
