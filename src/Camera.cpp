#include "Camera.h"

Camera::Camera()
{
	lerp = 2.5f;
	
	proj = vn::makeProjectionMatrix(80.0f, vn::vec2(800, 600));

	pos = vn::vec3(0.0f, 0.0f, 3.0f);
	rot = vn::vec3(0.0f);
}


void Camera::follow(vn::Transform& entity)
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
