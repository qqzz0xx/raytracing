#include "Ray.h"

glm::vec3 Ray::GetPoint(const float t) const
{
	return origin + dir * t;
}
