#include "../../../include/Backends/Input.h"

#ifdef _WIN32

#include <SFML/Graphics.hpp>
#include <iostream>

Input::Inputs Input::getInput()
{
	static auto lastMousePosition = sf::Mouse::getPosition();

	Input::Inputs input = { false, false, 0, 0, 0, 0, false, false };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		input.LY++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		input.LY--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		input.LX--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		input.LX++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		input.up = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		input.down = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		input.pause = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		input.accel = true;
	}

	auto offset = sf::Mouse::getPosition() - lastMousePosition;
	sf::Mouse::setPosition(lastMousePosition);
	lastMousePosition = sf::Mouse::getPosition();

	input.RY += offset.y;// *0.05f;
	input.RX += offset.x;// * 0.05f;

	

	return input;
}

#endif // WIN32

