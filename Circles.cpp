#include <iostream>
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"

#include "Shape.h"

SDL_Window* win = NULL;
SDL_Renderer* render = NULL;

int win_width = 800;
int win_height = 600;

bool RUN = true;
bool FPS = 1000 / 60;

void Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Can't init SDL! Error: %s", SDL_GetError());
        exit(1);
    }

    win = SDL_CreateWindow("Smth", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_width, win_height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    if (win == NULL) {
        printf("Can't init window! Error: %s", SDL_GetError());
        exit(1);
    }

    render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (render == NULL) {
        printf("Can't init renderer! Error: %s", SDL_GetError());
        exit(1);
    }
}

void DeInit(int error) {
    if (render != NULL) SDL_DestroyRenderer(render);
    if (win != NULL) SDL_DestroyWindow(win);

    SDL_Quit();
    exit(error);
}

void HandleButtons(const SDL_Event& event);

void HandleEvents() 
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                RUN = false;
                break;
            case SDL_KEYDOWN:
                HandleButtons(event);
                break;
            default:
                break;
        }
    }
}

void HandleButtons(const SDL_Event& event)
{
    switch (event.key.keysym.sym) {
    case SDLK_UP:
        std::cout << "Up arrow key pressed" << std::endl;
        break;
    case SDLK_DOWN:
        std::cout << "Down arrow key pressed" << std::endl;
        break;
    case SDLK_LEFT:
        std::cout << "Left arrow key pressed" << std::endl;
        break;
    case SDLK_RIGHT:
        std::cout << "Right arrow key pressed" << std::endl;
        break;
    default:
        break;
    }
}

int main(int argc, char* argv[])
{
    Init();
    Circle circle(0, 0, 300);

    Shape::SetRender(render);

    while (RUN)
    {
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_RenderClear(render);

        HandleEvents();

        Shape::DrawAll();

        SDL_RenderPresent(render);
    }

    DeInit(0);

    return 0;
}
