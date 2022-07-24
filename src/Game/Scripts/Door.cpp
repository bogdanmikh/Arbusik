#include "Door.hpp"
#include "Application/Application.hpp"
#include "Game/Levels/FirstLevel.hpp"

Door::Door(Shader* shader, Player* player)
    : GameObject("../resources/textures/Door.png", shader) {
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
    this->player = player;
}

void Door::update(double deltaTime) {
    if(player->maxMoney == player->money && distanceTo(player) < 0.2f){
        Application::getInstance()->loadLevel(new FirstLevel());
        return;
    }
    draw();
}
