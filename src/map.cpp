#include "map.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

Map::Map(int width, int height)
{
    _width = width;
    _height = height;
}

SDL_Point Map::CreatFood(void)
{
    SDL_Point food;

    srand (time(0));

    std::cout << "_width:" << _width << std::endl;
    std::cout << "_height:" << _height << std::endl;
    food.x = rand() % _width;
    food.y = rand() % _height;

    return food;
}


