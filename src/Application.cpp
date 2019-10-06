#include "Application.h"

#include "States/Gamestate.h"


Application::Application()
{
	pushState(std::make_unique<GameState>(*this));
}

void Application::RunLoop()
{
	vn::Clock clock;
	float t = 0;
	float dt = 0;
	float frames = 0.0f;
	m_context.clear();
	m_context.update();
//===================================================================================
	



//===================================================================================

	//Main Loop
	Input::window = m_context.getContext();
    while(m_context.isOpen() && !m_states.empty())
    {
		dt = clock.restart();
        ///Main Loop, do cycle of Input, Update, Draw, Render & Swap Buffers, Handle Events
        ///Input
		currentState().input();
		
        /// Update
        currentState().update(dt);
		currentState().lateUpdate(&m_camera);
		m_camera.update();

        /// Draw
		currentState().render(&m_renderer);

        /// Render
		m_context.clear();
		m_renderer.render(m_camera);

		m_renderer.clearQueue();
		
        m_context.update();

        /// Handle Window Events
		t += dt;
		frames++;
		if (t >= 1)
		{
			std::cout << frames << " per sec\n";
			t = 0;
			frames = 0;
		}
		handleEvents();
    }
	m_context.close();
}

void Application::popState()
{
    m_states.pop_back();
}

Basestate& Application::currentState()
{
    return *m_states.back();
}

void Application::handleEvents()
{
	
}
