#pragma once
#include "Scene.h"

class Renderer
{
protected:
	int width = 500;
	int height = 500;
	std::string fileName;
public:
	Renderer() { fileName = "test.ppm"; }
	Renderer(std::string & imgName): fileName(imgName) {}
	virtual void Render(const Scene& scene);
	virtual glm::vec3 Tracing(const Ray& ray, const Scene& scene, int depth);
};

