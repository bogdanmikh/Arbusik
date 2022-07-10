#pragma once

#include "Renderer/Shader.hpp"
#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"

class Player: public GameObject {
public:
    Player(Shader* shader);
    void update(double deltaTime) override;
private:
    float   verticalForce;
    bool    isGrounded;
    float   gravity = 9.f;
    float   jumpForce = 4.f;
    float   moveSpeed = 1.f;
};