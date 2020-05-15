#include "MenuState.h"
#include <iostream>
#include "PlayState.h"
#include "Game.h"

const std::string MenuState::menuId = "MENU";

MenuState::MenuState():
buttonUno(64 * 8, 32 * 8, MenuToPlay),
buttonDos(64 * 8, 55 * 8, ExitFromMenu)
{
    
}

void MenuState::Update(float deltaTime, SDL_Event event){

if(event.type == SDL_MOUSEBUTTONDOWN){
    if(event.button.button == SDL_BUTTON_LEFT){
      mouseButtonStates[LEFT] = true;
    }
    if(event.button.button == SDL_BUTTON_MIDDLE){
      mouseButtonStates[MIDDLE] = true;
    }
    if(event.button.button == SDL_BUTTON_RIGHT){
      mouseButtonStates[RIGHT] = true;
    }
  }
  if(event.type == SDL_MOUSEBUTTONUP){
    if(event.button.button == SDL_BUTTON_LEFT){
      mouseButtonStates[LEFT] = false;
    }
    if(event.button.button == SDL_BUTTON_MIDDLE){
      mouseButtonStates[MIDDLE] = false;
    }
    if(event.button.button == SDL_BUTTON_RIGHT){
      mouseButtonStates[RIGHT] = false;
    }
  }

  if(event.type == SDL_MOUSEMOTION){
    mousePosition.x = event.motion.x;
    mousePosition.y = event.motion.y;
  }

    buttonUno.Update(GetMousePosition(), GetMouseButtonStates(LEFT));
    buttonDos.Update(GetMousePosition(), GetMouseButtonStates(LEFT));
}
void MenuState::Render(){
    buttonUno.Draw();
    buttonDos.Draw();
    
}
bool MenuState::OnEnter(){
    std::cout << "entering MenuState\n";
    for(int i = 0; i < 3; i++){
        mouseButtonStates.push_back(false);
    }
    buttonUno.Init("assets/PlayButton.png");
    buttonDos.Init("assets/ExitButton.png");
    

    return true;
}
bool MenuState::OnExit(){
    std::cout << "exiting MenuState\n";
    return true;
}

bool MenuState::GetMouseButtonStates(int buttonNumber){
  return this->mouseButtonStates[buttonNumber];
}


void MenuState::MenuToPlay(){
    std::cout << "Play Button clicked\n";
    Game::Instance()->gameStateMachine->ChangeState(new PlayState());
}
void MenuState::ExitFromMenu(){
    std::cout << "Exit Button clicked\n";
    Game::Instance()->isRunning = false;
}
