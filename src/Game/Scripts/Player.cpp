#include "Player.hpp"
#include "Application/Application.hpp"
#include "Game/Core/CollisionDetector.hpp"

Player::Player(Shader* shader)
    : GameObject("../../resources/textures/Human.png", shader) {
    setPosition(0.f, 1.f, 0.f);
}

void Player::update(double deltaTime) {
    isGrounded = false;

    verticalForce -= gravity * deltaTime;
    float horizontalSpeed = deltaTime * moveSpeed;
    float verticalSpeed = - deltaTime * verticalForce;

    if(std::abs(verticalForce) > 10.f) {
        if(verticalForce > 0.f) {
            if(CollisionDetector::moveAcceptable(this, Direction::UP, verticalSpeed)) {
                translate(0.f, verticalSpeed, 0.f);
            } else {
                verticalForce = 0.f;
            }
        } else {
            if(CollisionDetector::moveAcceptable(this, Direction::DOWN, verticalSpeed)) {
                translate(0.f, verticalSpeed, 0.f);
            } else {
                verticalForce = 0.f;
                isGrounded = true;
            }
        }
    }

    if(Application::getInstance()->window->isKeyPressed(Key::SPACE) && isGrounded) {
        verticalForce = jumpForce;
    }

    if(Application::getInstance()->window->isKeyPressed(Key::A)
        && CollisionDetector::moveAcceptable(this, Direction::RIGHT, horizontalSpeed )) {
        translate(-horizontalSpeed , 0.f, 0.f);
    }
    if(Application::getInstance()->window->isKeyPressed(Key::D)
        && CollisionDetector::moveAcceptable(this, Direction::LEFT, horizontalSpeed )) {
        translate(horizontalSpeed, 0.f, 0.f);
    }

    draw();
}