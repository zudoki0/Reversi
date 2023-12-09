#pragma once
#include <Board.h>
#include <Disk.h>
#include <ReversiValidMoveSearcher.h>
#include <Player.h>

enum GameOutcome {
	BlackWin,
	WhiteWin,
	Draw,
	Ongoing
};

class ReversiGameManager
{
private:
	Board& board;
	Disk*** map;
	int numOfRows;
	int numOfCols;
	Player currentPlayer;
	void flipFromLeftDiagonally(int x, int y, DiskColor color);
	void flipFromRightDiagonally(int x, int y, DiskColor color);
	void flipWithinRow(int x, int y, DiskColor color);
	void flipWithinColumn(int x, int y, DiskColor color);
	bool isBoardFull();
public:
	ReversiGameManager(Board& board);
	void makeMove(int x, int y, ReversiValidMoveSearcher& rules);
	Player getCurrentPlayer();
	void switchPlayerMove(ReversiValidMoveSearcher& rules);
	GameOutcome getWinner();
};

