#include "CollisionDetector.hpp"
#include "Application/Application.hpp"

bool CollisionDetector::moveAcceptable(
    GameObject* entity, 
    Direction direction, 
    float amount
) {
    // if (direction == Direction::UP && entity->getMinY() < worldBounds.getMinY()) {
    //     return false;
    // } else if (direction == Direction::LEFT && entity->getMinX() < worldBounds.getMinX()) {
    //     return false;
    // } else if (direction == Direction::DOWN && entity->getMaxY() > worldBounds.getMaxY()) {
    //     return false;
    // } else if (direction == Direction::RIGHT && entity->getMaxX() > worldBounds.getMaxX()) {
    //     return false;
    // }

    auto collisionList = Application::getInstance()->world.getAllCollisions();
    for (auto& collision: collisionList) {
        if (collision == entity) { continue; }
        if (direction == Direction::UP
                && (entity->getMinY() + amount < collision->getMaxY()
                && entity->getMaxY() > collision->getMinY()
            )
                && (entity->getMaxX() > collision->getMinX()
                && entity->getMinX() < collision->getMaxX()
            )
        ) {
            return false;
        }
        if (direction == Direction::DOWN
                && (entity->getMinY() < collision->getMaxY()
                && entity->getMaxY() + amount > collision->getMinY()
            )
                && (entity->getMaxX() > collision->getMinX()
                && entity->getMinX() < collision->getMaxX()
            )
        ) {
            return false;
        }
        if (direction == Direction::LEFT
                && (entity->getMaxX() > collision->getMinX()
                && entity->getMinX() - amount < collision->getMaxX()
            )
                && (entity->getMinY() < collision->getMaxY()
                && entity->getMaxY() > collision->getMinY()
            )
        ) {
            return false;
        }
        if (direction == Direction::RIGHT
                && (entity->getMaxX() + amount > collision->getMinX()
                && entity->getMinX() < collision->getMaxX()
            )
                && (entity->getMinY() < collision->getMaxY()
                && entity->getMaxY() > collision->getMinY()
            )
        ) {
            return false;
        }
    }

    return true;
}