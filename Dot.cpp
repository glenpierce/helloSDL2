#include "Dot.h"

Dot::Dot(SDL_Renderer* renderer, int x, int y, int radius) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->renderer = renderer;
}

void Dot::draw() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Red
    SDL_RenderDrawPoint(renderer, x, y);
}

void Dot::update() {

}