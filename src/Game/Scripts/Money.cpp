#include "Money.hpp"
#include "Application/Application.hpp"

Money::Money(Shader* shader, Player* player) 
    : Sprite("../resources/textures/Mushroom.png", shader)
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
            player->getMinY() < getMinY() && getMinY() - player->getMinY() > 0.1f ? -moveSpeed : player->getMinY() > getMinY() && player->getMinY() - getMinY() > 0.1f ? moveSpeed : 0,
            0.0
        );
    }
    draw();
}