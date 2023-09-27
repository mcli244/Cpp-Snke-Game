#include "map.h"
#include <cmath>

Map::Map(int width, int height)
{
    _width = width;
    _height = height;
}

SDL_Point Map::CreatFood(void)
{
    SDL_Point food;

    food.x = fmod(0, _width);
    food.y = fmod(0, _height);

    return food;
}


