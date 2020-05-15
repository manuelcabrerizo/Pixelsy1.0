#include "PlayState.h"
#include <iostream>
#include "Game.h"

const std::string PlayState::playId = "PLAY";

PlayState::PlayState():
player(1800, 860, 0, 0, 16, 16, SCALE),
enemy(36*16*SCALE, 30*16*SCALE, 0, 0, 16, 16, SCALE, 80),
enemy2(25*16*SCALE, 30*16*SCALE, 0, 0, 16, 16, SCALE, 80),
enemy3(25*16*SCALE, 34*16*SCALE, 0, 0, 16, 16, SCALE, 80)
{

}

void PlayState::Update(float deltaTime, SDL_Event event){

    player.InputManager();


    player.Update(deltaTime, &map, &arbolesBase);

    if(enemy.GetLife() > 0){
        enemy.Update(deltaTime, &player, &map);
        enemy.EnemyGetsShoot();
        player.colider.IsColiding(&enemy.colider);
        enemy.GetDangerZoneIzq()->IsColiding(&player.colider);
        enemy.GetDangerZoneDer()->IsColiding(&player.colider);
        enemy.GetDangerZoneUp()->IsColiding(&player.colider);
        enemy.GetDangerZoneDown()->IsColiding(&player.colider);
        enemy.GetDangerZoneUpIzq()->IsColiding(&player.colider);
        enemy.GetDangerZoneUpDer()->IsColiding(&player.colider);
        enemy.GetDangerZoneDownIzq()->IsColiding(&player.colider);
        enemy.GetDangerZoneDownDer()->IsColiding(&player.colider);

    }else{
        player.colider.SetIsTrigger(false);
    }

    if(enemy2.GetLife() > 0){
        enemy2.Update(deltaTime, &player, &map);
        enemy2.EnemyGetsShoot();
        player.colider.IsColiding(&enemy2.colider);
        enemy2.GetDangerZoneIzq()->IsColiding(&player.colider);
        enemy2.GetDangerZoneDer()->IsColiding(&player.colider);
        enemy2.GetDangerZoneUp()->IsColiding(&player.colider);
        enemy2.GetDangerZoneDown()->IsColiding(&player.colider);
        enemy2.GetDangerZoneUpIzq()->IsColiding(&player.colider);
        enemy2.GetDangerZoneUpDer()->IsColiding(&player.colider);
        enemy2.GetDangerZoneDownIzq()->IsColiding(&player.colider);
        enemy2.GetDangerZoneDownDer()->IsColiding(&player.colider);

    }else{
        player.colider.SetIsTrigger(false);
    }

        if(enemy3.GetLife() > 0){
        enemy3.Update(deltaTime, &player, &map);
        enemy3.EnemyGetsShoot();
        player.colider.IsColiding(&enemy3.colider);
        enemy3.GetDangerZoneIzq()->IsColiding(&player.colider);
        enemy3.GetDangerZoneDer()->IsColiding(&player.colider);
        enemy3.GetDangerZoneUp()->IsColiding(&player.colider);
        enemy3.GetDangerZoneDown()->IsColiding(&player.colider);
        enemy3.GetDangerZoneUpIzq()->IsColiding(&player.colider);
        enemy3.GetDangerZoneUpDer()->IsColiding(&player.colider);
        enemy3.GetDangerZoneDownIzq()->IsColiding(&player.colider);
        enemy3.GetDangerZoneDownDer()->IsColiding(&player.colider);

    }else{
        player.colider.SetIsTrigger(false);;
    }
    enemy.coliderUno.IsColiding(&fireBalls[0]->colider);
    enemy.coliderDos.IsColiding(&fireBalls[1]->colider);
    enemy.coliderTres.IsColiding(&fireBalls[2]->colider);
    enemy.coliderCuatro.IsColiding(&fireBalls[3]->colider);

    enemy2.coliderUno.IsColiding(&fireBalls[0]->colider);
    enemy2.coliderDos.IsColiding(&fireBalls[1]->colider);
    enemy2.coliderTres.IsColiding(&fireBalls[2]->colider);
    enemy2.coliderCuatro.IsColiding(&fireBalls[3]->colider);

    enemy3.coliderUno.IsColiding(&fireBalls[0]->colider);
    enemy3.coliderDos.IsColiding(&fireBalls[1]->colider);
    enemy3.coliderTres.IsColiding(&fireBalls[2]->colider);
    enemy3.coliderCuatro.IsColiding(&fireBalls[3]->colider);

    map.Update(player.GetPlayerPosition()); 
    layerUno.Update(player.GetPlayerPosition());
    arboles.Update(player.GetPlayerPosition());
    arbolesBase.Update(player.GetPlayerPosition());


}

void PlayState::Render(){
    map.Render();
    arbolesBase.Render();
    player.Render();
    enemy.Render();
    enemy2.Render();
    enemy3.Render();
    arboles.Render();
    layerUno.Render();

  DrawSnow(&player);
}

bool PlayState::OnEnter(){
    std::cout << "entering PlayState\n";
    player.Draw("assets/MagoAnimations.png");
    enemy.Draw("assets/MonstroAnimationsFull.png");
    enemy2.Draw("assets/MonstroAnimationsFull.png");
    enemy3.Draw("assets/MonstroAnimationsFull.png");
    map.Initiallize("piso.map", "assets/layerUno.png");
    layerUno.Initiallize("paredes.map", "assets/layerUno.png");
    arboles.Initiallize("arboles.map", "assets/alrboltilesetl.png");
    arbolesBase.Initiallize("arbolesBase.map", "assets/alrboltilesetl.png");
    InitSnow("assets/snow-Sheet.png");
    fireBalls = player.GetFireBall();
    return true;
}

bool PlayState::OnExit(){
    std::cout << "exiting PlayState\n";
    return true;
}

void PlayState::InitSnow(const char* filePath){
    SDL_Surface* tempSurface = IMG_Load(filePath);
    snow.texture = SDL_CreateTextureFromSurface(Game::Instance()->renderer, tempSurface);
    SDL_FreeSurface(tempSurface); 
}
void PlayState::DrawSnow(Player* player){

   int OffsetX = WINDOW_WIDTH/2 - player->GetPlayerPosition().x;
   int OffsetY = WINDOW_HEIGHT/2 - player->GetPlayerPosition().y;


  snow.currentFrame = 1280 * int(((SDL_GetTicks() / 100) % 5));

    snow.sourceRectangle.x = snow.currentFrame;
    snow.sourceRectangle.y = 0;
    snow.sourceRectangle.w = 1280; 
    snow.sourceRectangle.h = 960;

    snow.destinationRectangle.x = 0 + OffsetX;
    snow.destinationRectangle.y = 0 + OffsetY;
    snow.destinationRectangle.w = 1280 * SCALE;
    snow.destinationRectangle.h = 960 * SCALE;

    SDL_RenderCopy(Game::renderer, snow.texture,
    &snow.sourceRectangle, &snow.destinationRectangle);
}

