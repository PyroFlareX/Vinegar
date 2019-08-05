#include "../../../include/Backends/Input.h"

#ifdef _WIN32

#include <SFML/Graphics.hpp>

Input::Inputs Input::getInput()
{
	static auto lastMousePosition = sf::Mouse::getPosition();

	Input::Inputs input = { false, false, 0.0f, 0.0f, 0.0f, 0.0f, false, false };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		input.LY = 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		input.LY = -1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		input.LX = -1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		input.LX = 1.0f;
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

	input.RY += (float)offset.y * 0.05f;
	input.RX += (float)offset.x * 0.05f;

	//auto cx = static_cast<int>(window->getSize().x / 2);
	//auto cy = static_cast<int>(window->getSize().y / 2);

	//sf::Mouse::setPosition({ cx, cy }, *window);

	//lastMousePosition = sf::Mouse::getPosition();


	return input;
}

#endif // WIN32

