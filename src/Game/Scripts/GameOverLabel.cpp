#include "Application/Application.hpp"
#include "Game/LevelManager/LevelManager.hpp"
#include "Game/Scripts/GameOverLabel.hpp"

GameOverLabel::GameOverLabel(Shader* shader, Player* player) 
    : Sprite("../resources/textures/GameOverLabel.png", shader)
    , labelTime(0.0) {
    setPosition(player->getMinX() - 2.5, player->getMinY() - 2.5, 0.f);
    setSize(5.0, 5.0);
}

void GameOverLabel::update(double deltaTime) {
    labelTime += deltaTime;
    std::cout << "LebelTime: " << labelTime << " deltaTime: " << deltaTime << '\n';
    if(labelTime >= 1) {
        Application::getInstance()->loadLevel(createCurrentLevel());
        return;
    }
    draw();
}