#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"
#include "Constants.h"
#include "TileMap.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"

class PlayState : public GameState{
private:
    static const std::string playId;
    Player player;
    Enemy enemy;
    Enemy enemy2;
    Enemy enemy3;
    TileMap map;
    TileMap layerUno;
    TileMap arboles;
    TileMap arbolesBase;
    std::vector<std::string>mapData;
    TextureManager snow;
    std::vector<std::string> tileMap;
    std::vector<Hechizo*>fireBalls;
public:
    PlayState();
    virtual void Update(float deltaTime, SDL_Event event);
    virtual void Render();
    virtual bool OnEnter();
    virtual bool OnExit();
    virtual std::string GetStateId() const {return playId;}
    void InitSnow(const char* filePath);
    void DrawSnow(Player* player);
};

#endif