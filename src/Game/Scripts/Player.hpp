#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Core/Camera.hpp"

class Player: public GameObject, public Sprite {
public:
    int money = 0;
    int maxMoney = 0;
    Player(Shader* shader, Camera* camera);
    void update(double deltaTime) override;
    void showGameOver();
    void jump(float force);
    
    bool time_freze;
    bool isInvincible;
    float time;
private:
    bool isPlaying;
    bool isGrounded;
    float verticalForce;
    float gravity = -9.8f;
    float jumpForce = 6.f;
    float moveSpeed = 3.f;
    Camera *camera;
};