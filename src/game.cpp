#include "game.h"
#include <unistd.h>
#include <iostream>
using namespace std;

Game::Game()
{
    
    Input *input = new Input();
    // Map *map = new Map(200, 200);
    // Snake *snaker = new Snake(20, 20);
}

Game::~Game()
{
    delete snaker;
    delete map;
    delete input;
}
void Game::CtreatFood(Snake *_snaker, Map *_map)
{
    while (true) {
        food = _map->CreatFood();
        if(false == _snaker->IsOnBody(food))
            break;
    }
}

void Game::run(void)
{
    SDL_Keycode key;
    int ret = -1;
    int cnt = 0;
    int update_cnt = 100;

    Map *map = new Map(200, 200);
    Snake *snaker = new Snake(20, 20, 500, 500);

    CtreatFood(snaker, map);
    cout << "food:("<<food.x <<","<< food.y << ")"<<endl;
    while(snaker->IsAlive())
    {

        
        key = input->HandleInput();
        switch (key) {
            case SDLK_UP:       snaker->SetDir(Snake::Direction::kUp); break;
            case SDLK_DOWN:     snaker->SetDir(Snake::Direction::kDown); break;
            case SDLK_LEFT:     snaker->SetDir(Snake::Direction::kLeft); break;
            case SDLK_RIGHT:    snaker->SetDir(Snake::Direction::kRight); break;
            case SDLK_h:        
                if(update_cnt <= 10)
                    update_cnt = 10;
                else
                    update_cnt-=10; 
                break;
            case SDLK_l:
                if(update_cnt >= 100)
                    update_cnt = 100;
                else
                    update_cnt+=10; 
                break;
        }
        
        if(cnt ++ >= update_cnt)
        {
            cnt = 0;
            cout<<"update_cnt:"<<update_cnt << " food:("<<food.x <<","<< food.y << ")"<<endl;
            ret = snaker->Update(food);
            if(ret == 1)
            {
                CtreatFood(snaker, map);
            }
            snaker->Show();
        }
        usleep(10*1000);
    }
}
