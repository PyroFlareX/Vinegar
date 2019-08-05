#include "Renderer.h"

Renderer::Renderer()
{
    //ctor
}

void Renderer::drawSFML(const sf::Drawable& drawable)
{
	m_SFMLRenderer.addToQueue(drawable);
}

void Renderer::drawCube(Entity& entity)
{
	m_cubeRenderer.addCube(entity);
}

void Renderer::doCompute()
{
//	m_computeRenderer.
}

void Renderer::drawChunk(ChunkMesh& mesh)
{
	m_chunkRenderer.addChunk(mesh);
}

void Renderer::render(Camera& cam, sf::RenderWindow* window)
{
	m_cubeRenderer.render(cam);
	m_chunkRenderer.render(cam);
//	m_SFMLRenderer.render(window);
//	m_computeRenderer.render();
}

Renderer::~Renderer()
{
    //dtor
}
