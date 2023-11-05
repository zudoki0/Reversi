#include "GameRenderer.h"


void GameRenderer::renderDisks(int** map, std::set<Disk>& disks) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (map[i][j] == BLACK_DISK) {
                Disk disk = Disk(renderer, i, j, DiskType::BLACK, 44);
                disks.erase(disk);
                disks.insert(disk);
            }
            else if (map[i][j] == WHITE_DISK) {
                Disk disk = Disk(renderer, i, j, DiskType::WHITE, 44);
                disks.erase(disk);
                disks.insert(disk);
            }
        }
    }
}

void GameRenderer::renderCursorHighlight(int mouseX, int mouseY, int GRID_SIZE, int outlineWidth)
{
    int row = mouseX / GRID_SIZE;
    int col = mouseY / GRID_SIZE;
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

void GameRenderer::renderValidMoves(bool** map)
{
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (map[i][j] == true) {
                Disk disk = Disk(renderer, i, j, DiskType::BLACK, 44);
                disk.setColor(Color(0, 0, 0, 255));
                disk.drawOutline(48);
            }
        }
    }
}

GameRenderer::GameRenderer(SDL_Renderer*& renderer, int rowCount, int colCount) : renderer(renderer), rowCount(rowCount), colCount(colCount)
{
}
