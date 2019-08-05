#pragma once

//#include <SFML/System.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera;
class Entity;

/*inline sf::Vector2f lerp(sf::Vector2f current, sf::Vector2f target, float gradient)
{
	return sf::Vector2f((target - current) * gradient + current);
}*/

const glm::mat4 makeViewMatrix(const Camera& camera);

const glm::mat4 makeModelMatrix(const Entity& entity);

const glm::mat4 makeProjectionMatrix(float fov, int x, int y);

/*namespace std
{
	template<>
	struct hash<sf::Vector3i>
	{
		size_t operator()(const sf::Vector3i& vect) const noexcept
		{
			std::hash<decltype(vect.x)> hasher;

			auto hash1 = hasher(vect.x);
			auto hash2 = hasher(vect.y);
			auto hash3 = hasher(vect.z);

			return std::hash<decltype(vect.x)>{}((hash1 ^ (hash2 << hash3) ^ hash3));
		}
	};
}*/

namespace std
{
	template<>
	struct hash<glm::vec3>
	{
		size_t operator()(const glm::vec3& vect) const noexcept
		{
			std::hash<decltype(vect.x)> hasher;

			auto hash1 = hasher(vect.x);
			auto hash2 = hasher(vect.y);
			auto hash3 = hasher(vect.z);

			return std::hash<decltype(vect.x)>{}((hash1 ^ (hash2 << hash3) ^ hash3));
		}
	};
}
