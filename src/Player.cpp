#include "../include/Player.h"


Player::Player()
{
	pos = glm::vec3(0.0f, 32.0f, 1.0f);
	rot = glm::vec3(0.0f, 0.0f, 0.0f);
	velocity = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Player::getInput(Input::Inputs vInput)
{
	glm::vec3 change = glm::vec3(0.0f);
	float speed = 1.0f;

	change.x += glm::cos(glm::radians(rot.y)) * speed * vInput.LX;
	change.z += glm::sin(glm::radians(rot.y)) * speed * vInput.LX;

	if (vInput.up)
	{
		jump();
	}
	if (vInput.down)
	{
		velocity.y--;
	}

	//Backwards
	if (vInput.LY < 0)
	{
		change.x += -glm::cos(glm::radians(rot.y + 90)) * speed * vInput.LY;
		change.z += -glm::sin(glm::radians(rot.y + 90)) * speed * vInput.LY;
	}

	//Movement
	if (vInput.accel)
	{
		speed *= 3.0f;
	}

	//Forward
	if (vInput.LY > 0)
	{
		change.x += -glm::cos(glm::radians(rot.y + 90)) * speed * vInput.LY;
		change.z += -glm::sin(glm::radians(rot.y + 90)) * speed * vInput.LY;
	}

	velocity += change;
	
	//Rotation
	rot.x -= (float)vInput.RY * 0.0005f;
	rot.y += (float)vInput.RX * 0.0005f;
}

void Player::jump()
{
	velocity.y++;
}

void Player::update(float dt)
{
	//static auto lastMousePosition = sf::Mouse::getPosition(*window);
	//auto offset = sf::Mouse::getPosition() - lastMousePosition;

	//rot.x += (float)offset.y * 0.05f;
	//rot.y += (float)offset.x * 0.05f;


	//velocity.y -= 0.7f;

	pos += velocity * dt;
	velocity = glm::vec3(0.0f);


	//auto cx = static_cast<int>(window->getSize().x / 2);
	//auto cy = static_cast<int>(window->getSize().y / 2);

	//sf::Mouse::setPosition({ cx, cy }, *window);

	//lastMousePosition = sf::Mouse::getPosition();

	//std::cout << pos.x << " " << pos.y << " " << pos.z << "\n";
}

Player::~Player()
{

}
