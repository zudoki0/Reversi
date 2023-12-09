#pragma once
#include <common.h>
#include <IRenderer.h>
#include <Disk.h>
#include <Board.h>

class DiskRenderer : public IRenderer
{
private:
	SDL_Renderer* renderer;
	Board& board;
	Disk*** map;
	int numOfRows;
	int numOfCols;
	int size;
public:
	DiskRenderer(SDL_Renderer*& renderer, Board& board, int size);
	void render() override;
};

