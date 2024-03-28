#ifndef HELLOSDL2_GRAPH_H
#define HELLOSDL2_GRAPH_H

#include <vector>
#include <SDL.h>
#include "Shape.h"
#include "Node.h"

class Graph : public Shape {
public:
    Graph(SDL_Renderer* renderer, std::vector<Node*> nodes);

    void draw();

    void update();

private:
    std::vector<Node*> nodes;
    SDL_Renderer* renderer;
};

#endif //HELLOSDL2_GRAPH_H
