#include "ReversiRules.h"

bool ReversiRules::isOnlyBlackDisks()
{
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (map[i][j]->getColor() == WHITE) return false;
        }
    }
    return true;
}

bool ReversiRules::isOnlyWhiteDisks()
{
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (map[i][j]->getColor() == BLACK) return false;
        }
    }
    return true;
}

bool ReversiRules::isFull()
{
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (map[i][j] == nullptr) return false;
        }
    }
    return true;
}

ReversiRules::ReversiRules(Board& board)
{
	this->map = board.getMap();
	this->numOfRows = board.getNumOfRows();
	this->numOfCols = board.getNumOfCols();
}

ReversiRules::~ReversiRules()
{
}

bool ReversiRules::isGameOver()
{
    return isFull();
}

bool ReversiRules::checkPlayerWon(Player player)
{
    if (player.getType() == WHITE) {
        if (isOnlyBlackDisks()) return true;
    }
    else {
        if (isOnlyWhiteDisks()) return true;
    }
    return false;
}

int ReversiRules::countBlackDisks()
{
    int counter = 0;
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (map[i][j]->getColor() == BLACK) {
                counter++;
            }
        }
    }
    return counter;
}

int ReversiRules::countWhiteDisks()
{
    int counter = 0;
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (map[i][j]->getColor() == WHITE) {
                counter++;
            }
        }
    }
    return counter;
}
