#pragma once 

#include "Renderer/Shader.hpp"
#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Scripts/Player.hpp"

class Door: public GameObject {
public:
    Door(Shader* shader, Player* player);
    void update(double deltaTime) override;
private:
    Player* player;
};