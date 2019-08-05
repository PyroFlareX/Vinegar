#include "SFMLRenderer.h"


SFMLRenderer::SFMLRenderer()
{

}

void SFMLRenderer::addToQueue(const sf::Drawable& item)
{
	m_queue.push_back(&item);
}

void SFMLRenderer::render(sf::RenderWindow* window)
{
	if (m_queue.empty())
	{
		return;
	}

	window->pushGLStates();

	for (const auto& draw : m_queue)
	{
		window->draw(*draw);
	}
	m_queue.clear();
	window->popGLStates();
}

SFMLRenderer::~SFMLRenderer()
{

}
