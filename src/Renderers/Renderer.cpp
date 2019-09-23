#include "Renderer.h"

Renderer::Renderer()
{
    //ctor
}

void Renderer::drawCube(vn::Transform& entity)
{
	m_cubeRenderer.addCube(entity);
}

void Renderer::drawObject(vn::Transform& entity)
{
	m_generalRenderer.addInstance(entity);
}

void Renderer::doCompute()
{
//	m_computeRenderer.
}

/*void Renderer::drawChunk(ChunkMesh& mesh)
{
	m_chunkRenderer.addChunk(mesh);
}*/

void Renderer::render(Camera& cam)
{
	m_cubeRenderer.render(cam);
	m_chunkRenderer.render(cam);
	m_generalRenderer.render(cam);
	m_computeRenderer.render();
}

Renderer::~Renderer()
{
    //dtor
}
