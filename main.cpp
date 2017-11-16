#include "PPMWriter.h"
#include "Sphere.h"
#include "Camera.h"
#include "Ray.h"
#include "PhongMaterial.h"
#include "Scene.h"
#include "TestRenderer.h"
#include "GridMaterial.h"
#include "Plane.h"
#include "ReflectionRenderer.h"
#include "DirectionalLight.h"
#include "ShadowRenderer.h"
#include "ColorMaterial.h"
int main()
{
	Material* redMate = new PhongMaterial(glm::vec3(1,0,0), 1, 1, 16, 0.25);
	Material* blueMate = new PhongMaterial(glm::vec3(0, 0, 1), 1, 1, 16, 0.25);
	Material* gridMate = new GridMaterial();
	ColorMaterial* colorMate = new ColorMaterial();
	colorMate->SetColor(glm::vec3(1));

	Sphere sphere(redMate, glm::vec3(-10, 10, -10), 10);
	Sphere sphere1(blueMate, glm::vec3(10, 10, -10), 10);
	Plane plane(colorMate, glm::vec3(0, 1, 0), glm::vec3(0, 0, 0));
	Camera camera;
	camera.LookAt(glm::vec3(0, 5, 15),( sphere.center + sphere1.center)*0.5f, glm::vec3(0, 1, 0), 90);

	
	DirectionalLight directionalLight(glm::vec3(1, 1, 1), glm::vec3(1, 1, 1), glm::vec3(1, 1, 1), true);
	Scene scene;
	scene.SetLight(&directionalLight);
	scene.SetCamera(&camera);
	scene.AddSurface(&sphere);
	scene.AddSurface(&sphere1);
	scene.AddSurface(&plane);

	//Renderer renderer;
	//renderer.Render(scene);

	ReflectionRenderer reflectionRenderer("refl.ppm");
	reflectionRenderer.Render(scene);

	//ShadowRenderer shadowRenderer("shadow.ppm");
	//shadowRenderer.Render(scene);

}