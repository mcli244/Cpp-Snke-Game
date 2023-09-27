#include "renderer.h"
#include <iostream>
using namespace std;


Renderer::Renderer(int width, int hight)
    :window_w(width), window_h(hight)
{

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL could not initialize." << endl;
        cerr << "SDL_Error: " << SDL_GetError() << endl;
    }

    // CreateWindows
    sdl_window = SDL_CreateWindow("test title", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, width,
                                hight, SDL_WINDOW_SHOWN);
    if(nullptr == sdl_window)
    {
        cerr << "SDL_CreateWindow filed" << endl;
        cerr << "sdl err: " << SDL_GetError() << endl;
    }

    // CreateRenderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if(nullptr == sdl_renderer)
    {
        cerr << "SDL_CreateRenderer filed" << endl;
        cerr << "sdl err: " << SDL_GetError() << endl;
    }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Fill(void)
{
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(sdl_renderer);
    SDL_RenderPresent(sdl_renderer);
}


void Renderer::test(void)
{
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(sdl_renderer);

    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xFF, 0x00, 0x00);
    SDL_RenderDrawPoint(sdl_renderer, 0, 0);

    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0xFF, 0x00);
    SDL_RenderDrawLine(sdl_renderer, 5, 5, 100, 100);

    SDL_Rect rect;
    rect.x = 20;
    rect.y = 20;
    rect.w = 20;
    rect.h = 20;
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0x00);
    SDL_RenderDrawRect(sdl_renderer, &rect);

    SDL_RenderPresent(sdl_renderer);
}
