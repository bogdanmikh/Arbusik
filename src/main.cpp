#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    if(glfwInit() != GLFW_TRUE) {
        std::cout << "GLFW initialization failed\n";
        return -1;
    }
    std::cout << "Arbusik version 0.0\n";

    GLFWwindow* window;
    window = glfwCreateWindow(1080, 480, "OpenGl", NULL, NULL);

    if (!window) {
        std::cout << "GLFW window creation failed\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }
    float red = 0.0f;
    float green = 0.0f;
    float blue = 0.0f;
    bool r = false;
    bool g = false;
    bool b = false;
    glClearColor(red, green, blue, 1.0f);
    while (!glfwWindowShouldClose(window)) {
        if(r){
            if(red <= 0){
                r = false;
            }
             red -= 0.0002;
        } else{
            if(red >= 1){
                r = true;
            }
            red += 0.0002;
        }
        if(g){
            if(green <= 0){
                g = false;
            }
            green -= 0.00015;
        } else {
            if(green >= 1){
                g = true;
            }
            green += 0.00015;
        }
        if(b){
            if(blue <= 0){
                b = false;
            }
            blue -= 0.0001;
        } else {
            if(blue >= 1){
                b = true;
            }
            blue += 0.0001;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        // ALL HERE

        glClearColor(red, green, blue, 1.0f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
