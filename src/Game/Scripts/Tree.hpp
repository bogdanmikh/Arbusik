#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"

class Tree: public GameObject, public Sprite {
public:
    Tree(Shader* shader);
    void update(double deltaTime) override;
};