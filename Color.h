#pragma once
#include <common.h>

class Color
{
private:
	Uint8 Red;
	Uint8 Green;
	Uint8 Blue;
	Uint8 Alpha;
public:
	Color(Uint8 Red, Uint8 Green, Uint8 Blue, Uint8 Alpha);
	Color();
	void setRed(Uint8 amount);
	void setGreen(Uint8 amount);
	void setBlue(Uint8 amount);
	void setAlpha(Uint8 amount);
	Uint8 getRed();
	Uint8 getGreen();
	Uint8 getBlue();
	Uint8 getAlpha();
};

