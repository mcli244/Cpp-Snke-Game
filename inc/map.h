#ifndef __MAP_H__
#define __MAP_H__

#include "SDL.h"

class Map
{
public:
    Map(int width, int height);
    SDL_Point CreatFood(void);

private:
    int _width;
    int _height;
};

#endif /*__MAP_H__*/