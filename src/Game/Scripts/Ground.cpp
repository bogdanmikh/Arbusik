#include "Ground.hpp"

Ground::Ground(Shader* shader) {
    sprite = new Sprite("../../resources/textures/Earth.png", shader);
    sprite->setPosition(-5.f, 0.f, 0.f);
    sprite->setSize(10.f, 6.f);
}

Ground::~Ground() {
    delete sprite;
}

void Ground::update(double deltaTime) {
    sprite->draw();
}