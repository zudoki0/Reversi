#include "MoveCommand.h"



MoveCommand::MoveCommand(ReversiGameManager& gameManager, int row, int col, ReversiValidMoveSearcher& searcher): gameManager(gameManager), row(row), col(col), searcher(searcher)
{
}

void MoveCommand::execute()
{
	gameManager.makeMove(row, col, searcher);
}

