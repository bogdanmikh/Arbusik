#pragma once

#include "Window/Window.hpp"
#include "Game/World.hpp"
#include "Game/Core/Camera.hpp"
#include "Renderer/Shader.hpp"
#include "Game/Scripts/Player.hpp"

class Application {
public:
    Application();
    ~Application();
    void loop();

    World world;
    Window* window;
    Shader* shader;
    Camera* camera;    
    int fps;
    static Application* getInstance();

private:
    static Application* s_instance;

    int         maximumFps = 60;
    uint64_t    oneSecondTimeCount = 0;
    uint64_t    deltaTimeMillis = 0;
    int         thisSecondFramesCount = 0;
    uint64_t    timeMillis;
    bool looking_cursor = true;
};