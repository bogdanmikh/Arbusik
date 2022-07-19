#pragma once

#include "Renderer/Shader.hpp"
#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Scripts/Player.hpp"

class Enemy: public GameObject{
public:
    Enemy(Shader* shader, Player* player_clone);
    void update(double deltaTime) override;
private:
    float   verticalForce;
    bool    isGrounded;
    float   gravity = - 9.8f;
    float   jumpForce = 6.f;
    float   moveSpeed = 1.f;
    Player* player;
    float distance = 2.0f;
};