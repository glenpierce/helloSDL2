#ifndef HELLOSDL2_NODE_H
#define HELLOSDL2_NODE_H

#include <vector>

class Node {
public:
    Node(int x, int y, std::vector<Node*> connections);
    std::vector<Node*> getConnections();
    int getX();
    int getY();

private:
    int x, y;
    std::vector<Node*> connections;
};

#endif //HELLOSDL2_NODE_H
