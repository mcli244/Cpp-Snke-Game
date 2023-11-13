#include "game.h"
#include <unistd.h>
#include <iostream>
using namespace std;

Game::Game()
{
    map = new Map(50, 50);
    snaker = new Snake(3, 5, map);
    input = new Input();
    snaker->SetSpeed(100);  // 正常
}

Game::Game(GameMode mode) : _mode(mode)
{
    map = new Map(50, 50);
    snaker = new Snake(3, 5, map);
    input = new Input();
    switch (mode)
    {
    case GameMode::Easy :       snaker->SetSpeed(150);  break;
    case GameMode::Normal :     snaker->SetSpeed(100);  break;
    case GameMode::Hard :       snaker->SetSpeed(50);  break;
    default:
        break;
    }
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
    int speed = 200;

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
                cout << "speed:"<< speed << endl;
                break;
            case SDLK_l: 
                if(speed <= 200)  speed ++; 
                snaker->SetSpeed(speed); 
                cout << "speed:"<< speed << endl;
                break;
            case SDLK_ESCAPE:
                snaker->Kill();
                break;
            default: break;
        }
        snaker->Show();
        usleep(10*1000);
    }
    cout << "Game over\n" << "GetScore: "<< snaker->GetScore() << endl;
}
