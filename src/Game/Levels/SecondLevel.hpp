#pragma once

#include "Game/Level.hpp"

#include "Game/Core/Camera.hpp"
#include "Renderer/Shader.hpp"

class SecondLevel : public Level {
public:
    ~SecondLevel();
    void start(World* world, Camera* camera) override;
private:
    Shader* shader;
};