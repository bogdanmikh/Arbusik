#pragma once

#include "GameObject/GameObject.hpp"

#include <vector>

class World {
public:
    void update(double deltaTime);
    void addActor(GameObject* actor);
    void deleteActor(GameObject* actor);
    std::vector<GameObject*>& getAllActors();
private:
    std::vector<GameObject*> gameObjects;
};