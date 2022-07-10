#include "Ground.hpp"

Ground::Ground(Shader* shader)
    : GameObject("../../resources/textures/Earth.png", shader) {
    isCollision = true;
}

void Ground::update(double deltaTime) {
    draw();
}