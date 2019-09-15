#ifndef INPUT_H
#define INPUT_H

#include "../../Engine/glad/glad/glad.h"
#include <GLFW/glfw3.h>

namespace Input
{
	struct Inputs
	{
		bool up;
		bool down;
		int LX;
		int LY;
		int RX;
		int RY;
		bool pause;
		bool accel;
	};

	Inputs getInput();

	extern GLFWwindow* window;
};

#endif // INPUT_H
