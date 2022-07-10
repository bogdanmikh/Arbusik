#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Direction.hpp"

class CollisionDetector {
public:
    static bool moveAcceptable(GameObject* entity, Direction direction, float amount);
};