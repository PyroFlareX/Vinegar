#include "../../include/Util/math.h"

#include "../../include/Camera.h"

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

const glm::mat4 makeProjectionMatrix(float fov, int x, int y)
{
	return glm::perspective(glm::radians(fov), float(x) / y, 0.001f, 1000.0f);
}