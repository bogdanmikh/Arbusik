#include "Application.hpp"

#include "Renderer/Renderer.hpp"
#include "Game/Scripts/Player.hpp"
#include "Game/Scripts/Ground.hpp"

#include <chrono>
#include <iostream>
#include <glm/glm.hpp>

uint64_t getMillis() {
    auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    return now.count();
}

Application* Application::s_instance;

Application* Application::getInstance() {
    return s_instance;
}

Application::Application() {
    s_instance = this;
    std::cout << "Arbusik version 0.2\n";

    window = new Window("OpenGl", 640, 480);
    Renderer::init();

    shader = new Shader("../../resources/shaders/vst.glsl","../../resources/shaders/fst.glsl");

    world.addActor(new Player(shader));
    auto ground = new Ground(shader);
    ground->setPosition(-5.f, 0.f, 0.f);
    ground->setSize(10.f, 6.f);
    world.addActor(ground);

    Renderer::setClearColor(1.0f, 0.5f, 0.7f, 1.0f);

    camera = new Camera;
    camera->setShader(shader);
    camera->setFieldOfView(glm::radians(60.f));
    camera->setRotation(0.f, 0.f, 0.f);
    camera->setPosition(0.f, 0.f, 5.f);

    timeMillis = getMillis();
}

Application::~Application() {
    s_instance = nullptr;
    for(auto& actor: world.getAllActors()) {
        world.deleteActor(actor);
    }
    delete camera;
    delete shader;
    delete window;
}

void Application::loop() {
    while (window->shouldClose() == false) {
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

        world.update(deltaTime);

        if(window->isKeyPressed(Key::ESCAPE)) {
            window->setShouldClose();
        }

        glm::vec2 resolution = window->getSize();
        camera->updateAspectRatio(resolution.x / resolution.y);
        Renderer::setRenderBufferSize(resolution.x, resolution.y);

        window->swapBuffers();
        window->pollEvents();
    }
}