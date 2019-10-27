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
		Transform getCurrentTransform()
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
		//Out-dated Functions?
		/*void applyTransform(Transform& trans)
		{
			transform.pos += trans.pos;
			transform.rot += trans.rot;
			transform.scale = trans.scale;

			physics.phyTransform.setOrigin(physics.phyTransform.getOrigin() + btVector3(trans.pos.x, trans.pos.y, trans.pos.z));

			btQuaternion quat = physics.phyTransform.getRotation();
			vec3 r;
			quat.getEulerZYX(r.z, r.y, r.x);
			quat.setEuler(r.y + transform.pos.y, r.x + transform.pos.x, r.z + transform.pos.z);
			physics.phyTransform.setRotation(quat);

			physics.shape->setLocalScaling(btVector3(trans.scale.x, trans.scale.y, trans.scale.z));
		}
		void applyTransform(btTransform& trans)
		{
			transform;

			physics.phyTransform.setRotation(trans.getRotation());

			trans.getOrigin().getX();
			trans.getOrigin().getY();
			trans.getOrigin().getZ();
			//trans.getRotation().getEulerZYX
		}

		void setTransform(Transform& trans)
		{
			transform = trans;


			btQuaternion quat;
			vec3 r;
			quat.setEuler(transform.pos.y, transform.pos.x, transform.pos.z);
			physics.phyTransform.setRotation(quat);

			physics.phyTransform.setOrigin(btVector3(trans.pos.x, trans.pos.y, trans.pos.z));

			physics.shape->setLocalScaling(btVector3(trans.scale.x, trans.scale.y, trans.scale.z));
			physics.body->setAngularVelocity(btVector3(trans.angularMomentum.x, trans.angularMomentum.y, trans.angularMomentum.z));
			physics.body->setLinearVelocity(btVector3(trans.velocity.x, trans.velocity.y, trans.velocity.z));
		}
		void setTransform(btTransform& trans)
		{
			physics.phyTransform = trans;

			vec3 v;
			v = vec3(trans.getOrigin().x(), trans.getOrigin().y(), trans.getOrigin().z());
			transform.pos = v;

			trans.getRotation().getEulerZYX(v.x, v.y, v.z);
			transform.rot = v;
		}
		*/
	};
}