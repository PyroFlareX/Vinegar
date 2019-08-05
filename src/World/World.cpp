#include "World.h"



World::World(const Camera& cam, Player& player)	:	m_chunkManager(*this)
{
	//loadThreads.emplace_back(std::thread(loadChunks, cam));
	loadChunks(cam);
}

Block& World::getBlock(int x, int y, int z)
{
	auto block = m_chunkManager.getChunk(x / 16, y / 16, z / 16).getBlock(x % 16, y % 16, z % 16);
	return block;
}

void World::update()
{

}

void World::renderWorld(const Camera& cam, Renderer& renderer)
{
	for (int x = 0; x < BOUNDS; ++x)
		for (int y = 0; y < BOUNDS; ++y)
			for (int z = 0; z < BOUNDS; ++z)
			{
				m_chunkManager.getChunk(x, y, z).renderChunk(renderer, cam);
			}
}

World::~World()
{
    //dtor
}

void World::loadChunks(const Camera& cam)
{
	while (isRunning)
	{
		bool hasMesh = false;
		glm::vec2 camXZ(cam.pos.x, cam.pos.z);
		//m_chunkManager.loadChunk()
		for(int i = -BOUNDS; i < BOUNDS; ++i)
			for(int j = -BOUNDS; j < BOUNDS; j++)
	}
	for (int x = 0; x < BOUNDS; ++x)
		for (int y = 0; y < BOUNDS; ++y)
			for (int z = 0; z < BOUNDS; ++z)
			{
				std::cout << "Chunk: " << x << " " << y << " " << z << "\n";
				m_chunkManager.loadChunk(x, y, z);
			}
	return;
}
