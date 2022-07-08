#include "Sprite.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/VertexBufferLayout.hpp"

#include <glm/ext.hpp>

Sprite::Sprite(std::string texturePath, Shader* shader)
    : texture(texturePath)
    , position(0.f)
    , shader(shader) {
    updateModelMatrix();

    float *data = new float[24] {
         1.f, 1.f, 1.f, 0.f,
        -1.f, 1.f, 0.f, 0.f,
        -1.f, -1.f, 0.f, 1.f,
         1.f, -1.f, 1.f, 1.f,
        -1.f, -1.f, 0.f, 1.f,
         1.f, 1.f, 1.f, 0.f
    };
    vertexBuffer = new VertexBuffer(data, sizeof(float) * 24);
    delete[] data;

    VertexBufferLayout layout;
    layout.push<glm::vec2>(1);
    layout.push<glm::vec2>(1);

    vertexArray = new VertexArray();
    vertexArray->addBuffer(*vertexBuffer, layout);
}

Sprite::~Sprite() {
    delete vertexArray;
    delete vertexBuffer;
}

void Sprite::draw(){
    texture.bind();
    vertexArray->bind();
    updateModelMatrix();
    Renderer::drawArrays(6);
}

void Sprite::setPosition(float x, float y, float z) {
    if (position.x == x && position.y == y && position.z == z) {
        return;
    }
    position.x = x;
    position.y = y;
    position.z = z;
    updateModelMatrix();
}

void Sprite::updateModelMatrix() {
    shader->use();
    glm::mat4 model = glm::translate(glm::mat4(1.f), position);
    shader->setMat4("model", model);
}

