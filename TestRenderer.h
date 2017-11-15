#pragma one

#include "Renderer.h"

class TestRenderer : public Renderer
{

public:
	TestRenderer();
	~TestRenderer();

	virtual glm::vec3 Tracing(const Ray& ray, const Scene& scene, int depth) override;

};

