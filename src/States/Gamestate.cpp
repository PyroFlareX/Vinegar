#include "Gamestate.h"



GameState::GameState(Application& app)	:	Basestate(app)
{
	app.getCam().follow(m_player);

	static int x = 0;
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-2.0f, 2.0f, -3.0f),
		glm::vec3(-4.0f, 2.0f, -12.0f),
		glm::vec3(2.0f, 1.0f, -4.0f),
		glm::vec3(-2.0f,  3.0f, -8.0f),
		glm::vec3(1.0f, 2.0f, -3.0f),
		glm::vec3(2.0f,  2.0f, -3.0f),
		glm::vec3(2.0f,  0.0f, -2.0f),
		glm::vec3(-1.0f,  1.0f, -2.0f)
	};
	for (int i = 0; i < 10; ++i)
	{
		vn::Transform entity;

		entity.pos = vn::vec3(1.0f, 0.0f, 1.0f);
		entity.pos = cubePositions[i];
		entity.rescale(entity, vn::vec3(0.5f, 0.5f, 0.5f));
		entity.rotate(entity, vn::vec3(0, 360 * sin(x++ / 10000.0), 0));

		vn::GameObject gameobject(entity);

		m_gameObjects.emplace_back(gameobject);
		m_world.addObject(gameobject);
	}

}

GameState::~GameState()
{

}

bool GameState::input()
{

	vInput = Input::getInput();

	m_player.getInput(vInput, false);


	return false;
}

void GameState::update(float dt)
{
	


	m_player.update(dt);
	m_world.update(dt);
}

void GameState::lateUpdate(Camera* cam)
{

}

void GameState::render(Renderer* renderer)
{
	std::cout << "Gamestate: render\n";
		
	for (auto& obj : m_gameObjects)
	{
		renderer->drawObject(obj.getCurrentTransform());
	}


	//m_world.renderWorld(app.getCam(), *renderer);
}

