#include "Money.hpp"
#include "Application/Application.hpp"

Money::Money(Shader* shader, Player* player) 
    : GameObject("../resources/textures/Money.png", shader)
    , player(player) {
    player->maxMoney++;
}

void Money::update(double deltaTime) {
    float horizontalSpeed = deltaTime * moveSpeed;
    if(distanceTo(player) < 0.2f) {
        player->money++;
        Application::getInstance()->world.deleteActor(this);
        return;
    } else if(distanceTo(player) < 1.5f) {
        float moveSpeed = 1.0 * deltaTime;
        translate(
            player->getMinX() < getMinX() ? -moveSpeed : moveSpeed,
            player->getMinY() < getMinY() ? -moveSpeed : moveSpeed,
            0.0
        );
    }
    draw();
}