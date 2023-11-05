#pragma once
#include <common.h>
#include <Color.h>
#include <Coord.h>

class Grid
{
private:
	int GRID_SIZE;
	int GRID_ROWS;
	int GRID_COLUMNS;
	SDL_Renderer* renderer;
	Color fillColor;
	Color outlineColor;
public:
	Grid(SDL_Renderer* renderer, int GRID_SIZE, int GRID_ROWS, int GRID_COLUMNS);
	void draw();
	void draw(int x, int y, int outlineWidth);
	void setFillColor(Color color);
	void setOutlineColor(Color color);
	void setGridSize(int pixels);
	void setGridRows(int amount);
	void setGridColumns(int amount);
	int getGridWidth();
	int getGridHeight();
	int getGridSize();
	bool isWithinGrid(int x, int y);
};

