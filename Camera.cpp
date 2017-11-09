#include "Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::LookAt(const glm::vec3 & eye, const glm::vec3 & target, const glm::vec3 up, const float fov)
{
	this->eye = eye;
	this->target = target;
	this->fov = fov;
	this->front = glm::normalize(target - eye);
	this->right = glm::normalize(glm::cross(front, up));
	this->up = glm::normalize(glm::cross(this->right, target - eye));

}

Ray Camera::GenerateRay(float x, float y)
{
	float half = glm::tan(glm::radians(this->fov * 0.5f));
	glm::vec3 dx = this->right * ((x - 0.5f) *2 * half);
	glm::vec3 dy = this->up *((y - 0.5f) * 2 * half);
	glm::vec3 d = glm::normalize(this->front + dx + dy);

	return Ray(this->eye, d);
}
