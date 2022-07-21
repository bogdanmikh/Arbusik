#include "Game/Scripts/GameOverLabel.hpp"
#include "Application/Application.hpp"
#include "Game/Levels/FirstLevel.hpp"

GameOverLabel::GameOverLabel(Shader* shader, Player* player) 
    : GameObject("../resources/textures/GameOverLabel.png", shader)
    , labelTime(0.0) {
    setPosition(player->getMinX() - 2.5, player->getMinY() - 2.5, 0.f);
    setSize(5.0, 5.0);
}

void GameOverLabel::update(double deltaTime) {
    labelTime += deltaTime;
    if(labelTime >= 1) {
        Application::getInstance()->loadLevel(new FirstLevel());
        return;
    }
    draw();
}