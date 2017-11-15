#include "Renderer.h"
#include "PPMWriter.h"
#include "Scene.h"


void Renderer::Render(const Scene & scene)
{
	PPMWriter write(width, height);
	write.SetName(fileName);
	HitInfo hitinfo;
	for (int i = 0; i < height; i++)
	{
		float sy = i / (float)height;
		for (int j = 0; j < width; j++)
		{
			float sx = j / (float)width;
			Ray ray = scene.camera.GenerateRay(sx, 1 - sy);

			auto color = Tracing(ray, scene, 0);
			write.SetPixel(i, j, color);

		}
	}
	write.Flush();
}


glm::vec3 Renderer::Tracing(const Ray & ray, const Scene & scene, int depth)
{
	glm::vec3 color(0);
	static HitInfo hitinfo;
	if (scene.Hit(ray, 0, 200, hitinfo))
	{
		//float al = glm::min((hitinfo.distance / 20) * 255.0f, 255.0f);
		color =  hitinfo.hitObject->material->GetColor(scene.light, ray, hitinfo.position, hitinfo.normal);
	}
	return color;
}
