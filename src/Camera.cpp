#include "../include/Camera.h"

Camera::Camera()
{
	lerp = 2.5f;

	proj = makeProjectionMatrix(80.0f, 800, 600);

	pos = glm::vec3(0.0f, 0.0f, 3.0f);
	rot = glm::vec3(0.0f);
}

void Camera::follow(Entity& entity)
{
	p_entity = &entity;
}

void Camera::update()
{
	pos = p_entity->pos;
	rot = p_entity->rot;
	if (rot.x > 90.0f) { rot.x = 89.9f; }
	if (rot.x < -90.0f) { rot.x = -89.9f; }
}

Camera::~Camera()
{

}
