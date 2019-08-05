#pragma once

#include "../../Model.h"

#include <array>
#include <vector>
#include <SFML/Graphics.hpp>


class ChunkMesh
{
public:
	void addFace(	const std::array<float, 12>& blockFace, const std::array<float, 8>& texCoords,
					const sf::Vector3i& chunkPos, const sf::Vector3i& blockPos);

	void bufferMesh();

	const void deleteData()
	{
		m_model.deleteData();
	}
	Model& getModel()
	{
		return m_model;
	}
private:
	Model m_model;
	Mesh mesh;
	unsigned int numIndicies = 0;
	uint16_t faces = 0;
};
