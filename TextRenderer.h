#pragma once
#include <common.h>

class TextRenderer
{
private:
	SDL_Renderer*& renderer;
public:
	TextRenderer(SDL_Renderer*& renderer);
	void renderText(TTF_Font* font, const char*);
};

