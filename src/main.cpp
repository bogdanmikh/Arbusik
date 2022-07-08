#include <iostream>
#include <chrono>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Window/Window.hpp"
#include "Game/Camera.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Shader.hpp"
#include "Renderer/VertexBuffer.hpp"
#include "Renderer/VertexBufferLayout.hpp"
#include "Renderer/VertexArray.hpp"
#include "Renderer/Texture.hpp"

int         maximumFps = 60;
uint64_t    oneSecondTimeCount = 0;
uint64_t    deltaTimeMillis = 0;
int         thisSecondFramesCount = 0;
uint64_t    timeMillis;
int         fps;

uint64_t getMillis() {
    auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    return now.count();
}

int main() {
    glm::vec2 resolution = { 640.f, 480.f };
    glm::vec2 mousePos = { 0., 0. };

    std::cout << "Arbusik version 0.2\n";
    Window window("OpenGl", resolution.x, resolution.y);
    
    float *data = new float[24] {
         1.f, 1.f, 1.f, 0.f,
        -1.f, 1.f, 0.f, 0.f,
        -1.f, -1.f, 0.f, 1.f,
         1.f, -1.f, 1.f, 1.f,
        -1.f, -1.f, 0.f, 1.f,
         1.f, 1.f, 1.f, 0.f
    };
    VertexBuffer buffer(data, sizeof(float) * 24);

    Texture texture("../../resources/textures/Ship.png");
    Shader shader("../../resources/shaders/vst.glsl","../../resources/shaders/fst.glsl");

    VertexBufferLayout layout;
    layout.push<glm::vec2>(1);
    layout.push<glm::vec2>(1);

    VertexArray vertexArray;
    vertexArray.addBuffer(buffer, layout);

    Renderer::setClearColor(1.0f, 0.5f, 0.7f, 1.0f);

    glm::vec3 position(0.f, 0.f, 1.f);
    Camera camera;
    camera.setShader(&shader);
    camera.setFieldOfView(glm::radians(60.f));
    camera.setRotation(0.f, 0.f, 0.f);
    camera.setPosition(0.f, 0.f, 5.f);

    timeMillis = getMillis();
    float bias = 1.2f;
    float n = 0.1f;
    window.toggleCursorLock();
    while (window.shouldClose() == false) {
        uint64_t lastTime = timeMillis;
        timeMillis = getMillis();
        deltaTimeMillis += timeMillis - lastTime;
        if (deltaTimeMillis < (1000 / maximumFps)) {
            continue;
        }
        oneSecondTimeCount += deltaTimeMillis;

        thisSecondFramesCount++;
        if (oneSecondTimeCount >= 1000) {
            fps = thisSecondFramesCount;
            std::cout << "FPS: " << fps << std::endl;
            thisSecondFramesCount = 0;
            oneSecondTimeCount = 0;
        }

        double deltaTime = deltaTimeMillis / 1000.0;
        deltaTimeMillis = 0;
        Renderer::clear();

        glm::vec2 newMousePos = window.getCursorPos();
        camera.rotate((mousePos.y - newMousePos.y) * n, (mousePos.x - newMousePos.x) * n, 0.f);
        mousePos = newMousePos;

        vertexArray.bind();

        texture.bind();

        shader.use();
        shader.setFloat("u_time", window.getTime());
        shader.setVec2("u_resolution", { resolution.x, resolution.y });
        shader.setVec2("u_mouse", { mousePos.x, resolution.y - mousePos.y });

        shader.setMat4("model", glm::mat4(1.f));

        Renderer::drawArrays(6);
        
        if(window.isKeyPressed(Key::ESCAPE)) {
            window.setShouldClose();
        }

        if(window.isKeyPressed(Key::W)) {
            camera.translateLocal(0.f, 0.f, bias * deltaTime);
        } else if(window.isKeyPressed(Key::D)) {
            camera.translateLocal(bias * deltaTime, 0.f, 0.f);
        } else if(window.isKeyPressed(Key::A)) {
            camera.translateLocal(-bias * deltaTime, 0.f, 0.f);
        } else if(window.isKeyPressed(Key::S)) {
            camera.translateLocal(0.f, 0.f, -bias * deltaTime);
        }

        resolution = window.getSize();
        camera.updateAspectRatio(resolution.x / resolution.y);
        Renderer::setRenderBufferSize(resolution.x, resolution.y);

        window.swapBuffers();
        window.pollEvents();
    }

    delete[] data;
}
