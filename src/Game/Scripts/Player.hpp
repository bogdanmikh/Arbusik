#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Core/Camera.hpp"

class Player: public GameObject {
public:
    int money = 0;
    int maxMoney = 0;
    Player(Shader* shader, Camera* camera);
    void update(double deltaTime) override;
    void showGameOver();
private:
    bool isPlaying;
    float verticalForce;
    bool isGrounded;
    float gravity = -9.8f;
    float jumpForce = 6.f;
    float moveSpeed = 3.f;
    Camera *camera;
};