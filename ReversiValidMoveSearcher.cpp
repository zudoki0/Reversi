#include "ReversiValidMoveSearcher.h"

bool ReversiValidMoveSearcher::searchDiagonalTopLeft(int x, int y, Player player)
{
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
        if (board.isEmptyCell(i, j)) break;
        if (map[i][j]->getColor() == player.getType()) {
            if (i + 1 < x && j + 1 < y) return true;
            break;
        }
    }
    return false;
}

bool ReversiValidMoveSearcher::searchDiagonalBottomLeft(int x, int y, Player player)
{
    for (int i = x + 1, j = y - 1; i < numOfRows && j >= 0; i++, j--) {
        if (board.isEmptyCell(i, j)) break;
        if (map[i][j]->getColor() == player.getType()) {
            if (i - 1 > x && j + 1 < y) return true;
            break;
        }
    }
    return false;
}

bool ReversiValidMoveSearcher::searchDiagonalTopRight(int x, int y, Player player)
{
    for (int i = x - 1, j = y + 1; i >= 0 && j < numOfCols; i--, j++) {
        if (board.isEmptyCell(i, j)) break;
        if (map[i][j]->getColor() == player.getType()) {
            if (i + 1 < x && j - 1 > y) return true;
            break;
        }
    }
    return false;
}

bool ReversiValidMoveSearcher::searchDiagonalBottomRight(int x, int y, Player player)
{
    for (int i = x + 1, j = y + 1; i < numOfRows && j < numOfCols; i++, j++) {
        if (board.isEmptyCell(i, j)) break;
        if (map[i][j]->getColor() == player.getType()) {
            if (i - 1 > x && j - 1 > y) return true;
            break;
        }
    }
    return false;
}

bool ReversiValidMoveSearcher::searchRowTop(int x, int y, Player player)
{
    for (int i = y + 1; i < numOfCols; i++) {
        if (board.isEmptyCell(x, i)) break;
        if (map[x][i]->getColor() == player.getType()) {
            if (i - 1 > y) return true;
            break;
        }
    }
    return false;
}

bool ReversiValidMoveSearcher::searchRowBottom(int x, int y, Player player)
{
    for (int i = y - 1; i >= 0; i--) {
        if (board.isEmptyCell(x, i)) break;
        if (map[x][i]->getColor() == player.getType()) {
            if (i + 1 < y) return true;
            break;
        }
    }
    return false;
}

bool ReversiValidMoveSearcher::searchColLeft(int x, int y, Player player)
{
    for (int i = x + 1; i < numOfRows; i++) {
        if (board.isEmptyCell(i, y)) break;
        if (map[i][y]->getColor() == player.getType()) {
            if (i - 1 > x) return true;
            break;
        }
    }
    return false;
}

bool ReversiValidMoveSearcher::searchColRight(int x, int y, Player player)
{
    for (int i = x - 1; i >= 0; i--) {
        if (board.isEmptyCell(i, y)) break;
        if (map[i][y]->getColor() == player.getType()) {
            if (i + 1 < x) return true;
            break;
        }
    }
    return false;
}

bool ReversiValidMoveSearcher::isAdjacentToExisting(int x, int y, Player player)
{
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int new_x = x + dx;
            int new_y = y + dy;
            if (new_x >= 0 && new_x < numOfRows && new_y >= 0 && new_y < numOfCols && map[new_x][new_y] != nullptr && map[new_x][new_y]->getColor() != player.getType()) {
                return true;
            }
        }
    }
    return false;
}

ReversiValidMoveSearcher::ReversiValidMoveSearcher(Board& board): board(board)
{
    this->map = board.getMap();
    this->numOfRows = board.getNumOfRows();
    this->numOfCols = board.getNumOfCols();
    validOptionsMap = new bool* [numOfRows];
    for (int i = 0; i < numOfRows; i++)
        validOptionsMap[i] = new bool[numOfCols];
}

ReversiValidMoveSearcher::~ReversiValidMoveSearcher()
{
    for (int i = 0; i < numOfRows; i++)
        delete validOptionsMap[i];
    delete validOptionsMap;
}

bool ReversiValidMoveSearcher::isValidMove(int x, int y, Player player)
{
    if (!(board.isWithinMap(x, y))) return false;
    return (searchDiagonalTopLeft(x, y, player) || searchDiagonalBottomLeft(x, y, player) || searchDiagonalTopRight(x, y, player) || searchDiagonalBottomRight(x, y, player)
        || searchRowTop(x, y, player) || searchRowBottom(x, y, player)
        || searchColLeft(x, y, player) || searchColRight(x, y, player)) && isAdjacentToExisting(x, y, player);
}

bool** ReversiValidMoveSearcher::getValidMovesMap(Player player)
{
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (map[i][j] == nullptr && isValidMove(i, j, player)) {
                validOptionsMap[i][j] = true;
            }
            else {
                validOptionsMap[i][j] = false;
            }
        }
    }
    return validOptionsMap;
}

bool ReversiValidMoveSearcher::hasValidMove(Player player)
{
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (map[i][j] == 0 && isValidMove(i, j, player)) {
                return true;
            }
        }
    }
    return false;
}