#include "Context.h"
#include <iostream>
#include "glad/glad/glad.h"

Context::Context()
{
    sf::ContextSettings settings;
	settings.majorVersion = 4;
	settings.minorVersion = 5;
	settings.depthBits = 24;
    context.create(sf::VideoMode(WIDTH, HEIGHT), "TechnoMagica", sf::Style::Default, settings);
    //context.setFramerateLimit(60);
	context.setMouseCursorGrabbed(true);
	context.setMouseCursorVisible(false);
    initAPI();
}

Context::~Context()
{
    //context.close();
}

sf::RenderWindow* Context::getContext()
{
    return &context;
}

void Context::clear()
{
    //context.clear(sf::Color::Black);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Context::update()
{
    context.display();
}

void Context::draw()
{

}

void Context::close()
{
	context.close();
}

void Context::initAPI()
{
	gladLoadGL();
	glViewport(0, 0, WIDTH, HEIGHT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

bool Context::isOpen()
{
    return context.isOpen();
}
