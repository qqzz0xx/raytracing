#pragma once
#include "Scene.h"
class Renderer
{
public:

	virtual void Render(const Scene& scnen) = 0;
};

