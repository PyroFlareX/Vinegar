#include "Camera.h"

Camera::Camera(sf::RenderWindow* p_win)
{
	p_window = p_win;
	lerp = 2.5f;

	proj = makeProjectionMatrix(80.0f, (sf::Vector2i)(p_window->getSize()));

	pos = glm::vec3(0.0f, 0.0f, 3.0f);
	rot = glm::vec3(0.0f);

	//p_window->setFramerateLimit(60);
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
