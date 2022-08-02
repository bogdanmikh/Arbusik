#include "Tree.hpp"

Tree::Tree(Shader* shader)
    : Sprite("../resources/textures/Wood.png", shader) {
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
}

void Tree::update(double deltaTime) {
    draw();
}