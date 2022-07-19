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

    if( getMinX() < player->getMinX() && player->getMinX() - getMinX() < distance ){
        if(CollisionDetector::moveAcceptable(this, Direction::RIGHT, horizontalSpeed)) {
            translate(horizontalSpeed, 0.f, 0.f);
        }
    } else if(getMinX() > player->getMinX() && getMinX() - player->getMinX() < distance){
        if(CollisionDetector::moveAcceptable(this, Direction::LEFT, -horizontalSpeed)) {
            translate(-horizontalSpeed, 0.f, 0.f);
        }
    }

    if( player->getMinY() > getMinY() && isGrounded && (getMinX() > player->getMinX() && getMinX() - player->getMinX() < distance  || getMinX() < player->getMinX() && player->getMinX() - getMinX() < distance)){
        verticalForce = jumpForce;
        std::cout << "1: " << player->getMinX() - getMinX() << "2: " <<  getMinX() - player->getMinX() << "\n";

    }
    draw();
}