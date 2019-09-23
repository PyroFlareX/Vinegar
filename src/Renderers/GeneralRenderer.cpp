#include "GeneralRenderer.h"

//#include "../../Engine/Registries/ResourceManager.h"

GeneralRenderer::GeneralRenderer()
{
	
	img.create(16, 16, vn::u8vec4(255.0f, 0.0f, 0.0f, 255.0f));
	//img.loadFromFile("res/container.jpg");
	//img = resources::TexManager.getSheet();
	//img.saveToFile("test.png");

	m_shader.load("res/Shaders/model.vs", "res/Shaders/model.fs");

	tex.loadFromImage(img);


	
	//m_generalModel.addData(vn::loadMeshFromObj("res/Models/Sword.obj"));
	//m_generalModel.addData(vn::loadMeshFromObj("res/Models/mythra.obj"));
	m_generalModel.addData(vn::loadMeshFromObj("res/Models/cube.obj"));
	//m_generalModel.addData(vn::loadMeshFromObj("res/Models/chalet.obj"));
}

void GeneralRenderer::addInstance(vn::Transform& entity)
{
	m_queue.push_back(entity);
}

void GeneralRenderer::render(Camera& cam)
{
	m_shader.use();
	m_generalModel.bindVAO();
	tex.bind();

	m_shader.setMat4("view", cam.getViewMatrix(cam));
	m_shader.setMat4("proj", cam.getProjMatrix());

	glDisable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for (auto& entity : m_queue)
	{
		m_shader.setMat4("model", makeModelMatrix(entity));

		glDrawElements(GL_TRIANGLES, m_generalModel.getNumIndicies(), GL_UNSIGNED_INT, nullptr);
	}
	m_queue.clear();
}

GeneralRenderer::~GeneralRenderer()
{

}
