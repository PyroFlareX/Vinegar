#pragma once

#include "../Model.h"
#include "../Camera.h"
#include "../Shaders/Shader.h"
#include "../../Engine/Engine.h"

class GeneralRenderer
{
public:
	GeneralRenderer();

	void addInstance(vn::Transform entity);
	void render(Camera& cam);

	void clearQueue();

	~GeneralRenderer();
private:
	std::vector<vn::Transform> m_queue;
	Shader m_shader;
	Model m_generalModel;
	Shader m_lampshader;
	Model m_lampModel;
	vn::Image img;
	vn::Texture tex;
};

