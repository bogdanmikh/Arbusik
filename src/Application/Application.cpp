#include "Application.hpp"

#include "Renderer/Renderer.hpp"
#include "Game/Scripts/Player.hpp"
#include "Game/Scripts/Ground.hpp"
#include "Game/Scripts/Enemy.hpp"

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

    shader = new Shader("../resources/shaders/vst.glsl", "../resources/shaders/fst.glsl");

    camera = new Camera;
    camera->setShader(shader);
    camera->setFieldOfView(glm::radians(60.f));
    camera->setRotation(0.f, 0.f, 0.f);

    auto player = new Player(shader, camera);
    player->setSize(0.5f,0.5f);
    world.addActor(player);

    auto enemy_1 = new Enemy(shader, player);
    enemy_1->setSize(0.5f,0.5f);
    enemy_1->setPosition(-3.f, 0.f, 0.f);
    world.addActor(enemy_1);

    auto enemy_2 = new Enemy(shader, player);
    enemy_2->setSize(0.5f,0.5f);
    enemy_2->setPosition(-2.f, 0.f, 0.f);
    world.addActor(enemy_2);

    auto place1 = new Ground(shader);
    place1->setPosition(-5.f, -7.5f, 0.f);
    place1->setSize(10.f, 6.f);
    world.addActor(place1);
    
    auto place2 = new Ground(shader);
    place2->setPosition(1.f, -7.5f, 0.f);
    place2->setSize(10.f, 6.f);
    world.addActor(place2);

    auto place3 = new Ground(shader);
    place3->setPosition(-15.f, -7.5f, 0.f);
    place3->setSize(10.f, 6.f);
    world.addActor(place3);
    
    auto ground2 = new Ground(shader);
    ground2->setPosition(-4.f, 0.f, 0.f);
    ground2->setSize(1.f, 1.f);
    world.addActor(ground2);

    auto ground3 = new Ground(shader);
    ground3->setPosition(-2.f, -1.3f, 0.f);
    ground3->setSize(1.f, 1.f);
    world.addActor(ground3);

    auto ground4 = new Ground(shader);
    ground4->setPosition(1.f, 0.5f, 0.f);
    ground4->setSize(1.f, 0.1f);
    world.addActor(ground4);


    auto ground6 = new Ground(shader);
    ground6->setPosition(1.5f, 1.0f, 0.f);
    ground6->setSize(1.f, 1.f);
    world.addActor(ground6);

    Renderer::setClearColor(.235f, .235f, .235f, 1.0f);

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
            close();
        }

        glm::vec2 resolution = window->getSize();
        camera->updateAspectRatio(resolution.x / resolution.y);
        Renderer::setRenderBufferSize(resolution.x, resolution.y);

        window->swapBuffers();
        window->pollEvents();
    }
}

void Application::close(){
    window->setShouldClose();
}
