#pragma once
#include "Command.h"
#include "ReversiGameManager.h"
class MoveCommand :
    public Command
{
private:
    ReversiGameManager& gameManager;
    ReversiValidMoveSearcher& searcher;
    int row, col;
public:
    MoveCommand(ReversiGameManager& gameManager, int row, int col, ReversiValidMoveSearcher& searcher);
    void execute() override;
};

