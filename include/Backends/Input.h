#ifndef INPUT_H
#define INPUT_H


namespace Input
{
	struct Inputs
	{
		bool up;
		bool down;
		float LX;
		float LY;
		float RX;
		float RY;
		bool pause;
		bool accel;
	};

	Inputs getInput();
};

#endif // INPUT_H
