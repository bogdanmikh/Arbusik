#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Scripts/Player.hpp"

class GameOverLabel: public GameObject, public Sprite {
public:
    GameOverLabel(Shader* shader, Player* player);
    void update(double deltaTime) override;
private:
    double labelTime;
};