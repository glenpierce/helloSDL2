#ifndef HELLOSDL2_GRID_H
#define HELLOSDL2_GRID_H


#include <SDL.h>
#include "Shape.h"

class Grid : public Shape {
public:
    Grid(SDL_Renderer* renderer, int height, int width, int resolution);

    void draw();

    void update();

private:
    int height, width, resolution;
    SDL_Renderer* renderer;

};


#endif //HELLOSDL2_GRID_H
