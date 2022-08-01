#include "Spring.hpp"
#include <iostream>

Spring::Spring(Shader* shader, Player* player, std::string path) 
    : GameObject(path, shader){
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
    this->player = player;
}

void Spring::update(double deltaTime) {
    if(distanceTo(player) < 0.1f) {
        player->translate(0, abs(player->getMinY()) * 10.f, 0.f);
    }
    draw();
}