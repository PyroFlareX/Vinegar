#pragma once

#include "Types/Types.h"
#include "Util/UtilFunctions.h"
#include "Resources/Mesh.h"
#include "Util/Loaders.h"
#include "Resources/Texture.h"
#include "Resources/Timer.h"
#include "Resources/Framebuffer.h"

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

#include "Util/VRUtils.h"

class Model;

namespace vn
{
	typedef struct
	{
		btCollisionShape*	shape;
		btRigidBody*		body;
		btMotionState*		motionState;
		btScalar			mass = 1.0f;
		btTransform			phyTransform;
	} PhysicsObject;

	class GameObject
	{
	public:
		GameObject()
		{

		};

		GameObject(Transform& trans) : transform(trans)
		{

		};

		//Internal
		
		Model m_model;
		
		//Audio

		//Functions
		virtual void init()
		{

		};

		void applyTransform(Transform& trans)
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

		virtual void update()
		{

		};


		virtual ~GameObject() = default;
	private:
		Transform transform;
		
		//Physics
		PhysicsObject physics;
	};

}