#include "ReversiGameManager.h"

void ReversiGameManager::flipFromLeftDiagonally(int x, int y, DiskColor color)
{
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
		if (board.isEmptyCell(i, j)) break;
		if (map[i][j]->getColor() == color) {
			for (int k = i, l = j; k < x && l < y; k++, l++) {
				map[k][l]->setColor(color);
			}
			break;
		}
	}
	for (int i = x + 1, j = y - 1; i < numOfRows && j >= 0; i++, j--) {
		if (board.isEmptyCell(i, j)) break;
		if (map[i][j]->getColor() == color) {
			for (int k = i, l = j; k > x && l < y; k--, l++) {
				map[k][l]->setColor(color);
			}
			break;
		}
	}
}

void ReversiGameManager::flipFromRightDiagonally(int x, int y, DiskColor color)
{
	for (int i = x + 1, j = y + 1; i < numOfRows && j < numOfCols; i++, j++) {
		if (board.isEmptyCell(i, j)) break;
		if (map[i][j]->getColor() == color) {
			for (int k = i, l = j; k > x && l > y; k--, l--) {
				map[k][l]->setColor(color);
			}
			break;
		}
	}
	for (int i = x - 1, j = y + 1; i >= 0 && j < numOfCols; i--, j++) {
		if (board.isEmptyCell(i, j)) break;
		if (map[i][j]->getColor() == color) {
			for (int k = i, l = j; k < x && l > y; k++, l--) {
				map[k][l]->setColor(color);
			}
			break;
		}
	}
}

void ReversiGameManager::flipWithinRow(int x, int y, DiskColor color)
{
	for (int i = x - 1; i >= 0; i--) {
		if (board.isEmptyCell(i, y)) break;
		if (map[i][y]->getColor() == color) {
			for (int j = i; j < x; j++) {
				map[j][y]->setColor(color);
			}
			break;
		}
	}
	for (int i = x + 1; i < numOfRows; i++) {
		if (board.isEmptyCell(i, y)) break;
		if (map[i][y]->getColor() == color) {
			for (int j = i; j > x; j--) {
				map[j][y]->setColor(color);
			}
			break;
		}
	}
}

void ReversiGameManager::flipWithinColumn(int x, int y, DiskColor color)
{
	for (int i = y - 1; i >= 0; i--) {
		if (board.isEmptyCell(x, i)) break;
		if (map[x][i]->getColor() == color) {
			for (int j = i; j < y; j++) {
				map[x][j]->setColor(color);
			}
			break;
		}
	}
	for (int i = y + 1; i < numOfCols; i++) {
		if (board.isEmptyCell(x, i)) break;
		if (map[x][i]->getColor() == color) {
			for (int j = i; j > y; j--) {
				map[x][j]->setColor(color);
			}
			break;
		}
	}
}

bool ReversiGameManager::isBoardFull()
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

ReversiGameManager::ReversiGameManager(Board& board) : board(board)
{
	map = board.getMap();
	numOfRows = board.getNumOfRows();
	numOfCols = board.getNumOfCols();
	currentPlayer = Player(BLACK);
}

void ReversiGameManager::makeMove(int x, int y, ReversiValidMoveSearcher& rules)
{
	if (!rules.isValidMove(x, y, this->currentPlayer)) {
		return;
	}
	if (this->currentPlayer.getType() == BLACK) {
		board.insertBlackDisk(x, y);
	}
	else {
		board.insertWhiteDisk(x, y);
	}
	
	flipFromLeftDiagonally(x, y, this->currentPlayer.getType());
	flipFromRightDiagonally(x, y, this->currentPlayer.getType());
	flipWithinColumn(x, y, this->currentPlayer.getType());
	flipWithinRow(x, y, this->currentPlayer.getType());
	switchPlayerMove(rules);
}

Player ReversiGameManager::getCurrentPlayer()
{
	return currentPlayer;
}

void ReversiGameManager::switchPlayerMove(ReversiValidMoveSearcher& rules)
{
	if (this->currentPlayer.getType() == WHITE) {
		this->currentPlayer = Player(BLACK);
	}
	else if (this->currentPlayer.getType() == BLACK) {
		this->currentPlayer = Player(WHITE);
	}
	if (!rules.hasValidMove(this->currentPlayer)) {
		if (this->currentPlayer.getType() == WHITE) {
			this->currentPlayer = Player(BLACK);
		}
		else if (this->currentPlayer.getType() == BLACK) {
			this->currentPlayer = Player(WHITE);
		}
	}
}

GameOutcome ReversiGameManager::getWinner()
{
	if (board.isOnlyBlackDisks()) {
		return GameOutcome(BlackWin);
	}
	if (board.isOnlyWhiteDisks()) {
		return GameOutcome(WhiteWin);
	}
	if (board.isFull()) {
		if (board.countBlackDisks() > board.countWhiteDisks()) {
			return GameOutcome(BlackWin);
		}
		else if (board.countBlackDisks() < board.countWhiteDisks()) {
			return GameOutcome(WhiteWin);
		}
		else {
			return GameOutcome(Draw);
		}
	}
	return GameOutcome(Ongoing);
}
