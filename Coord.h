#pragma once
class Coord
{
private:
	int x, y;
public:
	Coord(int x, int y);
	void setCoord(int x, int y);
	int getCoordX();
	int getCoordY();
};

