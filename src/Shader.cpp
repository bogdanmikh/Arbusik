#include "Shader.hpp"

Shader::Shader(std::string v_f, std::string f_f){
    std::fstream vertex_shader_file;
    vertex_shader_file.open(v_f);
    if (!vertex_shader_file.is_open()){
        std::cout << "Cannot open vertex shader file" << std::endl;
        return;
    }

    std::stringstream vertexSnaderStream;
    vertexSnaderStream << vertex_shader_file.rdbuf();
    vertex_shader_file.close();
    std::string vertexShaderCodeString = vertexSnaderStream.str();
    const char* vertex_shader_text = vertexShaderCodeString.c_str();

    std::fstream fragment_shader_file;
    fragment_shader_file.open(f_f);
    if (!fragment_shader_file.is_open()){
        std::cout << "Cannot open fragment shader file" << std::endl;
        return;
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

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    checkCompileErrors(program, "PROGRAM");
    glDeleteShader(fragmentShader);
    glDeleteShader(vertex_shader);
}

Shader::~Shader() {
    glDeleteProgram(program);
}

void Shader::use() {
    glUseProgram(program);
}

void Shader::setFloat(const std::string &name, float value) {
    uint32_t location = glGetUniformLocation(program, name.c_str());
    glUniform1f(location, value);
}

void Shader::setVec2(const std::string &name, const Vector2 &value) {
    uint32_t location = glGetUniformLocation(program, name.c_str());
    glUniform2f(location, value.x, value.y);
}

void Shader::checkCompileErrors(GLuint shader, std::string type) {
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