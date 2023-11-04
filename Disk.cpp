#include "Disk.h"

Disk::Disk(SDL_Renderer* renderer, int posX, int posY, DiskType type, int size) : renderer(renderer), posX(posX), posY(posY), type(type), size(size)
{
    switch(type) {
    case WHITE:
        color = Color(255,255,255,255);
        break;
    case BLACK:
        color = Color(0,0,0,255);
        break;
    }
}

void Disk::draw(int containerSize)
{
    int centerX = posX * containerSize + containerSize / 2;
    int centerY = posY * containerSize + containerSize / 2;
    int radius = size / 2;
    SDL_SetRenderDrawColor(renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    for (int x = centerX - radius; x <= centerX + radius; x++) {
        for (int y = centerY - radius; y <= centerY + radius; y++) {
            if (std::sqrt(std::pow(x - centerX, 2) + std::pow(y - centerY, 2)) <= radius) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

bool Disk::operator<(const Disk& other) const
{
    if (this->posX < other.posX) {
        return true;
    }
    if (this->posX > other.posX) {
        return false;
    }
    return this->posY < other.posY;
}

bool Disk::operator==(const Disk &other) const {
    return this->posX == other.posX && this->posY == other.posY;
}

int Disk::getPosX() {
    return posX;
}

int Disk::getPosY() {
    return posY;
}