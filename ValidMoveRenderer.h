#pragma once
#include "IRenderer.h"
#include <common.h>
#include <ReversiValidMoveSearcher.h>

class ValidMoveRenderer :
    public IRenderer
{
private:
	ReversiValidMoveSearcher* searcher;
	SDL_Renderer* renderer;
	int size;
	int posX;
	int posY;
	int numOfRows;
	int numOfCols;
	Player player;
public:
	ValidMoveRenderer(SDL_Renderer*& renderer, ReversiValidMoveSearcher* searcher, Board& board, int size, Player player);
	void render() override;
	void setPos(int x, int y);
	void setPlayer(Player player);
};

