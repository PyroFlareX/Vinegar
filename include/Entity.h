#pragma once

#include "Util/math.h"
#include <iostream>

struct Entity
{
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rot = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 origin = glm::vec3(0.0f, 0.0f, 0.0f);
	
	//AABB Collision Box
};

