#pragma once

#include "../Model.h"
#include <SFML/Graphics.hpp>

class SFMLRenderer
{
public:
	SFMLRenderer();

	void addToQueue(const sf::Drawable& item);
	void render(sf::RenderWindow* window);

	~SFMLRenderer();
private:
	std::vector<const sf::Drawable*> m_queue;
};

