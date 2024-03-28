#include "Dot.h"

Dot::Dot(SDL_Renderer* renderer, int x, int y, int radius) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->renderer = renderer;
}

void Dot::draw() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Red
    int d = 3 - 2 * radius;
    int currentX = radius;
    int currentY = 0;

    while (currentY <= currentX) {
        SDL_RenderDrawPoint(renderer,x + currentX, y + currentY);
        SDL_RenderDrawPoint(renderer,x - currentX, y + currentY);
        SDL_RenderDrawPoint(renderer,x + currentX, y - currentY);
        SDL_RenderDrawPoint(renderer,x - currentX, y - currentY);
        SDL_RenderDrawPoint(renderer,x + currentY, y + currentX);
        SDL_RenderDrawPoint(renderer,x - currentY, y + currentX);
        SDL_RenderDrawPoint(renderer,x + currentY, y - currentX);
        SDL_RenderDrawPoint(renderer,x - currentY, y - currentX);

        currentY++;

        // Update d based on the decision criterion
        if (d > 0) {
            currentX--;
            d = d + 4 * (currentY - currentX) + 10;
        } else {
            d = d + 4 * currentY + 6;
        }
    }
}

void Dot::update() {

}