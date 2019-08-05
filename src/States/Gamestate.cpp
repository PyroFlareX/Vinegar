#include "../../include/States/Gamestate.h"



GameState::GameState(Application& app)	: /*m_world(app.getCam(), m_player),*/	Basestate(app)
{
	TryPause = false;
}

GameState::~GameState()
{

}

bool GameState::input()
{
	if (!isPaused)
	{
		vInput = Input::getInput();

		m_player.getInput(vInput);

		
		if (vInput.pause)
		{
			tryPause();
		}
	}
	return false;
}

void GameState::update(float dt)
{
	/*if (window->hasFocus() && !TryPause)
	{
		isPaused = false;
	}
	else
	{
		isPaused = true;
		TryPause = false;
	}*/

	if (!isPaused)
	{
		m_player.update(dt);
		//m_world.update();
	}
}

void GameState::lateUpdate(Camera* cam)
{
	cam->follow(m_player);
}

void GameState::render(Renderer* renderer)
{
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-2.0f, -2.0f, -3.0f),
		glm::vec3(-4.0f, -2.0f, -12.0f),
		glm::vec3(2.0f, -1.0f, -4.0f),
		glm::vec3(-2.0f,  3.0f, -8.0f),
		glm::vec3(1.0f, -2.0f, -3.0f),
		glm::vec3(2.0f,  2.0f, -3.0f),
		glm::vec3(2.0f,  0.0f, -2.0f),
		glm::vec3(-1.0f,  1.0f, -2.0f)
	};
	for (int i = 0; i < 10; ++i)
	{
		Entity entity;
		entity.pos = cubePositions[i];
		//entity.rot.x = i * 20.0f;
		renderer->drawCube(entity);
	}

	//m_world.renderWorld(app.getCam(), *renderer);
}

void GameState::tryPause()
{
	TryPause = true;
}
