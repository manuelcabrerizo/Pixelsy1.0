#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "TileMap.h"
#include "./SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
#include "./SDL2/SDL_ttf.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"



class Game {
private:

  SDL_Window* window;
  static Game* instance;
public:
  static Game* Instance();
  Game();
  ~Game();
  SDL_Window* GetWindow(){return window;}
  void Initialize(int width, int height);
  void Update(float deltaTime);
  void Render();
  void Destroy();
  bool IsRunning();
  static SDL_Renderer* renderer;
  int ticksLastFrame;
  bool isRunning;
  GameStateMachine* gameStateMachine;

};

#endif
