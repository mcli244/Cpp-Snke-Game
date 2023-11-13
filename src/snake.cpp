#include "snake.h"
#include <iostream>

using namespace std;

Snake::Snake(int x, int y, Map *map)
    : _head_x(x),_head_y(y)
{
    _map = map;
    _score = 0;
    alive = true;
    _speed = 200;  // 每_speed ms更新一格

    SDL_Point p[3];
    _body.clear();
    for(int i=0; i<3; i++)
    {
        SDL_Point p;
        p.x = x;
        p.y = y+i;
        _body.push_back(p);
    }
    
    _food = _map->CreatFood();
    
}


void Snake::SetDir(Snake::Direction dir)
{
    switch (_dir)
    {
    case Direction::kUp:    if(dir != Direction::kDown)     _dir = dir; break;
    case Direction::kDown:  if(dir != Direction::kUp)       _dir = dir; break;
    case Direction::kLeft:  if(dir != Direction::kRight)    _dir = dir; break;
    case Direction::kRight: if(dir != Direction::kLeft)     _dir = dir; break;
    default:
        break;
    }
    
}

void Snake::SetSpeed(int speed)
{
    _speed = speed;
}

bool Snake::IsOnBody(SDL_Point &p)
{
    // 检查头是否与身体重合
    if(_body.size()>1) {
        for (auto const &item : _body) {
            if (p.x == item.x && p.y == item.y) {
                return true;
            }
        }
    }
    return false;
}

void Snake::PlaceFood(void)
{
    do{
        _food = _map->CreatFood();
    }while(IsOnBody(_food));
}

int Snake::Update(void)
{
    int ret = 0;

    uint32_t cur_ticks = _map->GetTicks();

    if(_tick + _speed > cur_ticks) return 1;

    _tick = cur_ticks;
    SDL_Point p = _body.front();
    

    switch (_dir)
    {
    case Direction::kUp:       p.y -= 1;    break;  // 上
    case Direction::kDown:     p.y += 1;    break;  // 下
    case Direction::kLeft:     p.x -= 1;    break;  // 左
    case Direction::kRight:    p.x += 1;    break;  // 右
    default:
        break;
    }
    
    p.x = fmod(p.x + _map->GetWidth(), _map->GetWidth());
    p.y = fmod(p.y + _map->GetHeight(), _map->GetHeight());

    if(IsOnBody(p))
    {
        alive = false;
        return -1;
    }

    _body.insert(_body.begin(), p);
    if(p.x != _food.x || p.y != _food.y)
        _body.pop_back();
    else
    {
        PlaceFood();
        _score ++;
    }
    
    return ret;
}

void Snake::Show(void)
{
    if(0 != Update()) return;
    
    _map->Clear();
    _map->DrawPoint(_food.x, _food.y, 0XFF8000);
    for (auto const &item : _body) 
    {
        _map->DrawPoint(item.x, item.y, 0xFFFFFF);
    }
    _map->Refresh();
}

bool Snake::IsAlive(void) { return alive; } 

void Snake::Kill(void) { alive = false; } 
