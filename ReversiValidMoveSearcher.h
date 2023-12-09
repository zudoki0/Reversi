#pragma once
#include <Disk.h>
#include <Player.h>
#include <Board.h>
class ReversiValidMoveSearcher
{
private:
	Board& board;
	Disk*** map;
	int numOfRows;
	int numOfCols;
	bool** validOptionsMap;
	bool searchDiagonalTopLeft(int x, int y, Player player);
	bool searchDiagonalBottomLeft(int x, int y, Player player);
	bool searchDiagonalTopRight(int x, int y, Player player);
	bool searchDiagonalBottomRight(int x, int y, Player player);
	bool searchRowTop(int x, int y, Player player);
	bool searchRowBottom(int x, int y, Player player);
	bool searchColLeft(int x, int y, Player player);
	bool searchColRight(int x, int y, Player player);
	bool isAdjacentToExisting(int x, int y, Player player);
public:
	ReversiValidMoveSearcher(Board& board);
	~ReversiValidMoveSearcher();
	bool isValidMove(int x, int y, Player player);
	bool** getValidMovesMap(Player player);
	bool hasValidMove(Player player);
};

