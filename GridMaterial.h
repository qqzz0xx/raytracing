#pragma once
#include "Material.h"
class GridMaterial : public Material
{
public:
	// ͨ�� Material �̳�
	virtual glm::vec3 GetColor(const Light & light, const Ray & ray, const glm::vec3 & pos, const glm::vec3 & normal) override;
};

