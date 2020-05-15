#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameState.h"
#include "MenuButton.h"
#include <vector>
#include "GameStateMachine.h"


enum mouse_buttons{
  LEFT = 0,
  MIDDLE = 1,
  RIGHT = 2
};


class MenuState : public GameState{
private:
    static const std::string menuId;
    glm::vec2 mousePosition;
    MenuButton buttonUno;
    MenuButton buttonDos;
    std::vector<bool> mouseButtonStates;
    static void MenuToPlay();
    static void ExitFromMenu();

public:
    MenuState();
    virtual void Update(float deltaTime, SDL_Event event);
    virtual void Render();
    virtual bool OnEnter();
    virtual bool OnExit();
    virtual std::string GetStateId() const {return menuId;}
    bool GetMouseButtonStates(int buttonNumber);
    glm::vec2* GetMousePosition(){return &mousePosition;}

};

#endif