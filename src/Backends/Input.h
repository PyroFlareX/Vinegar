#ifndef INPUT_H
#define INPUT_H


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
};

#endif // INPUT_H
