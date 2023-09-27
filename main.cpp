#include <iostream>
#include <unistd.h>
#include "game.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "SDL2 test" << endl;

    Game game;

    game.run();
    int a;
    cin>> a;
    return 0;
}
