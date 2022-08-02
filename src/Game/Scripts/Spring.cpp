#include "Spring.hpp"
#include <iostream>

Spring::Spring(Shader* shader, Player* player) 
    : Sprite("../resources/textures/Spring1.png", shader) {
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
    this->player = player;
}

void Spring::update(double deltaTime) {
    if(distanceTo(player) < 0.1f) {
        player->jump(15.f);
    }
    draw();
}