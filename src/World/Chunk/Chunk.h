#pragma once


#include "../Block/Block.h"
#include "ChunkMesh.h"
#include "../../Camera.h"

class Renderer;
class World;

constexpr int CHUNK_SIZE = 16;
constexpr int CHUNK_AREA = CHUNK_SIZE * CHUNK_SIZE;
constexpr int CHUNK_VOLUME = CHUNK_AREA * CHUNK_SIZE;

class Chunk
{
public:
	Chunk() = default;
	Chunk(World* p_world, int x, int y, int z);

	Block& getBlock(int x, int y, int z) const;
	const sf::Vector3i getPos() const;

	void makeMesh();
	void deleteMesh();

	void renderChunk(Renderer& render, const Camera& cam);

	~Chunk();
private:
	std::array<Block, CHUNK_VOLUME> m_blocks;

	bool hasMesh = false;
	ChunkMesh mesh;
	World* p_world;
	sf::Vector3i pos;
};