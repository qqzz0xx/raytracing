#pragma once
#include "glm\glm.hpp"
class Scene;

struct LightInfo
{
	glm::vec3 dir, color;
	bool isShadow;
};

class Light
{
public:
	Light(const glm::vec3 &p, const glm::vec3 &c) :
		pos(p), color(c) {}
	Light() {
		color = glm::vec3(1, 1, 1);
		pos = glm::normalize(glm::vec3(1, 1, 1));
	}

	virtual LightInfo GetLightInfo(const Scene& scene, const glm::vec3 pos) { return LightInfo(); }
public:
	glm::vec3 pos;
	glm::vec3 color;
};

