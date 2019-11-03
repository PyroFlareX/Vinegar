#pragma once

#include "Types.h"

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

#include <iostream>

namespace vn
{	
	class GameObject
	{
	public:
		GameObject(Transform& trans, btCollisionShape* colShape) : transform(trans)
		{
			this->collider = colShape;

			hasTransform = true;
			mass = 1.0f;
			btQuaternion quat(transform.rot.y, transform.rot.x, transform.rot.z);
			btVector3 pos(transform.pos.x, transform.pos.y, transform.pos.z);
			motionState = new btDefaultMotionState(btTransform(quat, pos));

			init();
		};


		virtual void init()
		{
			
		};

		virtual void update()
		{

		};

		// @Brief Returns the current Transform (internal engine) of the oject so it may be used in graphics
		Transform& getCurrentTransform()
		{
			if (!hasTransform)
			{
				Transform trans;
				btTransform t;
				motionState->getWorldTransform(t);
				trans.pos = vec3(t.getOrigin().getX(), t.getOrigin().getY(), t.getOrigin().getZ());
				btQuaternion quat = t.getRotation();
				quat.getEulerZYX(trans.rot.z, trans.rot.y, trans.rot.x);
				trans.scale = vec3(collider->getLocalScaling().getX(), collider->getLocalScaling().getY(), collider->getLocalScaling().getZ());
				transform = trans;
			}

			hasTransform = false;
			return transform;
		}



		btMotionState*		motionState;
		btCollisionShape*	collider;
		btRigidBody*		rigidBody;
		float				mass;

		//Model m_model;

		virtual ~GameObject() = default;
	private:

		bool hasTransform = false;

		Transform transform;
	};
}