#pragma once

#include <glm/glm.hpp>
#include "Key.hpp"

class Window{
public:
    Window(const char* name, double resolution_x, double resolution_y);
    ~Window();
    bool shouldClose();
    glm::vec2 getCursorPos();
    glm::vec2 getSize();
    double getTime();
    bool isKeyPressed(Key key);
    void setShouldClose();
    void swapBuffers();
    void pollEvents();
private:
    void* handle;
};