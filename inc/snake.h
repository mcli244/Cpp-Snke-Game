#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <vector>
#include "SDL.h"
#include "map.h"

class Snake
{
public:
    enum class Direction { kUp, kDown, kLeft, kRight };
    Snake(int x, int y, Map *map);
    int Update(void);
    void SetDir(Snake::Direction dir);
    void Show(void);
    void OnBody(SDL_Point &p);
    bool IsOnBody(SDL_Point &p);
    bool IsAlive(void);
    void SetSpeed(int speed);

private:
    void PlaceFood(void);
    std::vector<SDL_Point> _body;
    int _head_x, _head_y;
    int _food_cnt;
    Direction _dir = Direction::kUp;
    bool alive; 
    SDL_Point _food;
    Map *_map;
    int _speed;
    uint32_t _tick;
};


#endif /*__SNAKE_H__*/