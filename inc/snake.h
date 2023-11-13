#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <vector>
#include "SDL.h"
#include "renderer.h"

class Snake
{
public:
    enum class Direction { kUp, kDown, kLeft, kRight };
    Snake(int x, int y, int map_w, int map_h);
    Snake(int x, int y);
    Snake(){};
    int Update(SDL_Point &food);
    void SetDir(Snake::Direction dir);
    void Show(void);
    void SetMap(int map_w, int map_h);
    void OnBody(SDL_Point &p);
    bool IsOnBody(SDL_Point &p);
    bool IsAlive(void);

private:
    std::vector<SDL_Point> _body;
    int _head_x, _head_y;
    int _map_w, _map_h;
    int _food_cnt;
    Direction _dir = Direction::kUp;
    bool alive; 
    SDL_Point _food;
    Renderer *render;
};


#endif /*__SNAKE_H__*/