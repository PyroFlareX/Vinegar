#pragma once

#include "Types.h"

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <glm/gtx/euler_angles.hpp>
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

				//Position
				trans.pos = vec3(t.getOrigin().getX(), t.getOrigin().getY(), t.getOrigin().getZ());

				//Rotation (quaternion to Euler Angles)
				btQuaternion quat = t.getRotation();
				glm::quat q(quat.getW(), -quat.getX(), -quat.getY(), -quat.getZ());
				trans.rot = glm::eulerAngles(q);
				trans.rot = vec3(-trans.rot.x, -trans.rot.y, -trans.rot.z);
				trans.rot = glm::degrees(trans.rot);

				//Scale
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