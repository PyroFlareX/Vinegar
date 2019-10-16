#pragma once

#include "../../Engine/Engine.h"

class World
{
public:
	World();

	void addStaticObject(vn::GameObject& obj);
	void addObject(vn::GameObject& obj);

	void update(float dt);

	World(const World& world) = delete;
	~World() = default;
private:
	void doCollision(float step);

	std::vector<vn::GameObject> m_Scene;
	std::vector<vn::GameObject> m_ground;
};