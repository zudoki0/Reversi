#include "WhiteDisk.h"

WhiteDisk::WhiteDisk(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	this->color = WHITE;
}

void WhiteDisk::flip()
{
	if (this->color == WHITE) this->color = BLACK;
	else this->color = WHITE;
}
