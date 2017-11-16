#pragma once
#include "Camera.h"
#include "Ray.h"
#include "Light.h"
#include "Surface.h"

#include <vector>

class Scene
{
public:
	Scene();
	~Scene();
	void SetCamera(Camera* camera)
	{
		this->camera = camera;
	}
	void SetLight( Light* light)
	{
		this->light = light;
	}
	void AddSurface(Surface* surf) {
		surfaces.push_back(surf);
	}

	bool Hit(const Ray & ray, float tmin, float tmax, HitInfo & t);
	bool Hit(const Ray & ray, float tmin, float tmax, HitInfo & t) const;
public:
	Camera* camera;
	Light* light;
	std::vector<Surface*> surfaces;
};

