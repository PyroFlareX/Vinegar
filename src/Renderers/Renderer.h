#ifndef RENDERER_H
#define RENDERER_H

#include "../Camera.h"
#include "CubeRenderer.h"
#include "GeneralRenderer.h"
#include "ComputeRenderer.h"
#include "../../Engine/Engine.h"


class Renderer
{
    public:
        Renderer();

		void drawCube(vn::Transform& entity);
		void drawObject(vn::Transform& entity);
		void doCompute();
		void render(Camera& cam);

		void clearQueue();

		//Mode 0 is default, Mode 1 is VR
		unsigned int mode = 0;

        ~Renderer();
    protected:

    private:
		CubeRenderer m_cubeRenderer;
		GeneralRenderer m_generalRenderer;
		ComputeRenderer m_computeRenderer;

		vn::Framebuffer m_framebuffer;

		Model m_quad;
		Shader m_shader;
};

#endif // RENDERER_H
