#pragma once
#include <Color.h>

enum DiskType {
	WHITE,
	BLACK
};

class Disk
{
private:
	int posX, posY;
	Color color;
	DiskType type;
	SDL_Renderer*& renderer;
	int size;
public:
	Disk(SDL_Renderer*& renderer, int posX, int posY, DiskType type, int size);
	void draw(const int containerSize);
	void drawOutline(const int containerSize);
	bool operator<(const Disk& other) const;
	bool operator==(const Disk& other) const;
	void setColor(Color color);
};

