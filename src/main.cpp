#include <iostream>
#include <glm/glm.hpp>
#include "Window/Window.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Shader.hpp"
#include "Renderer/VertexBuffer.hpp"
#include "Renderer/VertexBufferLayout.hpp"
#include "Renderer/VertexArray.hpp"

int main() {
    glm::vec2 resolution = { 640., 480. };
    glm::vec2 mousePos = { 0., 0. };

    std::cout << "Arbusik version 0.2\n";
    Window window("OpenGl", resolution.x, resolution.y);
    
    float *data = new float[12] {
         1.f, 1.f,
        -1.f, 1.f,
        -1.f, -1.f,
         1.f, -1.f,
        -1.f, -1.f,
         1.f, 1.f
    };
    VertexBuffer buffer(data, sizeof(float) * 12);

    Shader shader("../../vst.glsl","../../fst.glsl");

    VertexBufferLayout layout;
    layout.push<glm::vec2>(1);

    VertexArray vertexArray;
    vertexArray.addBuffer(buffer, layout);

    Renderer::setClearColor(1.0f, 0.5f, 0.7f, 1.0f);
    while (window.shouldClose() == false) {
        Renderer::clear();
        mousePos = window.getCursorPos();

        vertexArray.bind();

        shader.use();
        shader.setFloat("u_time", window.getTime());
        shader.setVec2("u_resolution", { resolution.x, resolution.y });
        shader.setVec2("u_mouse", { mousePos.x, resolution.y - mousePos.y });

        Renderer::drawArrays(6);
        
        if(window.isKeyPressed(Key::ESCAPE)) {
            window.setShouldClose();
        }
        resolution = window.getSize();
        Renderer::setRenderBufferSize(resolution.x, resolution.y);

        window.swapBuffers();
        window.pollEvents();
    }

    delete[] data;
}
