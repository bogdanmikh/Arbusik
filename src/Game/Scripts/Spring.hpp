#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Scripts/Player.hpp"

class Spring : public GameObject, public Sprite {
public:
    Spring(Shader* shader, Player* player);
    void update(double deltaTime) override;
private:
    Player *player;
};