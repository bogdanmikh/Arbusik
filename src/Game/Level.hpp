#pragma once

#include "World.hpp"
#include "Game/Core/Camera.hpp"
#include <vector>

class Level {
public:
    static std::vector<Level> levels;   
    virtual ~Level() = default;
    virtual void start(World* world, Camera* camera) = 0;
}