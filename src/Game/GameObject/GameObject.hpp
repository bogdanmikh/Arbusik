#pragma once

class GameObject {
public:
    GameObject();
    virtual ~GameObject() = default;
    virtual void update(double deltaTime);
    bool isCollision;
};