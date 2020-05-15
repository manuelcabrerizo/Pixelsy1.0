#include "MenuButton.h"
#include "./Game.h"
#include <iostream>

MenuButton::MenuButton(int x, int y, void (*callback) ()):
callback(callback)
{
    this->position.x = x;
    this->position.y = y;

}

void MenuButton::Init(const char* filePath){
    SDL_Surface* tempSurface = IMG_Load(filePath);
    image.texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface); 

    image.currentFrame = 0;
    image.currentRow = 0;
}

void MenuButton::Draw(){

    image.sourceRectangle.x = image.currentFrame;
    image.sourceRectangle.y = image.currentRow;
    image.sourceRectangle.w = 32; 
    image.sourceRectangle.h = 16;

    image.destinationRectangle.x = position.x;
    image.destinationRectangle.y = position.y;
    image.destinationRectangle.w = image.sourceRectangle.w * 8;
    image.destinationRectangle.h = image.sourceRectangle.h * 8;

    SDL_RenderCopy(Game::renderer, image.texture,
    &image.sourceRectangle, &image.destinationRectangle);
}

void MenuButton::Update(glm::vec2* mousePosition, bool buttonState){
    glm::vec2* ptrMousePosition = mousePosition;

    if(ptrMousePosition->x < (position.x + 32 * 8)
    && ptrMousePosition->x > position.x
    && ptrMousePosition->y < (position.y + 16 * 8)
    && ptrMousePosition->y > position.y){
        
        if(buttonState && released){
            image.currentFrame = CLICKED;
            callback();
            released = false;
        }else if(!buttonState){
            released = true;
            image.currentFrame = MOUSE_OVER;
        }

    }else{
            image.currentFrame = MOUSE_OUT;
    }

}
