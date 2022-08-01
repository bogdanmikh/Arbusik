#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Scripts/Player.hpp"

class Spring : public GameObject{
public:
    Spring(Shader* shader, Player* player, std::string path);
    void update(double deltaTime) override;
private:
    Player *player;
};