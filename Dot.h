#ifndef HELLOSDL2_DOT_H
#define HELLOSDL2_DOT_H


#include <SDL.h>
#include "Shape.h"

class Dot : public Shape {
public:
    Dot( SDL_Renderer* renderer, int x, int y, int radius);

    void draw();

    void update();

private:
    int x, y, radius;
    SDL_Renderer* renderer;
};


#endif //HELLOSDL2_DOT_H
