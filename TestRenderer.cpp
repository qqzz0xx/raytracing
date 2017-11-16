#include "TestRenderer.h"
#include "PPMWriter.h"
#include "Surface.h"

#include "glm\glm.hpp"

TestRenderer::TestRenderer()
{
}

TestRenderer::~TestRenderer()
{
}

glm::vec3 TestRenderer::Tracing(const Ray& ray, const Scene& scene, int depth)
{
	glm::vec3 color(0);
	static HitInfo hitinfo;
	if (scene.Hit(ray, 0, 200, hitinfo))
	{
		//float al = glm::min((hitinfo.distance / 20) * 255.0f, 255.0f);
		auto lightInfo = scene.light->GetLightInfo(scene, hitinfo.position);
		color = hitinfo.hitObject->material->GetColor(lightInfo, ray, hitinfo.position, hitinfo.normal);
	}
	return color;
}
