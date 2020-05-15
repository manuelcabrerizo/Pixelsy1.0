#include <iostream>
#include "./SDL2/SDL.h"
#include "./Game.h"
#include "Constants.h"
#define sizeArray(X) sizeof(X)/sizeof(X[0])

float DeltaTime = 0;
unsigned int LastTime = SDL_GetTicks();
int HZ = 60;
float TargetFramesMS = (1.0f/(float)HZ) * 1000.0f; //0.016

int main (int argc, char* args[]){

  Game::Instance()->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

  while (Game::Instance()->IsRunning()) {

    Game::Instance()->Update(DeltaTime);
    Game::Instance()->Render();

    unsigned int CurrentTime = SDL_GetTicks();
    float CurrentMSFrame = (float)CurrentTime - (float)LastTime;
    
    if(CurrentMSFrame < TargetFramesMS)
    {
      float MS = TargetFramesMS - CurrentMSFrame;
      if(MS > 0)
      {
        SDL_Delay(MS);
      }
    }

    CurrentTime = SDL_GetTicks();
    DeltaTime = ((float)CurrentTime - (float)LastTime) / 1000.0f;

    LastTime = CurrentTime;
  }
  Game::Instance()->Destroy();
  return 0;
}
