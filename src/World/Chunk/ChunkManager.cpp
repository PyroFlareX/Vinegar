#include "ChunkManager.h"

#include "../World.h"

ChunkManager::ChunkManager(World& world)	: p_world(&world)
{
	
}

void ChunkManager::makeMesh(int x, int y, int z, const Camera& cam)
{

}

void ChunkManager::loadChunk(int x, int y, int z)
{
	getChunk(x, y, z);
}

void ChunkManager::unloadChunk(int x, int y, int z)
{
	//@TODO	save to file
	if (chunkExists(x, y, z))
	{
		chunks.erase(sf::Vector3i(x, y, z));
	}
}

Chunk& ChunkManager::getChunk(int x, int y, int z)
{
	if (!chunkExists(x, y, z))
	{
		Chunk chunk(p_world, x, y, z);
		chunks.emplace(sf::Vector3i(x, y, z), std::move(chunk));
	}

	return chunks[sf::Vector3i(x, y, z)];
}

ChunkManager::~ChunkManager()
{

}

bool ChunkManager::chunkExists(int x, int y, int z)
{
	return (chunks.find(sf::Vector3i(x, y, z)) != chunks.end());
}

bool ChunkManager::chunkLoadedAt(int x, int y, int z)
{
	if (!chunkExists(x, y, z))
		return false;

	return false;// chunks.at(sf::Vector3i(x, y, z)).hasLoaded();
}
