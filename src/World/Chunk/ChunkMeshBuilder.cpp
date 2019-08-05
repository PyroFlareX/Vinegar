#include "ChunkMeshBuilder.h"

void ChunkMeshBuilder::buildMesh()
{
	static int num = 0;
	AdjacentBlockPositions directions;
	sf::Clock timer;
	for(int x = 0; x < CHUNK_SIZE; ++x)
	for(int y = 0; y < CHUNK_SIZE; ++y)
	for(int z = 0; z < CHUNK_SIZE; ++z)
	{
		sf::Vector3i position(x, y, z);
		
		auto block = p_chunk->getBlock(x, y, z);

		if (block == BlockId::AIR)
		{
			continue;
		}

		directions.update(x, y, z);

		tryAddFaceToMesh(bottomFace, block.getTextureName(Facing::DOWN), position, directions.down);
		tryAddFaceToMesh(topFace, block.getTextureName(Facing::UP), position, directions.up);

		tryAddFaceToMesh(frontFace, block.getTextureName(Facing::SOUTH), position, directions.front);
		tryAddFaceToMesh(backFace, block.getTextureName(Facing::NORTH), position, directions.back);

		tryAddFaceToMesh(rightFace, block.getTextureName(Facing::EAST), position, directions.right);
		tryAddFaceToMesh(leftFace, block.getTextureName(Facing::WEST), position, directions.left);
	}
	std::cout << "Built Mesh " << num++ << " in: " << timer.restart().asSeconds() << "\n";
}

void ChunkMeshBuilder::tryAddFaceToMesh(const std::array<GLfloat, 12>& blockFace,
										const std::string& texName, 
										const sf::Vector3i& blockPosition, 
										const sf::Vector3i& blockFacing)
{
	if (shouldMakeFace(blockFacing))
	{
		auto texCoords = resources::TexManager.getTexCoords(texName);

		p_mesh->addFace(blockFace, texCoords, p_chunk->getPos(), blockPosition);
	}
}

bool ChunkMeshBuilder::shouldMakeFace(const sf::Vector3i adjBlock)
{
	auto block = p_chunk->getBlock(adjBlock.x, adjBlock.y, adjBlock.z);
	
	if (block == BlockId::AIR)
	{
		return true;
	}
	else
	{
		return true;
	}
}
