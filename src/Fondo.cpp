#include "Fondo.h"
#include "Game.h"

void Fondo::InitImage(const char* filePath){
    SDL_Surface* tempSurface = IMG_Load(filePath);
    texture = SDL_CreateTextureFromSurface(Game::Instance()->renderer, tempSurface);
    SDL_FreeSurface(tempSurface); 
}
void Fondo::DrawImage(){

    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    sourceRectangle.w = 160; 
    sourceRectangle.h = 120;

    destinationRectangle.x = 0;
    destinationRectangle.y = 0;
    destinationRectangle.w = 160 * 8;
    destinationRectangle.h = 120 * 6;

    SDL_RenderCopy(Game::renderer, texture,
    &sourceRectangle, &destinationRectangle);
}

