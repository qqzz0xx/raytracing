#include "ShadowRenderer.h"



ShadowRenderer::ShadowRenderer()
{
}


ShadowRenderer::~ShadowRenderer()
{
}

glm::vec3 ShadowRenderer::Tracing(const Ray& ray, const Scene& scene, int depth)
{
	glm::vec3 color(0);
	static HitInfo hitinfo;
	if (scene.Hit(ray, 0, 200, hitinfo))
	{
		auto lightInfo = scene.light->GetLightInfo(scene, hitinfo.position);

		if (lightInfo.dir != glm::vec3(0))
		{
			color = lightInfo.color * glm::max(0.0f, glm::dot(lightInfo.dir, hitinfo.normal));
		}

	}

	return color;
}
