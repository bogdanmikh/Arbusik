#pragma once

#include "Renderer/Shader.hpp"
#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"

class Player: public GameObject {
public:
    Player(Shader* shader);
    ~Player();
    void update(double deltaTime) override;
private:
    Sprite* sprite;
};