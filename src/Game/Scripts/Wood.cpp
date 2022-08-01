#include "Wood.hpp"

Wood::Wood(Shader* shader)
    : Sprite("../resources/textures/Wood.png", shader) {
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
}

void Wood::update(double deltaTime) {
    draw();
}