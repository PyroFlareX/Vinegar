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

		//Physics
		btCollisionShape* shape;
		btRigidBody* body;
		btMotionState* motionState;
		btScalar mass = 1.0f;
		
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
		}
		void applyTransform(btTransform& trans)
		{
			transform;

			phyTransform.setRotation(trans.getRotation());

			trans.getOrigin().getX();
			trans.getOrigin().getY();
			trans.getOrigin().getZ();
			//trans.getRotation().getEulerZYX
		}

		void setTransform(Transform& trans)
		{
			transform.pos = trans.pos;
			transform.rot = trans.rot;
			transform.scale = trans.scale;
		}
		void setTransform(btTransform& trans);

		virtual void update()
		{

		};


		virtual ~GameObject() = default;
	private:

		Transform transform;
		btTransform phyTransform;
	};

}