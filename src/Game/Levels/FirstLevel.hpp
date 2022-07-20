#pragma once

#include "Game/Level.hpp"

#include "Game/Core/Camera.hpp"
#include "Renderer/Shader.hpp"

class FirstLevel: public Level {
public:
    ~FirstLevel();
    void start(World* world, Camera* camera) override;
private:
    Shader* shader;
};