#pragma once

#include "Backends/Input.h"
#include "../Engine/Engine.h"
#include <openvr.h>

class Camera : public vn::Transform
{
public:
	Camera();

	vn::mat4 getViewMatrix() const { return vn::makeViewMatrix(*this); }
	glm::mat4 getProjMatrix() const { return proj; }

	vn::mat4 getVRproj(vr::Hmd_Eye nEye) const;
	vn::mat4 getVRview(vr::Hmd_Eye nEye) const;

	void follow(vn::Transform& entity);
	void update();

	vr::IVRSystem* getHMDptr() { return m_pHMD; }

	~Camera();
private:
	float lerp;

	glm::mat4 proj;

	vr::IVRSystem* m_pHMD;
	vn::Transform* p_entity;
};

