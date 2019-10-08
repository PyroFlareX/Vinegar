#pragma once

#include "Backends/Input.h"
#include "../Engine/Engine.h"

class Camera : public vn::Transform
{
public:
	Camera();

	vn::mat4 getViewMatrix() const { return vn::makeViewMatrix(*this); }
	glm::mat4 getProjMatrix() const { return proj; }

	void follow(vn::Transform& entity);
	void update();

	
	~Camera();
private:
	float lerp;

	glm::mat4 proj;

	vn::Transform* p_entity;
};

