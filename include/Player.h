#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Backends/Input.h"

class Player : public Entity
{
public:
	Player();

	void getInput(Input::Inputs inputs);

	void jump();

	void update(float dt);

	~Player();
private:
	glm::vec3 velocity;

	bool isFlying;
};

