#include "Coord.h"

Coord::Coord(int x, int y) : x(x), y(y) {

}

void Coord::setCoord(int x, int y) {
	this->x = x;
	this->y = y;
}

int Coord::getCoordX() {
	return this->x;
}

int Coord::getCoordY() {
	return this->y;
}
