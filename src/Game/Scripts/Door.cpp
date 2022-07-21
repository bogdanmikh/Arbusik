#include "Door.hpp"

Door::Door(Shader* shader)
    : GameObject("../resources/textures/Door.png", shader) {
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
}

void Door::update(double deltaTime) {
    draw();
}