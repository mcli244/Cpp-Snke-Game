#include "SDL.h"

class Renderer
{
public:
    Renderer(int width, int hight);
    ~Renderer();

    void Fill(void);
    void test(void);

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    int window_h;
    int window_w;

};


