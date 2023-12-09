#pragma once
#include <Board.h>
#include <Player.h>
#include <ReversiValidMoveSearcher.h>

class ReversiRules
{
private:
	Disk*** map;
	int numOfRows;
	int numOfCols;
	bool isOnlyBlackDisks();
	bool isOnlyWhiteDisks();
	bool isFull();
	int countBlackDisks();
	int countWhiteDisks();
public:
	ReversiRules(Board& board);
	~ReversiRules();
	bool isGameOver();
	bool checkPlayerWon(Player player);
};

