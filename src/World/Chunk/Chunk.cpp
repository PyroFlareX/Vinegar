#include "Chunk.h"

#include "../../Renderers/Renderer.h"
#include "ChunkMeshBuilder.h"

#include "../World.h"

bool inRange(const int n)
{
	return (n >= 0 && n <= 15);
}

constexpr int toIndex(int x, int y, int z)
{
	return y * CHUNK_AREA + z * CHUNK_SIZE + x;
}

Chunk::Chunk(World* p_world, int x, int y, int z)	: p_world(p_world), pos(x, y, z)
{
	for(int i = 0; i < CHUNK_VOLUME; ++i)
	{
		m_blocks[i] = Block(BlockId::DIRT);//resources::BlockDatabase.getBlock("dirt");
	}
}

Block& Chunk::getBlock(int x, int y, int z) const
{
	if (!(inRange(x) && inRange(y) && inRange(z)))
	{
		//return p_world->getBlock(x, y, z);
		return Block(BlockId::AIR);
		/*x = getPos().x % 16;
		y = getPos().y % 16;
		z = getPos().z % 16;*/
	}

	return Block(m_blocks.at(toIndex(x, y, z)));
}

const sf::Vector3i Chunk::getPos() const
{
	return pos;
}

void Chunk::makeMesh()
{
	ChunkMeshBuilder(*this, mesh).buildMesh();
	mesh.bufferMesh();
	hasMesh = true;
}

void Chunk::deleteMesh()
{
	mesh.deleteData();
}

void Chunk::renderChunk(Renderer& render, const Camera& cam)
{
	if (hasMesh)
	{
		render.drawChunk(mesh);
		std::cout << "Test\n";
	}
	else
	{
		std::cout << "Test2\n";
		makeMesh();
		render.drawChunk(mesh);
	}
}

Chunk::~Chunk()
{

}
