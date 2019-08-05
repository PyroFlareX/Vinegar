#include "math.h"

#include "../Camera.h"

const glm::mat4 makeViewMatrix(const Camera & camera)
{
	glm::mat4 matrix = glm::mat4(1.0f);

	matrix = glm::rotate(matrix, glm::radians(camera.rot.x), { 1, 0, 0 });
	matrix = glm::rotate(matrix, glm::radians(camera.rot.y), { 0, 1, 0 });
	matrix = glm::rotate(matrix, glm::radians(camera.rot.z), { 0, 0, 1 });

	matrix = glm::translate(matrix, -camera.pos);

	return matrix;
}

const glm::mat4 makeModelMatrix(const Entity& entity)
{
	glm::mat4 matrix = glm::mat4(1.0f);

	matrix = glm::rotate(matrix, glm::radians(entity.rot.x), entity.pos/*{ 1, 0, 0 }*/);
	matrix = glm::rotate(matrix, glm::radians(entity.rot.y), entity.pos/*{ 0, 1, 0 }*/);
	matrix = glm::rotate(matrix, glm::radians(entity.rot.z), entity.pos/*{ 0, 0, 1 }*/);

	matrix = glm::translate(matrix, entity.pos);

	return matrix;
}

/*constexpr glm::mat4 makeProjectionMatrix(const float fov)
{
	return glm::perspective(glm::radians(fov), (800.0f / 600.0f), 0.1f, 1000.0f);
}*/
const glm::mat4 makeProjectionMatrix(float fov, sf::Vector2i winSize)
{
	return glm::perspective(glm::radians(fov), ((float)winSize.x / winSize.y), 0.001f, 1000.0f);
}