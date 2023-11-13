#ifndef __GAME_H__
#define __GAME_H__

#include "snake.h"
#include "map.h"
#include "input.h"

class Game
{
public:
    Game();
    ~Game();
    void run(void);
    void CtreatFood(Snake *_snaker, Map *_map);
private:
    SDL_Point food;
    Snake *snaker;
    Map *map;
    Input *input;
};
#endif /*__GAME_H__*/