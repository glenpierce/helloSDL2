#include "Graph.h"

Graph::Graph(SDL_Renderer *renderer, std::vector<Node*> nodes) {
    this->renderer = renderer;
    this->nodes = nodes;

}

void Graph::draw() {
    for(auto& node : nodes) {
        auto connections = node->getConnections();
        for(auto& connection : connections) {
            SDL_RenderDrawLine(renderer, node->getX(), node->getY(), connection->getX(), connection->getY());
        }
    }
}

void Graph::update() {

}
