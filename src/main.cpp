#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

int main() {
    if(glfwInit() != GLFW_TRUE) {
        std::cout << "GLFW initialization failed\n";
        return -1;
    }
    std::cout << "Arbusik version 0.0\n";

    GLFWwindow* window;
    window = glfwCreateWindow(640, 480, "OpenGl", NULL, NULL);

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
        0.5f, 0.5f,
        -0.5f, 0.5f,
        -0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, data, GL_STATIC_DRAW);

    const char* vertex_shader_text =
    "#version 330\n"
    "layout (location = 0) in vec2 aPos;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(aPos, 0.0, 1.0);\n"
    "}\n";

    const char* fragment_shader_text =
    "#version 330\n"
    "uniform float u_time;\n"
    "void main()\n"
    "{\n"
    "    gl_FragColor = vec4(abs(sin(u_time * 1.5)), 1.0, 1.0, 1.0);\n"
    "}\n";

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

    glClearColor(0.5f, 0.5f, 0.7f, 1.0f);
    uint32_t time_location = glGetUniformLocation(program, "u_time");

    float time = 0.f;
    while (!glfwWindowShouldClose(window)) {
        time += 0.0001f;
        glClear(GL_COLOR_BUFFER_BIT);
        // ALL HERE

        glUseProgram(program);
        glUniform1f(time_location, time);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete[] data;
    glDeleteProgram(program);
    glfwTerminate();
}
