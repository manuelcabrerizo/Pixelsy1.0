#include "GameStateMachine.h"
#include <iostream>


void GameStateMachine::PushState(GameState* statePointer){
    gameStates.push_back(statePointer);
    gameStates.back()->OnEnter();
}
void GameStateMachine::ChangeState(GameState* statePointer){
    if(!gameStates.empty()){
        if(gameStates.back()->GetStateId() == statePointer->GetStateId()){
            return; // do nothing
        }
        if(gameStates.back()->OnExit()){
            delete gameStates.back();
            gameStates.pop_back();
        }
        gameStates.push_back(statePointer);
        gameStates.back()->OnEnter();
    }
}
void GameStateMachine::PopState(){
    if(!gameStates.empty()){
        if(gameStates.back()->OnExit()){
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
}

void GameStateMachine::Update(float deltaTime, SDL_Event event){
    if(!gameStates.empty()){
        gameStates.back()->Update(deltaTime, event);
    }
}
void GameStateMachine::Render(){
    if(!gameStates.empty()){
        gameStates.back()->Render();
    }
}
std::vector<GameState*>& GameStateMachine::GetGameStates(){
    return this->gameStates;
}