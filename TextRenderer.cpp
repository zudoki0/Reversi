#include "TextRenderer.h"

TextRenderer::TextRenderer(SDL_Renderer*& renderer, TTF_Font* font, const char* text, SDL_Rect textContainer, SDL_Color textColor) :
    renderer(renderer),
    font(font),
    text(text),
    textContainer(textContainer),
    textColor(textColor)
{
}

void TextRenderer::render()
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, textureText, NULL, &textContainer);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textureText);
}

void TextRenderer::changeText(const char* text)
{
    this->text = text;
}

void TextRenderer::changeColor(SDL_Color color)
{
    this->textColor = color;
}

TextRenderer::~TextRenderer()
{
}
