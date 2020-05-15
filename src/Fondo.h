#ifndef FONDO_H
#define FONDO_H
#include "../SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
class Fondo{

private: 
    SDL_Texture* texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
public:

    void InitImage(const char* filePath);
    void DrawImage();

};

#endif