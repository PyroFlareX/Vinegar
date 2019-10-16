#include "World.h"

World::World()
{

}

void World::addStaticObject(vn::GameObject& obj)
{
	m_ground.emplace_back(obj);
}

void World::addObject(vn::GameObject& obj)
{
	m_Scene.emplace_back(obj);
}

void World::update(float dt)
{
	for (auto& obj : m_Scene)
	{
		if (obj.transform.pos.y <= 0.0f)
		{
			obj.transform.velocity.y = 0.0f;
		}
		obj.transform.translate(obj.transform, obj.transform.velocity * dt);
		//obj.transform.velocity -= obj.transform.velocity * dt;	//Unrealistic, all momentum terminates after 1 second

	}
}

void World::doCollision(float step)
{

}
