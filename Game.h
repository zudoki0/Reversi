#pragma once
#include <common.h>
#include <defs.h>

class Game
{
private:
	int width;
	int height;
	int** map;
	int move;
	void flip(int targetX, int targetY, int source);
	void flipWithinRow(int x, int y, int source);
	void flipWithinColumn(int x, int y, int source);
	void flipWithinDiagonal(int x, int y, int source);
	bool hasWithinDiagonal(int x, int y, int source);
	bool hasWithinRow(int x, int y, int source);
	bool hasWithinColumn(int x, int y, int source);
	bool isAdjacentToExisting(int x, int y, int source);
	bool isFull();
	bool isOnlyWhiteDisk();
	bool isOnlyBlackDisk();
	bool isWonByBlack();
public:
	Game(int width, int height);
	~Game();
	bool isWithinGame(int x, int y);
	bool isValidMove(int x, int y, int source);
	bool hasValidMove(int source);
	int** getMap();
	bool insertDisk(int x, int y, int source);
	int isWonBy();
	int getCurrentMove();
	bool** getValidMoves(int player);
	void renderMapOnConsole();
};

