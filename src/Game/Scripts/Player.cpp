#include "Player.hpp"
#include "Application/Application.hpp"
#include "Game/LevelManager/LevelManager.hpp"
#include "Game/Core/CollisionDetector.hpp"
#include "Game/Core/Camera.hpp"
#include "Game/Scripts/GameOverLabel.hpp"
#include "Game/LevelManager/LevelManager.hpp"

#include <imgui.h>

Player::Player(Shader* shader, Camera* camera)
    : Sprite("../resources/textures/ball.png", shader)
    , camera(camera)
    , isPlaying(true)
    , isInvincible(false) {
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
}

void Player::jump(float force) {
    verticalForce = force;
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

    // Если игрок упал слишком низко (за карту) - перезагрузка уровня
    if (getMinY() < -10.f) {
        Application::getInstance()->loadLevel(createCurrentLevel());
        return;
    }

    if(Application::getInstance()->window->isKeyPressed(Key::SPACE) && isGrounded) {
        jump(jumpForce);
    }

    if(Application::getInstance()->window->isKeyPressed(Key::A)
        && CollisionDetector::moveAcceptable(this, Direction::LEFT, -horizontalSpeed)) {
        translate(-horizontalSpeed , 0.f, 0.f);
    }
    if(Application::getInstance()->window->isKeyPressed(Key::D)
        && CollisionDetector::moveAcceptable(this, Direction::RIGHT, horizontalSpeed)) {
        translate(horizontalSpeed, 0.f, 0.f);
    }

    ImGui::Begin("Player info", nullptr, 0);
    ImGui::Text("Player, x: %f, y: %f", getMinX(), getMinY());
    if(ImGui::Button("RESTART LEVEL", ImVec2(200, 50))) {
        Application::getInstance()->loadLevel(createCurrentLevel());
        ImGui::End();
        return;
    }
    if(ImGui::Button(isInvincible ? "MAKE VUNERABLE" : "MAKE INVINCIBLE", ImVec2(200, 50))) {
        isInvincible = isInvincible == false;
    }
    if(ImGui::Button("SUPER JUMP", ImVec2(200, 50))) {
        jump(15.f);
    }
    ImGui::Text("Money: %d of %d", money, maxMoney);
    if(ImGui::Button("MENU", ImVec2(200, 50))) {
        Application::getInstance()->loadLevel(createMenuLevel());
        ImGui::End();
        return;
    }
    ImGui::End();
    draw();
}

void Player::showGameOver() {
    if(isPlaying == false) { return; } 
    Application::getInstance()->world.addActor(new GameOverLabel(shader, this));
    isPlaying = false;
}