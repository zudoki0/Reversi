#include "GridRenderer.h"

GridRenderer::GridRenderer(SDL_Renderer*& renderer, int cellSize, int gridRows, int gridCols, SDL_Color fillColor, SDL_Color outlineColor)
    :
    renderer(renderer),
    cellSize(cellSize),
    gridRows(gridRows),
    gridCols(gridCols),
    fillColor(fillColor),
    outlineColor(outlineColor)
{
}

void GridRenderer::render()
{
    for (int row = 0; row < gridRows; row++) {
        for (int col = 0; col < gridCols; col++) {
            SDL_Rect cellRect = { row * cellSize, col * cellSize, cellSize, cellSize };
            SDL_SetRenderDrawColor(renderer, fillColor.r, fillColor.g, fillColor.b, fillColor.a);
            SDL_RenderFillRect(renderer, &cellRect);
            SDL_SetRenderDrawColor(renderer, outlineColor.r, outlineColor.g, outlineColor.b, outlineColor.a);
            SDL_RenderDrawRect(renderer, &cellRect);
        }
    }
}
