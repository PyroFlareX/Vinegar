#include "Camera.h"

Camera::Camera()
{
	lerp = 2.5f;

	proj = vn::makeProjectionMatrix(80.0f, vn::vec2(800, 600));

	pos = vn::vec3(0.0f, 0.0f, 3.0f);
	rot = vn::vec3(0.0f);

	// Loading the SteamVR Runtime
	vr::EVRInitError eError = vr::VRInitError_None;
	m_pHMD = vr::VR_Init(&eError, vr::VRApplication_Scene);
}

vn::mat4 Camera::getVRproj(vr::Hmd_Eye nEye) const
{
	vr::HmdMatrix44_t mat = m_pHMD->GetProjectionMatrix(nEye, 0.1f, 1000.0f);
	const float matrix[] = {
		mat.m[0][0], mat.m[1][0], mat.m[2][0], mat.m[3][0],
		mat.m[0][1], mat.m[1][1], mat.m[2][1], mat.m[3][1],
		mat.m[0][2], mat.m[1][2], mat.m[2][2], mat.m[3][2],
		mat.m[0][3], mat.m[1][3], mat.m[2][3], mat.m[3][3]
	};
	glm::mat4 proj = glm::make_mat4(matrix);
	return proj;
}

vn::mat4 Camera::getVRview(vr::Hmd_Eye nEye) const
{
	vr::HmdMatrix34_t mat = m_pHMD->GetEyeToHeadTransform(nEye);
	const float matrix[] = {
		mat.m[0][0], mat.m[1][0], mat.m[2][0], 0.0f,
		mat.m[0][1], mat.m[1][1], mat.m[2][1], 0.0f,
		mat.m[0][2], mat.m[1][2], mat.m[2][2], 0.0f,
		mat.m[0][3], mat.m[1][3], mat.m[2][3], 1.0f
	};
	glm::mat4 view = glm::inverse(glm::make_mat4(matrix));
	return view;
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
	vr::VR_Shutdown();
}
