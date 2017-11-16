#pragma once
#include "Renderer.h"
class ShadowRenderer :
	public Renderer
{
public:
	ShadowRenderer();
	ShadowRenderer(const std::string &name) :Renderer(name) {}
	~ShadowRenderer();

	virtual glm::vec3 Tracing(const Ray& ray, const Scene& scene, int depth) override;

};

