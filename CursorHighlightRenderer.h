#pragma once
#include <common.h>
#include "IRenderer.h"
class CursorHighlightRenderer :
    public IRenderer
{
private:
	SDL_Renderer* renderer;
	int size;
	int outlineWidth;
	int mouseX;
	int mouseY;
public:
	CursorHighlightRenderer(SDL_Renderer*& renderer, int size, int outlineWidth);
	void render() override;
	void setMousePos(int x, int y);
};

