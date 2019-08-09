#pragma once

#include <vector>

struct Mesh
{
	std::vector<float> vertices;
	std::vector<unsigned int> indicies;
	std::vector<float> texCoords;
};

struct renderInfo
{
	unsigned int VAO = 0;
	int indiciesCount = 0;
	inline void reset()
	{
		VAO = 0;
		indiciesCount = 0;
	}
};