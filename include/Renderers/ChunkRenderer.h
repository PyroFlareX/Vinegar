#pragma once

#include "../World/Chunk/ChunkMesh.h"
#include "../Camera.h"
#include "../Shaders/Shader.h"
#include "../Texture/Texture.h"

class ChunkRenderer
{
public:
	ChunkRenderer();

	void addChunk(ChunkMesh& mesh);
	void render(Camera& cam);

	~ChunkRenderer();
private:
	std::vector<const renderInfo*> m_queue;
	Shader m_shader;
	Texture tex;
};
