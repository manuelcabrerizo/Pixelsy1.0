#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>

enum class TileType
{
    SOLID,
    NO_SOILID
};

struct Tile
{
public:
    SDL_Rect rect;
    TileType type;
};

#endif