#ifndef CONTEXT_H
#define CONTEXT_H

// GLAD
#include "../../../../Engine/glad/glad/glad.h"
// GLFW
#include <GLFW/glfw3.h>

constexpr int HEIGHT = 720;
constexpr int WIDTH = 1280;

class Context
{
    public:
        Context();

        void clear();
        void update();
		void close();
        void initAPI();
        bool isOpen();

		GLFWwindow* getContext();

        ~Context();
    protected:

    private:
        GLFWwindow* context;
};

#endif // CONTEXT_H