#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include "Shader.hpp"
#include "vec2.hpp"

int main() {
    if(glfwInit() != GLFW_TRUE) {
        std::cout << "GLFW initialization failed\n";
        return -1;
    }
    Vector2 resolution = { 640., 480. };
    Vector2 mousePos = { 0., 0. };
    std::cout << "Arbusik version 0.2\n";

    GLFWwindow* window = glfwCreateWindow(resolution.x, resolution.y, "OpenGl", NULL, NULL);

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
    float *data = new float[6] {
        // 0.5f, 0.5f,
        // -0.5f, 0.5f,
        // -0.5f, -0.5f,
        //  0.5f, -0.5f,
        // -0.5f, -0.5f,
        // 0.5f, 0.5f
         1.f, 1.f,
        -1.f, 1.f,
        -1.f, -1.f,
        //  1.f, -1.f,
        // -1.f, -1.f,
        // 1.f, 1.f
    };
    
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, data, GL_STATIC_DRAW);
    
    //begin
    Shader shader("../../vst.glsl","../../fst.glsl");
    //end

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0, 2, GL_FLOAT, GL_FALSE,
        sizeof(float) * 2, (void*) 0 
    );

    glClearColor(1.0f, 0.5f, 0.7f, 1.0f);

    int k = 0;
    bool b_k = true;
    bool b_data;
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        // ALL HERE
        b_k = (k == 6)? false : (k == 0)? true : b_k; 
        k = (b_k)? k++ : k--;  
        data[k] = (data[k] == 1)? data[k] -= 1 : data[k] += 0.05;
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, data, GL_STATIC_DRAW);

        glfwGetCursorPos(window, &mousePos.x, &mousePos.y);

        shader.use();
        shader.setFloat("u_time", glfwGetTime());
        shader.setVec2("u_resolution", { resolution.x, resolution.y });
        shader.setVec2("u_mouse", { mousePos.x, resolution.y - mousePos.y });

        glDrawArrays(GL_TRIANGLES, 0, 6);
        
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_KEY_F) {
           // gl(window, true);
        }
        int w, h;
        glfwGetWindowSize(window, &w, &h);
        glViewport(0, 0, w, h);
        resolution.x = w;
        resolution.y = h;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete[] data;
    glfwTerminate();
}
