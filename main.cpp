#include <cstdio>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <vector>
#include "Shape.h"
#include "Line.h"
#include "Grid.h"

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

                shapes.push_back(&grid);

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
