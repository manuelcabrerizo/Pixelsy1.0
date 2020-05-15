#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include "GameState.h"
#include <vector>

class GameStateMachine{

private:
    std::vector<GameState*> gameStates;
public:
    void PushState(GameState* statePointer);
    void ChangeState(GameState* statePointer);
    void PopState();
    void Update(float deltaTime, SDL_Event event);
    void Render();
    std::vector<GameState*>& GetGameStates();
};

#endif