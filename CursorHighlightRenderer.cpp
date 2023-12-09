#include "CursorHighlightRenderer.h"

CursorHighlightRenderer::CursorHighlightRenderer(SDL_Renderer*& renderer, int size, int outlineWidth): renderer(renderer), size(size), outlineWidth(outlineWidth), mouseX(0), mouseY(0)
{
}

void CursorHighlightRenderer::setMousePos(int x, int y) {
    this->mouseX = x;
    this->mouseY = y;
}

void CursorHighlightRenderer::render()
{
    int row = mouseX / size;
    int col = mouseY / size;
    SDL_Rect outline = {0,0,0,0};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    //Top border
    outline.x = row * size;
    outline.y = col * size;
    outline.w = size;
    outline.h = outlineWidth;
    SDL_RenderFillRect(renderer, &outline);

    //Bottom border
    outline.y = col * size + size - outlineWidth;
    SDL_RenderFillRect(renderer, &outline);

    //Left border
    outline.y = col * size;
    outline.w = outlineWidth;
    outline.h = size;
    SDL_RenderFillRect(renderer, &outline);

    //Right border
    outline.x = row * size + size - outlineWidth;
    SDL_RenderFillRect(renderer, &outline);
}
