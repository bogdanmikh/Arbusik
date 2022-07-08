#pragma once

#include <iostream>
#include <glm/glm.hpp>

#include "Renderer/VertexBuffer.hpp"
#include "Renderer/VertexArray.hpp"
#include "Renderer/Texture.hpp"
#include "Renderer/Shader.hpp"

class Sprite {
public:
    Sprite(std::string texturePath, Shader* shader);
    ~Sprite();
    void setPosition(float x, float y, float z);
    void draw();
private:
    void updateModelMatrix();

    Texture texture;
    VertexBuffer* vertexBuffer;
    VertexArray* vertexArray;
    Shader* shader;
    glm::vec3 position;
};