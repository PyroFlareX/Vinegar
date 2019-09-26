#include "Gamestate.h"



GameState::GameState(Application& app)	: /*m_world(app.getCam(), m_player),*/	Basestate(app)
{
	TryPause = false;
	app.getCam().follow(m_player);
}

GameState::~GameState()
{

}

bool GameState::input()
{
	//if (!isPaused)
	//{
		vInput = Input::getInput();

		m_player.getInput(vInput);

		
		//if (vInput.pause)
		{
			//tryPause();
		}
	//}
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


	m_player.update(dt);
//	m_world.update();
}

void GameState::lateUpdate(Camera* cam)
{

}

void GameState::render(Renderer* renderer)
{
	/*glm::vec3 cubePositions[] = {
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
	{*/
	static int x = 0;

		vn::Transform entity;
		entity.pos = vn::vec3(1.0f, 0.0f, 1.0f);
		//entity.pos = cubePositions[i];
		entity.rescale(entity, vn::vec3(0.5f, 0.5f, 0.5f));
		entity.rotate(entity, vn::vec3(0, 0, 360 * sin(x++ / 1000.0)));
		renderer->drawObject(entity);
	//}
		

	//m_world.renderWorld(app.getCam(), *renderer);
}

void GameState::tryPause()
{
	TryPause = true;
}
