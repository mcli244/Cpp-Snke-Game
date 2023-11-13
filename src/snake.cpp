#include "snake.h"
#include <iostream>

using namespace std;

Snake::Snake(int x, int y)
    : _head_x(x),_head_y(y)
{
    cout << "Snake(int x, int y)" << endl;
    SDL_Point p;
    p.x = x;
    p.y = y;

    _food_cnt = 0;
    alive = true;
    _body.clear();
    _body.push_back(p);

    render = new Renderer(200, 200);
}

Snake::Snake(int x, int y, int map_w, int map_h)
    : _head_x(x),_head_y(y), _map_w(map_w), _map_h(map_h)
{
    cout << "Snake(int x, int y, int map_w, int map_h)" << endl;
    SDL_Point p;
    p.x = x;
    p.y = y;

    _food_cnt = 0;
    alive = true;
    _body.clear();
    _body.push_back(p);
    render = new Renderer(200, 200);
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

int Snake::Update(SDL_Point &food)
{
    SDL_Point p = _body.front();
    int ret = 0;

    switch (_dir)
    {
    case Direction::kUp:       p.y -= 1;    break;  // 上
    case Direction::kDown:     p.y += 1;    break;  // 下
    case Direction::kLeft:     p.x -= 1;    break;  // 左
    case Direction::kRight:    p.x += 1;    break;  // 右
    default:
        break;
    }
    
    p.x = fmod(p.x + _map_w, _map_w);
    p.y = fmod(p.y + _map_h, _map_h);

    if(IsOnBody(p))
    {
        alive = false;
        return -1;
    }

    _body.insert(_body.begin(), p);
    if(p.x != food.x || p.y != food.y)
        _body.pop_back();
    else
    {
        ret = 1;
        _food_cnt ++;
    }
    _food.x = food.x;
    _food.y = food.y;
    
    // // 检查是否到地图边界
    // if (p.x >= _map_w || p.x < 0
    //     || p.y >= _map_h || p.y < 0) {
    //     alive = false;
    //     return -2;
    // }
    
    return ret;
}

void Snake::Show(void)
{
    render->Clear();
    render->DrawPoint(_food.x, _food.y, 0xff0000);
    for (auto const &item : _body) 
    {
        render->DrawPoint(item.x, item.y, 0x00ff00);
    }
    render->Refresh();
}

void Snake::SetMap(int map_w, int map_h)
{
    _map_w = map_w;
    _map_h = map_h;
}

bool Snake::IsAlive(void)
{
    return alive;
}