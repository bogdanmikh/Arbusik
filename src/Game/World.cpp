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
