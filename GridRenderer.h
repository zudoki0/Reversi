#pragma once
#include <common.h>
#include <IRenderer.h>
class GridRenderer: public IRenderer
{
private:
	SDL_Renderer* renderer;
	int cellSize;
	int gridRows;
	int gridCols;
	SDL_Color fillColor;
	SDL_Color outlineColor;
public:
	GridRenderer(SDL_Renderer*& renderer, int cellSize, int gridRows, int gridCols, SDL_Color fillColor, SDL_Color outlineColor);
	void render() override;
};

