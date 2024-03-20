#ifndef HELLOSDL2_LINE_H
#define HELLOSDL2_LINE_H


#include <SDL.h>
#include "Shape.h"

class Line : public Shape {
public:
    Line(int x1, int y1, int x2, int y2, SDL_Renderer* renderer);

    void draw();

    void update();

private:
    int x1, y1, x2, y2;
    SDL_Renderer* renderer;
};


#endif //HELLOSDL2_LINE_H
