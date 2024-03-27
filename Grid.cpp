#include "Grid.h"

Grid::Grid(SDL_Renderer *renderer, int height, int width, int resolution) {
    this->height = height;
    this->width = width;
    this->resolution = resolution;
    this->renderer = renderer;
}

void Grid::draw() {
    SDL_SetRenderDrawColor(renderer, 0xAA, 0xAA, 0xAA, 0xAA); // grey?
    for (int i = 0; i < width; i += resolution) {
        SDL_RenderDrawLine(renderer, i, 0, i, height); // draw every vertical line
    }
    for(int j = 0; j < height; j += resolution) {
        SDL_RenderDrawLine(renderer, 0, j, width, j); // draw every horizontal line
    }
}

void Grid::update() {

}
