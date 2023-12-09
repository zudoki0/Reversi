#include "BlackDisk.h"

BlackDisk::BlackDisk(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	this->color = BLACK;
}

void BlackDisk::flip()
{
	if (this->color == WHITE) this->color = BLACK;
	else this->color = WHITE;
}
