#include "GameObject.hpp"

GameObject::GameObject(std::string texturePath, Shader* shader) 
    : isCollision(false)
    , Sprite(texturePath, shader) {}

void GameObject::update(double deltaTime) {}