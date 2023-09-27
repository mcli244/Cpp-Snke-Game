#include "game.h"
#include <unistd.h>

Game::Game(void)
{
    Input *input = new Input();
    Renderer *render = new Renderer(50, 50);
    Map *map = new Map(50, 50);
    Snake *snaker = new Snake(20, 20, 50, 50);
}

Game::~Game()
{
    delete snaker;
    delete map;
    delete render;
    delete input;
}

void Game::run(void)
{
    SDL_Keycode key;
    int ret = -1;
    SDL_Point food;

    food = map->CreatFood();
    while(snaker->IsAlive())
    {
        key = input->HandleInput();
        // case 0:    p.y -= 1;    break;  // 上
        // case 1:    p.y += 1;    break;  // 下
        // case 2:    p.x -= 1;    break;  // 左
        // case 3:    p.x += 1;    break;  // 右
        switch (key) {
            case SDLK_UP:       snaker->SetDir(0); break;
            case SDLK_DOWN:     snaker->SetDir(1); break;
            case SDLK_LEFT:     snaker->SetDir(2); break;
            case SDLK_RIGHT:    snaker->SetDir(3); break;
        }
        
        ret = snaker->Update(food);
        if(ret == 1)
            food = map->CreatFood();
        
        sleep(1);
    }
}
