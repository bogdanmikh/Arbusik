#include "Player.hpp"
#include "Application/Application.hpp"
#include "Game/Core/CollisionDetector.hpp"
#include "Game/Core/Camera.hpp"
#include "Game/Scripts/GameOverLabel.hpp"

Player::Player(Shader* shader, Camera* camera)
    : GameObject("../resources/textures/ball.png", shader)
    , camera(camera)
    , isPlaying(true) {
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
}

void Player::update(double deltaTime) {
    isGrounded = false;
    camera->setPosition(getMaxX(), getMaxY(), 5.f);
    verticalForce += gravity * deltaTime;
    float horizontalSpeed = deltaTime * moveSpeed;
    float verticalSpeed = deltaTime * verticalForce;

    if(std::abs(verticalForce) > 0.1f) {
        if(verticalForce >= 0.f) {
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
        && CollisionDetector::moveAcceptable(this, Direction::LEFT, -horizontalSpeed)) {
        translate(-horizontalSpeed , 0.f, 0.f);
    }
    if(Application::getInstance()->window->isKeyPressed(Key::D)
        && CollisionDetector::moveAcceptable(this, Direction::RIGHT, horizontalSpeed)) {
        translate(horizontalSpeed, 0.f, 0.f);
    }

    draw();
}

void Player::showGameOver() {
    if(isPlaying == false) { return; } 
    Application::getInstance()->world.addActor(new GameOverLabel(shader, this));
    isPlaying = false;
}