#pragma once
#include "glm\glm.hpp"
#include "Ray.h"
class Camera
{
public:
	Camera();
	~Camera();

	void LookAt(const glm::vec3& eye, const glm::vec3& target, const glm::vec3 up, const float fov);
	Ray GenerateRay(float x, float y);

public:
	glm::vec3 eye, target, up;
	glm::vec3 right, front;
	float fov;
};

