#pragma once

#include "../Model.h"
#include "../Camera.h"
#include "../Shaders/Shader.h"
#include "../Texture/Texture.h"

class CubeRenderer
{
public:
	CubeRenderer();

	void addCube(Entity& entity);
	void render(Camera& cam);

	~CubeRenderer();
private:
	std::vector<Entity> m_queue;
	Shader m_shader;
	Model m_cubeModel;
	Texture tex;
	sf::Image img;
};

