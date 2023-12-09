#pragma once
#include <common.h>
#include <IRenderer.h>

class TextRenderer : public IRenderer
{
private:
	SDL_Renderer* renderer;
	TTF_Font* font;
	const char* text;
	SDL_Rect textContainer;
	SDL_Color textColor;
public:
	TextRenderer(SDL_Renderer*& renderer, TTF_Font* font, const char* text, SDL_Rect textContainer, SDL_Color textColor);
	void render() override;
	void changeText(const char* text);
	void changeColor(SDL_Color color);
	~TextRenderer();
};

