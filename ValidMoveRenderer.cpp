#include "ValidMoveRenderer.h"

ValidMoveRenderer::ValidMoveRenderer(SDL_Renderer*& renderer, ReversiValidMoveSearcher* searcher, Board& board, int size, Player player): renderer(renderer), searcher(searcher), size(size), player(player)
{
    this->posX = 0;
    this->posY = 0;
    this->numOfRows = board.getNumOfRows();
    this->numOfCols = board.getNumOfCols();
}

void ValidMoveRenderer::render()
{
    bool** map = searcher->getValidMovesMap(player);
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (map[i][j] == true) {
                int centerX = i * size + size / 2;
                int centerY = j * size + size / 2;
                int radius = size / 2;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                for (int angle = 0; angle < 360; angle++) {
                    int x = centerX + int(radius * std::cos(angle * M_PI / 180.0));
                    int y = centerY + int(radius * std::sin(angle * M_PI / 180.0));
                    SDL_RenderDrawPoint(renderer, x, y);
                }
            }
        }
    }
}

void ValidMoveRenderer::setPos(int x, int y)
{
    this->posX = x;
    this->posY = y;
}

void ValidMoveRenderer::setPlayer(Player player)
{
    this->player = player;
}
