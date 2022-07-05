#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>

void checkCompileErrors(GLuint shader, std::string type) {
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
                      << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
                      << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

struct Vector2 {
    double x;
    double y;
};

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
    
    std::fstream vertex_shader_file;
    vertex_shader_file.open("../../vst.glsl");
    if (!vertex_shader_file.is_open()){
        std::cout << "Cannot open vertex shader file" << std::endl;
        return -1;
    }

    std::stringstream vertexSnaderStream;
    vertexSnaderStream << vertex_shader_file.rdbuf();
    vertex_shader_file.close();
    std::string vertexShaderCodeString = vertexSnaderStream.str();
    const char* vertex_shader_text = vertexShaderCodeString.c_str();

    std::fstream fragment_shader_file;
    fragment_shader_file.open("../../fst.glsl");
    if (!fragment_shader_file.is_open()){
        std::cout << "Cannot open fragment shader file" << std::endl;
        return -1;
    }
    std::stringstream fragmentSnaderStream;
    fragmentSnaderStream << fragment_shader_file.rdbuf();
    fragment_shader_file.close();
    std::string fragmentShaderCodeString = fragmentSnaderStream.str();
    const char* fragment_shader_text = fragmentShaderCodeString.c_str();

    int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
    checkCompileErrors(vertex_shader, "VERTEX");

    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, "FRAGMENT");

    int program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    checkCompileErrors(program, "PROGRAM");
    glDeleteShader(fragmentShader);

    uint32_t vpos_location = glGetAttribLocation(program, "aPos");
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(
        vpos_location, 2, GL_FLOAT, GL_FALSE,
        sizeof(float) * 2, (void*) 0 
    );

    glClearColor(1.0f, 0.5f, 0.7f, 1.0f);
    uint32_t time_location = glGetUniformLocation(program, "u_time");
    uint32_t resolution_location = glGetUniformLocation(program, "u_resolution");
    uint32_t mouse_location = glGetUniformLocation(program, "u_mouse");

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

        glUseProgram(program);
        glUniform1f(time_location, glfwGetTime());
        glUniform2f(resolution_location, resolution.x, resolution.y);
        glUniform2f(mouse_location, mousePos.x, resolution.y - mousePos.y);
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
    glDeleteProgram(program);
    glfwTerminate();
}
