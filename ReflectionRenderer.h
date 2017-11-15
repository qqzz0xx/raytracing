#pragma once
#include "Renderer.h"
class ReflectionRenderer :
	public Renderer
{
public:
	ReflectionRenderer() :Renderer() {}
	ReflectionRenderer(std::string fileName) : Renderer(fileName) { }


	virtual glm::vec3 Tracing(const Ray& ray, const Scene& scene, int depth) override;

};

