#include "Board.h"

Board::Board(int numOfRows, int numOfCols): numOfRows(numOfRows), numOfCols(numOfCols)
{
	map = new Disk**[numOfRows];
	for (int i = 0; i < numOfRows; i++) {
		map[i] = new Disk * [numOfCols];
	}
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfCols; j++) {
			map[i][j] = nullptr;
		}
	}
}

void Board::insertWhiteDisk(int x, int y)
{
	if (!isEmptyCell(x, y)) {
		return;
	}
	map[x][y] = new WhiteDisk(x, y);
}

void Board::insertBlackDisk(int x, int y)
{
	if (!isEmptyCell(x, y)) {
		return;
	}
	map[x][y] = new BlackDisk(x, y);
}

void Board::flipDisk(int x, int y)
{
	if (!isEmptyCell(x, y)) {
		return;
	}
	map[x][y]->flip();
}

Disk*** Board::getMap()
{
	return map;
}

int Board::getNumOfRows()
{
	return this->numOfRows;
}

int Board::getNumOfCols()
{
	return this->numOfCols;
}

int Board::countWhiteDisks()
{
	int counter = 0;
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfCols; j++) {
			if (map[i][j] != nullptr && map[i][j]->getColor() == WHITE) {
				counter++;
			}
		}
	}
	return counter;
}

int Board::countBlackDisks()
{
	int counter = 0;
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfCols; j++) {
			if (map[i][j] != nullptr && map[i][j]->getColor() == BLACK) {
				counter++;
			}
		}
	}
	return counter;
}

bool Board::isOnlyWhiteDisks()
{
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfCols; j++) {
			if (map[i][j] != nullptr && map[i][j]->getColor() == BLACK) {
				return false;
			}
		}
	}
	return true;
}

bool Board::isOnlyBlackDisks()
{
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfCols; j++) {
			if (map[i][j] != nullptr && map[i][j]->getColor() == WHITE) {
				return false;
			}
		}
	}
	return true;
}

bool Board::isFull()
{
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfCols; j++) {
			if (map[i][j] == nullptr) {
				return false;
			}
		}
	}
	return true;
}

bool Board::isWithinMap(int x, int y)
{
	return x >= 0 && y >= 0 && x < numOfRows && y <= numOfCols;
}

bool Board::isEmptyCell(int x, int y)
{
	if (isWithinMap(x, y)) {
		return map[x][y] == nullptr;
	}
	return false;
}

Board::~Board()
{
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfCols; j++) {
			delete map[i][j];
		}
	}
	for (int i = 0; i < numOfRows; i++) {
		delete map[i];
	}
	delete map;
}

