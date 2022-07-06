#include "Window.hpp"

Window::Window(std::string name, double resolution_x, double resolution_y){
    window = glfwCreateWindow(resolution_x, resolution_y, name.c_str(), NULL, NULL);
    if (!window) {
        std::cout << "GLFW window creation failed\n";
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
} 

GLFWwindow* Window::getWindow(){
    return window;
}