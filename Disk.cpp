#include "Disk.h"

Disk::Disk() {
	posX = 0;
	posY = 0;
	color = BLACK;
}

int Disk::getPosX()
{
	return this->posX;
}

int Disk::getPosY()
{
	return this->posY;
}

void Disk::setPosX(int x)
{
	this->posX = x;
}

void Disk::setPosY(int y)
{
	this->posY = y;
}

DiskColor Disk::getColor()
{
	return this->color;
}

void Disk::setColor(DiskColor color)
{
	this->color = color;
}

void Disk::flip()
{
	if (this->color == WHITE) this->color = BLACK;
	else this->color = WHITE;
}
