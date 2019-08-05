#pragma once


#include "Backends/Input.h"
#include "Entity.h"
#include "Util/math.h"

class Camera : public Entity
{
public:
	Camera();

	glm::mat4 getViewMatrix(const Camera cam) const { return makeViewMatrix(*this); }
	glm::mat4 getProjMatrix() const { return proj; }

	void follow(Entity& entity);
	void update();

	~Camera();
private:
	float lerp;

	glm::mat4 proj;

	Entity* p_entity;
};

