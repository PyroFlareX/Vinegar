#include "Player.h"
#include <iostream>

Player::Player()
{
	pos = glm::vec3(0.0f, 0.0f, 1.0f);
	rot = glm::vec3(0.0f, 0.0f, 0.0f);
	velocity = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Player::getInput(Input::Inputs vInput)
{
	glm::vec3 change = glm::vec3(0.0f);
	float speed = 3.0f;

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
	rot.x += vInput.RY * 0.05f;
	rot.y += vInput.RX * 0.05f;
}

void Player::jump()
{
	velocity.y += 3;
}

void Player::update(float dt)
{
	//velocity.y -= 0.7f;

	pos += velocity * dt;
	velocity = glm::vec3(0.0f);

	//std::cout << pos.x << " " << pos.y << " " << pos.z << "\n";
	//std::cout << rot.x << " " << rot.y << " " << rot.z << "\n";
}

Player::~Player()
{

}
