#include <iostream>
#include "vec2.hpp"
#include <GLFW/glfw3.h>

class Window{
public:
    Window(std::string name, double resolution_x, double resolution_y);
    GLFWwindow* getWindow();
private:
    GLFWwindow* window;
};