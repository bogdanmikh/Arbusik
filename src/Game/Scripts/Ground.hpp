#pragma once

#include "Renderer/Shader.hpp"
#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"

class Ground: public GameObject {
public:
    Ground(Shader* shader);
    void update(double deltaTime) override;
};