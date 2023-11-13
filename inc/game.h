#ifndef __GAME_H__
#define __GAME_H__

#include "snake.h"
#include "input.h"

enum class GameMode { Easy, Normal, Hard};
class Game
{
public:
    
    Game();
    Game(GameMode mode);
    ~Game();
    void run(void);
private:
    Snake *snaker;
    Input *input;
    Map *map;
    GameMode _mode = GameMode::Normal;
};
#endif /*__GAME_H__*/