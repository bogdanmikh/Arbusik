#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Scripts/Player.hpp"

class Enemy: public GameObject, public Sprite {
public:
    Enemy(Shader* shader, Player* player);
    void update(double deltaTime) override;
private:
    Player *player;
    float verticalForce;
    bool isGrounded;
    float gravity = -9.8f;
    float jumpForce = 5.f;
    float moveSpeed = 1.5f;
    float distance = 3.0f;
};