//#ifdef _PC

#include "GLContext.h"
#include <iostream>

Context::Context()
{
	// Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    context = glfwCreateWindow(WIDTH, HEIGHT, "Vinegar", nullptr, nullptr);
    glfwMakeContextCurrent(context);

    
    initAPI();
}

Context::~Context()
{
    close();
}

void Context::clear()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Context::update()
{
	glfwSwapBuffers(context);
    glfwPollEvents();
}

void Context::close()
{
	glfwTerminate();
}

void Context::initAPI()
{
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
    }
	glViewport(0, 0, WIDTH, HEIGHT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

bool Context::isOpen()
{
    return !glfwWindowShouldClose(context);
}

///#endif // _PC