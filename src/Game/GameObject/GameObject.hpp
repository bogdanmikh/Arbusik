#pragma once

#include "Game/Core/Sprite.hpp"

class GameObject: public Sprite {
public:
    GameObject(std::string texturePath, Shader* shader);
    virtual ~GameObject() = default;
    virtual void update(double deltaTime);
    bool isCollision;
};