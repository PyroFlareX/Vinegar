#include "ChunkMesh.h"

#include "Chunk.h"

void ChunkMesh::addFace(const std::array<float, 12>& blockFace, const std::array<float, 8>& texCoords, const sf::Vector3i & chunkPos, const sf::Vector3i & blockPos)
{
	++faces;
	auto& verticies = mesh.vertices;
	auto& textureCoords = mesh.texCoords;
	auto& indicies = mesh.indicies;

	textureCoords.insert(textureCoords.end(), texCoords.begin(), texCoords.end());

	for (int i = 0, index = 0; i < 4; ++i)
	{
		verticies.push_back(blockFace[index++] + chunkPos.x * CHUNK_SIZE + blockPos.x);
		verticies.push_back(blockFace[index++] + chunkPos.y * CHUNK_SIZE + blockPos.y);
		verticies.push_back(blockFace[index++] + chunkPos.z * CHUNK_SIZE + blockPos.z);
	}

	indicies.insert(indicies.end(),
	{
		numIndicies,
		numIndicies + 1,
		numIndicies + 2,

		numIndicies + 2,
		numIndicies + 3,
		numIndicies
	});
	numIndicies += 4;
}

void ChunkMesh::bufferMesh()
{
	m_model.addData(mesh);
	
	mesh.vertices.clear();
	mesh.texCoords.clear();
	mesh.indicies.clear();

	mesh.vertices.shrink_to_fit();
	mesh.indicies.shrink_to_fit();
	mesh.texCoords.shrink_to_fit();

	numIndicies = 0;
}
