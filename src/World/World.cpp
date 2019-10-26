#include "World.h"

World::World()
{
	//Initializing Bullet Physics Engine setup
	collisionConfiguration =	new btDefaultCollisionConfiguration();
	dispatcher =				new btCollisionDispatcher(collisionConfiguration);
	overlappingPairCache =		new btDbvtBroadphase();
	solver =					new btSequentialImpulseConstraintSolver;
	dynamicsWorld =				new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
	
	dynamicsWorld->setGravity(btVector3(0, -10, 0));


	// Create a few basic rigid bodies
/*
	{
		vn::GameObject obj;

		obj.shape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));
		obj.transform.pos = vn::vec3(0.0f, -56.0f, 0.0f);
		obj.phyTransform.setIdentity();
		
		obj.phyTrans;
		obj.transform.;

		obj.phyTransform.setOrigin(btVector3(0.0f, -56.0f, 0.0f));
		obj.body = new btRigidBody(obj.mass, obj.motionState, obj.shape,
			btVector3(obj.transform.velocity.x, obj.transform.velocity.y, obj.transform.velocity.z));
		obj.shape->calculateLocalInertia(obj.mass, )
	}*/
	//the ground is a cube of side 100 at position y = -56.
	//the sphere will hit it at y = -6, with center at -5
	{
		btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));

		collisionShapes.push_back(groundShape);

		btTransform groundTransform;
		groundTransform.setIdentity();
		groundTransform.setOrigin(btVector3(0, -56, 0));
		
		btScalar mass(0.);
		
		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		bool isDynamic = (mass != 0.f);
		
		btVector3 localInertia(0, 0, 0);
		if (isDynamic)
			groundShape->calculateLocalInertia(mass, localInertia);

		//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
		btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
		btRigidBody* body = new btRigidBody(rbInfo);
		
		//add the body to the dynamics world
		dynamicsWorld->addRigidBody(body);
	}
	/*
	{
		//create a dynamic rigidbody

		//btCollisionShape* colShape = new btBoxShape(btVector3(1,1,1));
		btCollisionShape* colShape = new btSphereShape(btScalar(1.));
		collisionShapes.push_back(colShape);

		/// Create Dynamic Objects
		btTransform startTransform;
		startTransform.setIdentity();
		
		btScalar mass(1.f);

		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		bool isDynamic = (mass != 0.f);

		btVector3 localInertia(0, 0, 0);
		if (isDynamic)
			colShape->calculateLocalInertia(mass, localInertia);

		startTransform.setOrigin(btVector3(2, 10, 0));

		//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
		btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);
		btRigidBody* body = new btRigidBody(rbInfo);

		dynamicsWorld->addRigidBody(body);
	}

	
	*/
}

void World::addObject(vn::GameObject& obj)
{
	obj.collider = new btSphereShape(1.0f);

	collisionShapes.push_back(obj.collider);

	/// Create Dynamic Objects
	vn::vec3 t(0.0f);

	t = obj.getCurrentTransform().pos;
	std::cout << "After \"addObject()\" function in World.cpp \n";

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(t.x, t.y, t.z));


	/// Rigidbody is dynamic if and only if mass is non zero, otherwise static
	bool isDynamic = (obj.mass != 0.f);
	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
	{
		obj.collider->calculateLocalInertia(obj.mass, localInertia);
	}

	obj.motionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(obj.mass, obj.motionState, obj.collider, localInertia);
	obj.rigidBody = new btRigidBody(rbInfo);

	dynamicsWorld->addRigidBody(obj.rigidBody);
}

void World::update(float dt)
{
	std::cout << "Start of World Update function\n";
	for (int i = 0; i < 150; i++)
	{
		dynamicsWorld->stepSimulation(1.f / 60.f, 10);

		//print positions of all objects
		for (int j = dynamicsWorld->getNumCollisionObjects() - 1; j >= 0; j--)
		{
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
			btRigidBody* body = btRigidBody::upcast(obj);
			
			btTransform trans;
			if (body && body->getMotionState())
			{
				body->getMotionState()->getWorldTransform(trans);
			}
			else
			{
				trans = obj->getWorldTransform();
			}
			//printf("world pos object %d = %f,%f,%f\n", j, float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));
		}
	}

}

World::~World()
{
	//cleanup in the reverse order of creation/initialization

	///-----cleanup_start-----

	//remove the rigidbodies from the dynamics world and delete them
	for (int i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
	{
		btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState())
		{
			delete body->getMotionState();
		}
		dynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}

	//delete collision shapes
	for (int j = 0; j < collisionShapes.size(); j++)
	{
		btCollisionShape* shape = collisionShapes[j];
		collisionShapes[j] = 0;
		delete shape;
	}

	//delete dynamics world
	delete dynamicsWorld;

	//delete solver
	delete solver;

	//delete broadphase
	delete overlappingPairCache;

	//delete dispatcher
	delete dispatcher;

	delete collisionConfiguration;

	//next line is optional: it will be cleared by the destructor when the array goes out of scope
	collisionShapes.clear();
}

