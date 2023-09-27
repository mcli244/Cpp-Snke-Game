#include <iostream>
#include <unistd.h>
#include "game.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "Snake Game" << endl;
    cout << "speed++: H\n \
             speed--: L\n" << endl;
    
    cout<< "任意键开始!" << endl;
    int a;
    cin >> a;

    Game game;
    game.run();
    return 0;
}
