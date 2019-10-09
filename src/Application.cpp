#include "Application.h"

#include "States/Gamestate.h"


Application::Application()
{
	pushState(std::make_unique<GameState>(*this));
	
	vn::vr::initVR();
}

void Application::RunLoop()
{
	vn::Clock clock;
	float t = 0;
	float dt = 0;
	float frames = 0.0f;
	m_context.clear();
	m_context.update();
	vn::vec2 winSize = vn::vr::getRecommendedViewportSize();
	vn::Framebuffer leftEye(winSize);
	vn::Framebuffer rightEye(winSize);
	
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
		vn::vr::updateTracking();

        /// Draw
		currentState().render(&m_renderer);

        /// Render
		///If VR, then render one for each eye
		glViewport(0, 0, winSize.x, winSize.y);
		leftEye.bind();
		m_renderer.render(m_camera);
		rightEye.bind();
		m_renderer.render(m_camera);
		
		vr::Texture_t leftEyeTexture = { (void*)(uintptr_t)leftEye.getTexture().ID, vr::TextureType_OpenGL, vr::ColorSpace_Gamma };
		vr::VRCompositor()->Submit(vr::Eye_Left, &leftEyeTexture);
		vr::Texture_t rightEyeTexture = { (void*)(uintptr_t)rightEye.getTexture().ID, vr::TextureType_OpenGL, vr::ColorSpace_Gamma };
		vr::VRCompositor()->Submit(vr::Eye_Right, &rightEyeTexture);
		
		leftEye.getTexture().bind();
		glViewport(0, 0, 1280, 720);
		m_renderer.finish();

        m_context.update();

		glFlush();
		glFinish();

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
	vn::vr::ShutdownVR();
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
