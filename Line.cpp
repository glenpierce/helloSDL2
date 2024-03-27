#include "Line.h"

Line::Line(SDL_Renderer* renderer, int x1, int y1, int x2, int y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->renderer = renderer;
}

void Line::draw() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Red color
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2); // Draw a line from top-left to bottom-right
}

void Line::update() {
    y1++;
    y2++;

    if(y1 > 480) {
        y1 = 0;
    }

    if(y2 > 480) {
        y2 = 0;
    }

}