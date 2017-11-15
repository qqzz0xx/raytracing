#include "ReflectionRenderer.h"




glm::vec3 ReflectionRenderer::Tracing(const Ray& ray, const Scene& scene, int depth)
{
	glm::vec3 color(0);
	glm::vec3 reflColor(0);
	HitInfo hitinfo;
	if (scene.Hit(ray, 0, 200, hitinfo))
	{
		color = hitinfo.hitObject->material->GetColor(scene.light, ray, hitinfo.position, hitinfo.normal);

		if (hitinfo.hitObject->material->reflectiveness > 1e-5 && depth < 5)
		{
			glm::vec3 reflDir = hitinfo.normal * (2 * glm::dot(hitinfo.normal, -ray.dir)) + ray.dir;
			Ray reflRay(hitinfo.position, reflDir);
			reflColor = Tracing(reflRay, scene, depth + 1);
			color = color * (1-hitinfo.hitObject->material->reflectiveness)
				+ reflColor * (hitinfo.hitObject->material->reflectiveness);
		}

	}

	return color;

}

