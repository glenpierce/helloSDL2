#include "Node.h"
#include <vector>

Node::Node(int x, int y, std::vector<Node*> connections) {
    this->x = x;
    this->y = y;
    this->connections = connections;
}

std::vector<Node*> Node::getConnections() {
    return connections;
}

int Node::getX() {
    return x;
}

int Node::getY() {
    return y;
}
