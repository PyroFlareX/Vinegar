#pragma once

#include "Chunk.h"
#include <unordered_map>
#include <SFML/System.hpp>

class World;

using ChunkMap = std::unordered_map<sf::Vector3i, Chunk>;

class ChunkManager
{
public:
	ChunkManager(World& world);

	void makeMesh(int x, int y, int z, const Camera& cam);

	void loadChunk(int x, int y, int z);
	void unloadChunk(int x, int y, int z);
	
	Chunk& getChunk(int x, int y, int z);


	~ChunkManager();
private:
	ChunkMap chunks;

	World* p_world;

	bool chunkExists(int x, int y, int z);
	bool chunkLoadedAt(int x, int y, int z);
};