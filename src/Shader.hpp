#include "vec2.hpp"
#include <iostream>
#include <glad/glad.h>
#include <fstream>
#include <sstream>

class Shader {
public:
    Shader(std::string v_f, std::string f_f);
    ~Shader();
    void use();
    void setFloat(const std::string &name, float value);
    void setVec2(const std::string &name, const Vector2 &value);

private:
    int program;
    void checkCompileErrors(GLuint shader, std::string type);
};