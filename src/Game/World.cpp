#include "World.hpp"

void World::update(double deltaTime) {
    for(auto& gameObject: gameObjects) {
        gameObject->update(deltaTime);
    }
}

void World::addActor(GameObject* actor) {
    gameObjects.push_back(actor);
}

void World::deleteActor(GameObject* actor) {
    gameObjects.erase(find(gameObjects.begin(), gameObjects.end(), actor));
    delete actor;
}

std::vector<GameObject*>& World::getAllActors() {
    return gameObjects;
}

std::vector<GameObject*> World::getAllCollisions() {
    std::vector<GameObject*> result;
 
    for (int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i]->isCollision) {
            result.push_back(gameObjects[i]);
        }
    }
 
    return result;
}
