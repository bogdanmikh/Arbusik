#include "Game/Scripts/Enemy.hpp"
#include "Application/Application.hpp"
#include "Game/Core/CollisionDetector.hpp"

Enemy::Enemy(Shader* shader, Player* player_clone) 
    : GameObject("../resources/textures/Enemy.png", shader){
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
    player = player_clone;
}

void Enemy::update(double deltaTime) {
    isGrounded = false;
    verticalForce += gravity * deltaTime;
    float horizontalSpeed = deltaTime * moveSpeed;
    float verticalSpeed = deltaTime * verticalForce;
    deltaDistance_x = player->getMinX();

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

    if((player->getMinX() - getMinX() < 0.01f || getMinX() - player->getMinX() < 0.01f) && getMinX() < player->getMinX() && isGrounded){
        translate(horizontalSpeed * 0.5f, 0.f, 0.f);
    } else if((player->getMinX() - getMinX() < 0.01f || getMinX() - player->getMinX() < 0.01f) && isGrounded && getMinX() > player->getMinX()){
        translate(-horizontalSpeed * 0.5f, 0.f, 0.f);
    }

    if(deltaDistance_y - oneSecondDistanceCount_y > 0 && player->getMinY() < 2.f && isGrounded){
        verticalForce = jumpForce;
    }

    oneSecondDistanceCount_x = deltaDistance_x;
    draw();
}