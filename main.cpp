#include "PPMWriter.h"
#include "Sphere.h"
#include "Camera.h"
#include "Ray.h"
#include "PhongMaterial.h"
#include "Scene.h"
#include "TestRenderer.h"


int main()
{
	Material* redMate = new PhongMaterial(glm::vec3(1,0,0), 1, 1, 1, 0);
	Material* blueMate = new PhongMaterial(glm::vec3(0, 0, 1), 1, 1, 1, 0);
	Sphere sphere(redMate, glm::vec3(-10, 10, -10), 10);
	Sphere sphere1(blueMate, glm::vec3(10, 10, -10), 10);

	Camera camera;
	camera.LookAt(glm::vec3(0, 5, 15),( sphere.center + sphere1.center)*0.5f, glm::vec3(0, 1, 0), 90);
	float maxDistance = 20;
	int w = 500;
	int h = 500;
	
	Scene scene;
	scene.SetCamera(camera);
	scene.AddSurface(&sphere);
	scene.AddSurface(&sphere1);

	TestRenderer renderer;
	renderer.Render(scene);


	//PPMWriter write(w, h);
	//write.SetName("test1.ppm");
	//HitInfo hitinfo;
	//for (int i = 0 ;i < w; i++)
	//{
	//	float sx = i /(float) w;
	//	for (int j = 0; j < h; j++)
	//	{
	//		float sy = j /(float) h;

	//		Ray ray = camera.GenerateRay(sx, sy);
	//		if (sphere.Hit(ray, 0, 200, hitinfo))
	//		{
	//			float al = glm::min((hitinfo.distance / maxDistance) * 255.0f, 255.0f);

	//			write.SetPixel(i, j, glm::vec3(al));
	//		}

	//	}
	//}
	//write.Flush();
}