#pragma once
#include "Light.h"

class DirectionalLight:
	public Light
{
public:
	DirectionalLight();
	DirectionalLight(const glm::vec3& p, const glm::vec3 &c, const glm::vec3 &d)
	{
		Init(p, c, d, true, glm::vec3(0));
	}
	DirectionalLight(const glm::vec3& p, const glm::vec3 &c, const glm::vec3 &d, bool isUseShadow)
	{
		Init(p, c, d, isUseShadow, glm::vec3(0));
	}
	~DirectionalLight();

	void Init(const glm::vec3& p, const glm::vec3 &c, const glm::vec3 &d, bool bshadow, glm::vec3 &sc)
	{
		pos = p;
		color = c;
		dir = glm::normalize(d);
		IsUseShadow = bshadow;
		shadowColor = sc;
	}


	virtual LightInfo GetLightInfo(const Scene& scene, const glm::vec3 pos) override;

public:
	glm::vec3 dir;
	bool IsUseShadow ;
	glm::vec3 shadowColor ; 
};

