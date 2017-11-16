#pragma once
#include "Material.h"
class ColorMaterial :
	public Material
{
public:
	ColorMaterial();
	~ColorMaterial();

	void SetColor(const glm::vec3& color) {
		this->color = color;
	}
	// ͨ�� Material �̳�
	virtual glm::vec3 GetColor(const LightInfo & light, const Ray & ray, const glm::vec3 & pos, const glm::vec3 & normal) override;
};

