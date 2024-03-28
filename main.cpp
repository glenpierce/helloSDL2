#include <cstdio>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <vector>
#include "Shape.h"
#include "Line.h"
#include "Grid.h"
#include "Dot.h"
#include "Graph.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argv, char** args) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if( SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == nullptr) {
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            } else {

                std::vector<Shape*> shapes;

                Grid grid(renderer, SCREEN_HEIGHT, SCREEN_WIDTH, 10);
                std::vector<Node*> nodes;
                Node* node1 = new Node(20, 20, {});
                Node* node2 = new Node(40, 40, {node1});
                for(int i = 0; i < 20; i++) {
                    std::vector<Node*> connections;
                    for(int j = 0; j < 3; j++) {
                        if (!nodes.empty()) {
                            connections.push_back(nodes[rand() % nodes.size()]);
                        }
                    }
                    Node* node = new Node(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, connections);
                    nodes.push_back(node);
                }
                nodes.push_back(node1);
                nodes.push_back(node2);
                Graph graph(renderer, nodes);

                Dot dot(renderer, 100, 100, 100);
                shapes.push_back(&dot);

                shapes.push_back(&grid);
                shapes.push_back(&graph);

                //get window to stay up
                SDL_Event sdlEvent;
                bool quit = false;
                while(!quit) {
                    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(renderer);

                    while(SDL_PollEvent(&sdlEvent) ) {
                        if(sdlEvent.type == SDL_QUIT) {
                            quit = true;
                        }
                    }

                    for (Shape* shape : shapes) {
                        shape->update();
                        shape->draw();
                    }

                    SDL_RenderPresent(renderer);

                }

                for (Shape* shape : shapes) {
                    delete shape;
                }

            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}
