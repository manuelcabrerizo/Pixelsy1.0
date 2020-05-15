#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include "./SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
#include "./SDL2/SDL_ttf.h"

class GameStateMachine;
class GameState {
private:

public:
    virtual void Update(float deltaTime, SDL_Event event) = 0;
    virtual void Render() = 0;

    virtual bool OnEnter() = 0;
    virtual bool OnExit() = 0;

    virtual std::string GetStateId() const = 0;
};


#endif