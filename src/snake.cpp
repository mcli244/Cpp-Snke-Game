#include "snake.h"
#include <iostream>

using namespace std;

Snake::Snake(int x, int y)
    : _head_x(x),_head_y(y)
{
    SDL_Point p;
    p.x = x;
    p.y = y;

    _food_cnt = 0;
    alive = true;
    _body.clear();
    _body.push_back(p);
}

Snake::Snake(int x, int y, int map_w, int map_h)
    : _head_x(x),_head_y(y), _map_w(map_w), _map_h(map_h)
{
    SDL_Point p;
    p.x = x;
    p.y = y;

    _food_cnt = 0;
    alive = true;
    _body.clear();
    _body.push_back(p);
}

void Snake::SetDir(int dir)
{
    _dir = dir;
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
    case 0:    p.y -= 1;    break;  // 上
    case 1:    p.y += 1;    break;  // 下
    case 2:    p.x -= 1;    break;  // 左
    case 3:    p.x += 1;    break;  // 右
    default:
        break;
    }
    
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
    
    // 检查是否到地图边界
    if (p.x >= _map_w || p.x < 0
        || p.y >= _map_h || p.y < 0) {
        alive = false;
        return -2;
    }
    
    return ret;
}

void Snake::Show(void)
{
    cout << "body"<<_body.size() << ":";
    for (auto const &item : _body) 
    {
        cout << "("<< item.x << "," << item.y << ")->";
    }
    cout << "end" << endl;
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