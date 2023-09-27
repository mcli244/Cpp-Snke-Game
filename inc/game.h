#ifndef __GAME_H__
#define __GAME_H__

#include "snake.h"
#include "map.h"
#include "input.h"
#include "renderer.h"

class Game
{
public:
    Game();
    ~Game();
    void run(void);
private:
    Snake *snaker;
    Map *map;
    Input *input;
    Renderer *render;
};
#endif /*__GAME_H__*/