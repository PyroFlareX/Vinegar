#include "../../include/Renderers/ComputeRenderer.h"

ComputeRenderer::ComputeRenderer()
{
	m_shader.addShader("res/Shaders/compute.glsl", GL_COMPUTE_SHADER);
}

void ComputeRenderer::render()
{
	m_shader.use();
	
	glDispatchCompute(1, 1, 1);
}

ComputeRenderer::~ComputeRenderer()
{

}
