#include "DirectionalLight.h"
#include "Ray.h"
#include "Surface.h"
#include "Scene.h"

DirectionalLight::DirectionalLight()
{
}


DirectionalLight::~DirectionalLight()
{
}

LightInfo DirectionalLight::GetLightInfo(const Scene& scene, const glm::vec3 pos)
{
	LightInfo  lightInfo;
	if (IsUseShadow)
	{
		Ray shadowRay(pos, dir);
		HitInfo t;
		if (scene.Hit(shadowRay, 0, 200, t))
		{
			lightInfo.dir = glm::vec3(0);
			lightInfo.color = shadowColor;
			lightInfo.isShadow = true;
			return lightInfo;
		}

	}
	lightInfo.dir = dir;
	lightInfo.color = color;
	lightInfo.isShadow = false;
	return lightInfo;
}
