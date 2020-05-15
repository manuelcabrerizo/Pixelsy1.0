#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "TextureManager.h"
#include "glm/glm.hpp"

class MenuButton{

private:
    enum button_state{
        MOUSE_OUT = 0,
        MOUSE_OVER = 32,
        CLICKED = 64
    };
    TextureManager image;
    glm::vec2 position;
    void (*callback) ();
    bool released;


public:

    MenuButton(int x, int y, void (*callback) ());
    void Init(const char* filePath);
    void Draw();
    void Update(glm::vec2* mousePosition, bool buttonState);

};
#endif