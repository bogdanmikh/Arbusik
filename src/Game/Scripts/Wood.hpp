#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"

class Wood: public GameObject, public Sprite {
public:
    Wood(Shader* shader);
    void update(double deltaTime) override;
};