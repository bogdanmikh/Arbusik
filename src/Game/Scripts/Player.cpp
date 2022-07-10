#include "Player.hpp"

Player::Player(Shader* shader) {
    sprite = new Sprite("../../resources/textures/Human.png", shader);
    sprite->setPosition(0.f, 1.f, 0.f);
}

Player::~Player() {
    delete sprite;
}

void Player::update(double deltaTime) {
    sprite->draw();
}