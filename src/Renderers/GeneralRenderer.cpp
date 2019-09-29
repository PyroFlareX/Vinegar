#include "GeneralRenderer.h"

//#include "../../Engine/Registries/ResourceManager.h"

GeneralRenderer::GeneralRenderer()
{
	
	//img.create(16, 16, vn::u8vec4(255.0f, 0.0f, 0.0f, 255.0f));
	//img.loadFromFile("res/container.jpg");
	img.loadFromFile("res/Textures/fbi.png");
	//img = resources::TexManager.getSheet();
	//img.saveToFile("test.png");

	m_shader.load("res/Shaders/model.vs", "res/Shaders/model.fs");
	m_lampshader.load("res/Shaders/testing.vs", "res/Shaders/testing.fs");

	tex.loadFromImage(img);
	
	//m_generalModel.addData(vn::loadMeshFromObj("res/Models/Sword.obj"));
	//m_generalModel.addData(vn::loadMeshFromObj("res/Models/mythra.obj"));
	//m_generalModel.addData(vn::loadMeshFromObj("res/Models/cube.obj"));
	m_generalModel.addData(vn::loadMeshFromObj("res/Models/sphere.obj"));
	//m_generalModel.addData(vn::loadMeshFromObj("res/Models/chalet.obj"));

	m_lampModel.addData(vn::loadMeshFromObj("res/Models/cube.obj"));
}

void GeneralRenderer::addInstance(vn::Transform& entity)
{
	m_queue.push_back(entity);
}

void GeneralRenderer::render(Camera& cam)
{
	vn::vec3 lightpos(5.0f, 0.0f, -1.0f);

	m_shader.use();
	m_generalModel.bindVAO();
	tex.bind();

	m_shader.setMat4("view", cam.getViewMatrix(cam));
	m_shader.setMat4("proj", cam.getProjMatrix());
	m_shader.setVec3("lightsrc", lightpos);

	glEnable(GL_CULL_FACE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for (auto& entity : m_queue)
	{
		m_shader.setMat4("model", vn::makeModelMatrix(entity));
		m_shader.setMat4("normmat", vn::makeNormalMatrix(entity));
		
		glDrawElements(GL_TRIANGLES, m_generalModel.getNumIndicies(), GL_UNSIGNED_INT, nullptr);
	}
	m_queue.clear();

	vn::Transform trans;
	trans.rescale(trans, vn::vec3(0.5f, 0.5f, 0.5f));
	trans.translate(trans, lightpos);
	m_lampshader.use();
	m_lampModel.bindVAO();
	m_lampshader.setMat4("view", cam.getViewMatrix(cam));
	m_lampshader.setMat4("proj", cam.getProjMatrix());
	m_lampshader.setMat4("model", makeModelMatrix(trans));
	glDrawElements(GL_TRIANGLES, m_lampModel.getNumIndicies(), GL_UNSIGNED_INT, nullptr);
}

GeneralRenderer::~GeneralRenderer()
{

}
