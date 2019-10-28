#ifdef NX

#ifndef CONTEXT_H
#define CONTEXT_H

#include <EGL/egl.h>    // EGL library
#include <EGL/eglext.h> // EGL extensions
#include <glad/glad.h>  // glad library (OpenGL loader)
#include <switch.h>

constexpr int HEIGHT = 720;
constexpr int WIDTH = 1280;

class Context
{
    public:
        Context();


        void clear();
        void update();
        void draw();
		void close();
        bool isOpen();

        ~Context();
    protected:

    private:
		void initAPI(NWindow* win);

		EGLDisplay display;
		EGLContext context;
		EGLSurface surface;
};

#endif // CONTEXT_H

#endif // NX