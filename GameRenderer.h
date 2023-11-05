#pragma once
#include <common.h>
#include <Disk.h>
#include <defs.h>

class GameRenderer
{
private:
	int rowCount;
	int colCount;
	SDL_Renderer* renderer;
public:
	GameRenderer(SDL_Renderer* renderer, int rowCount, int colCount);
	void renderDisks(int** map, std::set<Disk>& disks);
	void renderCursorHighlight(int row, int col, int GRID_SIZE, int outlineWidth);
	void renderValidMoves(bool** map);
};

