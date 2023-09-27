#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <vector>
#include "SDL.h"

class Snake
{
public:
    Snake(int x, int y, int map_w, int map_h);
    Snake(int x, int y);
    Snake(){};
    int Update(SDL_Point &food);
    void SetDir(int dir);
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
    int _dir;
    bool alive; 
};


#endif /*__SNAKE_H__*/