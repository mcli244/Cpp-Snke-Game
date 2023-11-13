#include "game.h"
#include <unistd.h>
#include <iostream>
using namespace std;

Game::Game()
{
    map = new Map(50, 50);
    snaker = new Snake(3, 5, map);
    input = new Input();
}

Game::~Game()
{
    delete input;
    delete snaker;
    delete map;
}

void Game::run(void)
{
    SDL_Keycode key;
    int speed = 100;

    while(snaker->IsAlive())
    {
        key = input->HandleInput();
        switch (key) {
            case SDLK_UP:       snaker->SetDir(Snake::Direction::kUp); break;
            case SDLK_DOWN:     snaker->SetDir(Snake::Direction::kDown); break;
            case SDLK_LEFT:     snaker->SetDir(Snake::Direction::kLeft); break;
            case SDLK_RIGHT:    snaker->SetDir(Snake::Direction::kRight); break;
            case SDLK_h:  
                if(speed > 0)  speed --;
                snaker->SetSpeed(speed);
                break;
            case SDLK_l: 
                if(speed <= 100)  speed ++; 
                snaker->SetSpeed(speed); 
                break;
            default: break;
        }
        snaker->Show();
        usleep(10*1000);
    }
    cout << "Game over" << endl;
}
