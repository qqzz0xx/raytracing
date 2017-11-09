#include "PPMWriter.h"
#include "Sphere.h"
#include "Camera.h"
#include "Ray.h"

int main()
{

	Sphere sphere(glm::vec3(0, 10, -10), 10);
	Camera camera;
	camera.LookAt(glm::vec3(0, 10, 10), sphere.center, glm::vec3(0, 1, 0), 90);
	float maxDistance = 20;
	int w = 500;
	int h = 500;
	
	
	

	PPMWriter write(w, h);
	write.SetName("test1.ppm");
	HitInfo hitinfo;
	for (int i = 0 ;i < w; i++)
	{
		float sx = i /(float) w;
		for (int j = 0; j < h; j++)
		{
			float sy = j /(float) h;

			Ray ray = camera.GenerateRay(sx, sy);
			if (sphere.Hit(ray, 0, 200, hitinfo))
			{
				float al = glm::min((hitinfo.distance / maxDistance) * 255.0f, 255.0f);

				write.SetPixel(i, j, glm::vec3(al));
			}

		}
	}
	write.Flush();
}