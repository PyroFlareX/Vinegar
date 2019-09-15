#pragma once

#include "../Engine/Engine.h"
#include "Backends/Input.h"

class Player : public vn::Transform
{
public:
	Player();

	void getInput(Input::Inputs inputs);

	void jump();

	void update(float dt);

	~Player();
private:
	vn::vec3 velocity;

	bool isFlying;
};

