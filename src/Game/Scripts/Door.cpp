#include "Door.hpp"
#include "Application/Application.hpp"
#include "Game/LevelManager/LevelManager.hpp"

Door::Door(Shader* shader, Player* player)
    : Sprite("../resources/textures/Door.png", shader) {
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
    this->player = player;
}

void Door::update(double deltaTime) {
    if(player->maxMoney == player->money && distanceTo(player) < 0.2f){
        increaseLevelNumber();
        Application::getInstance()->loadLevel(createCurrentLevel());
        return;
    }
    draw();
}
