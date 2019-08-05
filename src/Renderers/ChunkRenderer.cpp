#include "ChunkRenderer.h"
#include "../Util/ResourceManager.h"

ChunkRenderer::ChunkRenderer()
{
	tex.loadFromImage(resources::TexManager.getSheet());
	m_shader.load("res/Shaders/ChunkVert.glsl", "res/Shaders/ChunkFrag.glsl");
}

void ChunkRenderer::addChunk(ChunkMesh& mesh)
{
	m_queue.push_back(&mesh.getModel().getInfo());
}

void ChunkRenderer::render(Camera& cam)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	m_shader.use();
	tex.bind();


	m_shader.setMat4("view", cam.getViewMatrix(cam));
	m_shader.setMat4("proj", cam.getProjMatrix());

	glEnable(GL_CULL_FACE);

	for (auto& mesh : m_queue)
	{
		glBindVertexArray(mesh->VAO);

		glDrawElements(GL_TRIANGLES, mesh->indiciesCount, GL_UNSIGNED_INT, nullptr);
	}
	m_queue.clear();
}

ChunkRenderer::~ChunkRenderer()
{

}
