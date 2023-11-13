#include <iostream>
#include <unistd.h>
#include "game.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "Snake Game" << endl;
    cout<< "**************选择难度**************" << endl;
    cout<< "1. 简单" << endl;
    cout<< "2. 正常" << endl;
    cout<< "3. 困难" << endl;
    cout<< "************************************" << endl;
    int mode;
    GameMode gmode;
    scanf("%d", &mode);

    switch (mode)
    {
    case 1: gmode = GameMode::Easy; break;
    case 2: gmode = GameMode::Normal; break;
    case 3: gmode = GameMode::Hard; break;
    default:
        gmode = GameMode::Normal;
        break;
    }
    Game game(gmode);
    game.run();
    return 0;
}
