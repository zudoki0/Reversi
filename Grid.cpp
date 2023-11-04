#include "Grid.h"

void Grid::draw() {
	for (int row = 0; row < GRID_ROWS; row++) {
        for (int col = 0; col < GRID_COLUMNS; col++) {
            SDL_Rect cellRect = { col * GRID_SIZE, row * GRID_SIZE, GRID_SIZE, GRID_SIZE };
            SDL_SetRenderDrawColor(renderer, fillColor.getRed(), fillColor.getGreen(), fillColor.getBlue(), fillColor.getAlpha());
            SDL_RenderFillRect(renderer, &cellRect);
            SDL_SetRenderDrawColor(renderer, outlineColor.getRed(), outlineColor.getGreen(), outlineColor.getBlue(), outlineColor.getAlpha());
            SDL_RenderDrawRect(renderer, &cellRect);
        }
    }
}

void Grid::draw(int x, int y, int outlineWidth) {
    int row = x / GRID_SIZE;
    int col = y / GRID_SIZE;
    for (int row = 0; row < GRID_ROWS; row++) {
        for (int col = 0; col < GRID_COLUMNS; col++) {
            SDL_Rect cellRect = { col * GRID_SIZE, row * GRID_SIZE, GRID_SIZE, GRID_SIZE };
            SDL_SetRenderDrawColor(renderer, fillColor.getRed(), fillColor.getGreen(), fillColor.getBlue(), fillColor.getAlpha());
            SDL_RenderFillRect(renderer, &cellRect);
            SDL_SetRenderDrawColor(renderer, outlineColor.getRed(), outlineColor.getGreen(), outlineColor.getBlue(), outlineColor.getAlpha());
            SDL_RenderDrawRect(renderer, &cellRect);
        }
    }
    drawCell(row, col, outlineWidth);
}

void Grid::drawCell(int row, int col, int outlineWidth) {
    SDL_Rect outline;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    //Top border
    outline.x = row * GRID_SIZE;
    outline.y = col * GRID_SIZE;
    outline.w = GRID_SIZE;
    outline.h = outlineWidth;
    SDL_RenderFillRect(renderer, &outline);

    //Bottom border
    outline.y = col * GRID_SIZE + GRID_SIZE - outlineWidth;
    SDL_RenderFillRect(renderer, &outline);

    //Left border
    outline.y = col * GRID_SIZE;
    outline.w = outlineWidth;
    outline.h = GRID_SIZE;
    SDL_RenderFillRect(renderer, &outline);

    //Right border
    outline.x = row * GRID_SIZE + GRID_SIZE - outlineWidth;
    SDL_RenderFillRect(renderer, &outline);
}

Grid::Grid(SDL_Renderer* renderer, int GRID_SIZE, int GRID_ROWS, int GRID_COLUMNS) : renderer(renderer), GRID_SIZE(GRID_SIZE), GRID_ROWS(GRID_ROWS), GRID_COLUMNS(GRID_COLUMNS) {
    this->outlineColor = Color(0, 0, 0, 255);
    this->fillColor = Color(255, 255, 255, 255);
}

void Grid::setFillColor(Color color){
    this->fillColor = color;
}

void Grid::setOutlineColor(Color color) {
    this->outlineColor = color;
}

void Grid::setGridSize(int pixels) {
    this->GRID_SIZE = pixels;
}

void Grid::setGridRows(int amount) {
    this->GRID_ROWS = amount;
}

void Grid::setGridColumns(int amount) {
    this->GRID_COLUMNS = amount;
}

int Grid::getGridWidth()
{
    return GRID_SIZE * GRID_ROWS;
}

int Grid::getGridHeight()
{
    return GRID_SIZE * GRID_COLUMNS;
}

int Grid::getGridSize()
{
    return GRID_SIZE;
}

bool Grid::isWithinGrid(int x, int y)
{
    return x >= 0 && y >= 0 && x < this->getGridWidth() && y < this->getGridHeight();
}
