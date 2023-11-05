#include "TextRenderer.h"

TextRenderer::TextRenderer(SDL_Renderer*& renderer) : renderer(renderer)
{

}

void TextRenderer::renderText(TTF_Font* font, const char* text)
{
    SDL_Color textColor = { 0,0,0,255 };
    SDL_Rect textRect = { 0,384,384,116 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, textureText, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textureText);
}
