#pragma one

#include "Renderer.h"

class TestRenderer : public Renderer
{
private:
	int width = 500;
	int height = 500;
public:
	TestRenderer();
	~TestRenderer();


	// ͨ�� Renderer �̳�
	virtual void Render(const Scene & scnen) override;

};

