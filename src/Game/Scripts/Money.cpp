#include "Money.hpp"
#include "Application/Application.hpp"

Money::Money(Shader* shader, Player* player) 
    : Sprite("../resources/textures/Money.png", shader)
    , player(player) {
    player->maxMoney++;
}

void Money::update(double deltaTime) {
    float horizontalSpeed = deltaTime * moveSpeed;
    if(distanceTo(player) < 0.4f) {
        player->money++;
        Application::getInstance()->world.deleteActor(this);
        return;
    } else if(distanceTo(player) < 2.f) {
        float moveSpeed = 1.1 * deltaTime;
        translate(
            player->getMinX() < getMinX() ? -moveSpeed : player->getMinX() > getMinX()? moveSpeed : 0,
            player->getMinY() < getMinY() ? -moveSpeed : player->getMinY() > getMinY() ? moveSpeed : 0,
            0.0
        );
    }
    draw();
}