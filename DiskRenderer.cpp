#include "DiskRenderer.h"

DiskRenderer::DiskRenderer(SDL_Renderer*& renderer, Board& board, int size) : renderer(renderer), board(board), size(size)
{
    this->map = board.getMap();
    this->numOfRows = board.getNumOfRows();
    this->numOfCols = board.getNumOfCols();
}

void DiskRenderer::render()
{
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (map[i][j] != nullptr) {
                int centerX = this->map[i][j]->getPosX() * size + size / 2;
                int centerY = this->map[i][j]->getPosY() * size + size / 2;
                int radius = size / 2;
                switch (this->map[i][j]->getColor()) {
                case WHITE:
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    break;
                case BLACK:
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    break;
                default:
                    break;
                }
                for (int x = centerX - radius; x <= centerX + radius; x++) {
                    for (int y = centerY - radius; y <= centerY + radius; y++) {
                        if (std::sqrt(std::pow(x - centerX, 2) + std::pow(y - centerY, 2)) <= radius) {
                            SDL_RenderDrawPoint(renderer, x, y);
                        }
                    }
                }
            }
        }
    }
}