#include "ReversiBoardBuilder.h"

Board ReversiBoardBuilder::build()
{
    Board board = Board(numOfRows, numOfCols);
    board.insertBlackDisk(3, 3);
    board.insertWhiteDisk(3, 4);
    board.insertBlackDisk(4, 4);
    board.insertWhiteDisk(4, 3);
    return board;
}
