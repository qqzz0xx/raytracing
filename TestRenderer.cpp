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

void TestRenderer::Render(const Scene & scene)
{

	PPMWriter write(width, height);
	write.SetName("test1.ppm");
	HitInfo hitinfo;
	for (int i = 0; i < width; i++)
	{
		float sx = i / (float)width;
		for (int j = 0; j < height; j++)
		{
			float sy = j / (float)height;
			scene.camera.GenerateRay(sx, sy);
			Ray ray = scene.camera.GenerateRay(sx, sy);

			if (scene.Hit(ray, 0, 200, hitinfo))
			{
				//float al = glm::min((hitinfo.distance / 20) * 255.0f, 255.0f);
				auto color = hitinfo.hitObject->material->GetColor(scene.light, ray, hitinfo.position, hitinfo.normal);
				write.SetPixel(i, j, color);
			}

		}
	}
	write.Flush();

}
