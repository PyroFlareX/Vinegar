#ifdef NX

#include "../include/Context.h"

Context::Context()
{
    
    initAPI(nwindowGetDefault());
}

Context::~Context()
{
	close();
}

/*sf::RenderWindow* Context::getContext()
{
    return &context;
}*/

void Context::clear()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Context::update()
{
	eglSwapBuffers(display, surface);
}

void Context::draw()
{

}

void Context::close()
{
	if (display)
	{
		eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		if (context)
		{
			eglDestroyContext(display, context);
			context = nullptr;
		}
		if (surface)
		{
			eglDestroySurface(display, surface);
			surface = nullptr;
		}
		eglTerminate(display);
		display = nullptr;
	}
}

void Context::initAPI(NWindow* win)
{
	//Create Display
	display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

	//Initialize
	eglInitialize(display, nullptr, nullptr);

	if (eglBindAPI(EGL_OPENGL_API) == EGL_FALSE)
	{

	}

	//Config EGL
	EGLConfig config;
	EGLint numConfigs;

	const int framebufferAttributeList[] =
	{
		EGL_RENDERABLE_TYPE,	EGL_OPENGL_BIT,
		EGL_RED_SIZE,     8,
		EGL_GREEN_SIZE,   8,
		EGL_BLUE_SIZE,    8,
		EGL_ALPHA_SIZE,   8,
		EGL_DEPTH_SIZE,   24,
		EGL_STENCIL_SIZE, 8,
		EGL_NONE
	};
	eglChooseConfig(display, framebufferAttributeList, &config, 1, &numConfigs);

	//Create Window surface
	surface = eglCreateWindowSurface(display, config, win, nullptr);

	//Create Rendering Context
	const EGLint contextAttributeList[] =
	{
		EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR, EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR,
		EGL_CONTEXT_MAJOR_VERSION_KHR, 4,
		EGL_CONTEXT_MINOR_VERSION_KHR, 3,
		EGL_NONE
	};
	context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttributeList);

	//Connect context to the surface
	eglMakeCurrent(display, surface, surface, context);


	gladLoadGL();
	glViewport(0, 0, WIDTH, HEIGHT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

bool Context::isOpen()
{
	bool close = false;
	hidScanInput();
	u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
	if (kDown & KEY_PLUS)
	{
		close = true;
	}
	return close;
}

#endif // NX