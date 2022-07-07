#include "Window.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Window::Window(const char* name, double resolution_x, double resolution_y) {
    if(glfwInit() != GLFW_TRUE) {
        std::cout << "GLFW initialization failed\n";
        return;
    }
    GLFWwindow* window = glfwCreateWindow(resolution_x, resolution_y, name, NULL, NULL);
    if (!window) {
        std::cout << "GLFW window creation failed\n";
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
    }
    this->handle = window;
} 

Window::~Window() {
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose((GLFWwindow*) handle);
}

glm::vec2 Window::getCursorPos() {
    double x, y;
    glfwGetCursorPos((GLFWwindow*) handle, &x, &y);
    return { x, y };
}

glm::vec2 Window::getSize() {
    int x, y;
    glfwGetWindowSize((GLFWwindow*) handle,  &x, &y);
    return { x, y };
}

double Window::getTime() {
    return glfwGetTime();
}

bool Window::isKeyPressed(Key key) {
    return glfwGetKey((GLFWwindow*) handle, (int) key) == GLFW_PRESS;
}

void Window::setShouldClose() {
    glfwSetWindowShouldClose((GLFWwindow*) handle, true);
}

void Window::swapBuffers() {
    glfwSwapBuffers((GLFWwindow*) handle);
}

void Window::pollEvents() {
    glfwPollEvents();
}