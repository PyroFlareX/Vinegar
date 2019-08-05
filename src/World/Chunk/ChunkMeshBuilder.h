#pragma once

#include "Chunk.h"
#include "../../Util/ResourceManager.h"

class ChunkMeshBuilder
{
public:
	ChunkMeshBuilder(const Chunk& chunk, ChunkMesh& mesh) : p_chunk(&chunk), p_mesh(&mesh) {}

	void buildMesh();

private:
	void tryAddFaceToMesh(const std::array<GLfloat, 12>& blockFace, const std::string& texName, const sf::Vector3i& blockPosition, const sf::Vector3i& blockFacing);
	bool shouldMakeFace(const sf::Vector3i adjBlock);

	const Chunk* p_chunk;
	ChunkMesh* p_mesh;
};

struct AdjacentBlockPositions
{
	void update(int x, int y, int z)
	{
		up = { x,     y + 1,  z };
		down = { x,     y - 1,  z };
		left = { x - 1, y,      z };
		right = { x + 1, y,      z };
		front = { x,     y,      z + 1 };
		back = { x,     y,      z - 1 };
	}

	sf::Vector3i up;
	sf::Vector3i down;
	sf::Vector3i left;
	sf::Vector3i right;
	sf::Vector3i front;
	sf::Vector3i back;
};

const std::array<GLfloat, 12> frontFace
{
	0, 0, 1,
	1, 0, 1,
	1, 1, 1,
	0, 1, 1,
};

const std::array<GLfloat, 12> backFace
{
	1, 0, 0,
	0, 0, 0,
	0, 1, 0,
	1, 1, 0,
};

const std::array<GLfloat, 12> leftFace
{
	0, 0, 0,
	0, 0, 1,
	0, 1, 1,
	0, 1, 0,
};

const std::array<GLfloat, 12> rightFace
{
	1, 0, 1,
	1, 0, 0,
	1, 1, 0,
	1, 1, 1,
};

const std::array<GLfloat, 12> topFace
{
	0, 1, 1,
	1, 1, 1,
	1, 1, 0,
	0, 1, 0,
};

const std::array<GLfloat, 12> bottomFace
{
	0, 0, 0,
	1, 0, 0,
	1, 0, 1,
	0, 0, 1
};