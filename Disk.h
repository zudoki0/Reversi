#pragma once

enum DiskColor {
	WHITE,
	BLACK
};

class Disk
{
protected:
	int posX, posY;
	DiskColor color;
public:
	Disk();
	int getPosX();
	int getPosY();
	void setPosX(int x);
	void setPosY(int y);
	DiskColor getColor();
	void setColor(DiskColor color);
	virtual void flip();
};