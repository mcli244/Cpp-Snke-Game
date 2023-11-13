#ifndef __GAME_H__
#define __GAME_H__

#include "snake.h"
#include "input.h"

class Game
{
public:
    Game();
    ~Game();
    void run(void);
private:
    Snake *snaker;
    Input *input;
    Map *map;
};
#endif /*__GAME_H__*/