#include "./Game.h"
#include <iostream>
#include "ColiderComponent.h"

//#include "TileMap.h"

SDL_Renderer* Game::renderer;
Game* Game::instance;
Game* Game::Instance(){
  if(instance == 0){
    instance = new Game();
    return instance;
  }
  return instance;
}

Game::Game()
{
  this->isRunning = false;
}

void Game::Initialize(int width, int height){
  //here we are goin to initialize sdl and also
  //all the entitys and component of our game.
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cerr << "Error Initializing SDL\n";
    return;
  }
  this->window = SDL_CreateWindow("Project-01", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
  if(!this->window){
    std::cerr << "Error Creating the window\n";
    return;
  }
  renderer = SDL_CreateRenderer(this->window, -1, 0);
  
  if(!renderer){
    std::cerr << "Error Creating the renderer\n";
    return;
  }

  gameStateMachine = new GameStateMachine();
  gameStateMachine->PushState(new MenuState());
  
  this->isRunning = true;
  return;
}

void Game::Update(float deltaTime){

  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
      this->isRunning = false;
      break;
  case SDL_KEYDOWN:
      if(event.key.keysym.sym == SDLK_ESCAPE){
          this->isRunning = false;
      }
  default:
      break;
  }
  gameStateMachine->Update(deltaTime, event);

}

void Game::Render(){

  SDL_SetRenderDrawColor(renderer ,255, 255, 255, 255);
  SDL_RenderClear(renderer);

  gameStateMachine->Render();

  SDL_RenderPresent(renderer);

}

void Game::Destroy(){
  for(int i = 0; i < gameStateMachine->GetGameStates().size(); i++){
    gameStateMachine->PopState();
    std::cout << "se elimino el gameState\n";
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool Game::IsRunning(){
  return this-> isRunning;
}



