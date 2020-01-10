#pragma once

#include "../../Engine/Engine.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

class World
{
public:
	World();
	
	void addObject(vn::GameObject& obj);

	void update(float dt);

	World(const World& world) = delete;

	~World();
private:

	btDefaultCollisionConfiguration*		collisionConfiguration;
	btCollisionDispatcher*					dispatcher;
	btBroadphaseInterface*					overlappingPairCache;;
	btSequentialImpulseConstraintSolver*	solver;
	btDiscreteDynamicsWorld*				dynamicsWorld;

	//keep track of the shapes, we release memory at exit.
	//make sure to re-use collision shapes among rigid bodies whenever possible!
	btAlignedObjectArray<btCollisionShape*> collisionShapes;
};