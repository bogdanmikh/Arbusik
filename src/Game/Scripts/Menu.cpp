#include "Menu.hpp"

#include <imgui.h>

#include "Application/Application.hpp"
#include "Game/LevelManager/LevelManager.hpp"

void Menu::update(double deltaTime) {
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);  
    ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize); 
    ImGui::SetCursorPos(ImVec2(300, 200));
    if(ImGui::Button("Level 1", ImVec2(200, 100))) {
        Application::getInstance()->loadLevel(createLevelWithIndex(0));
    }
    ImGui::SetCursorPos(ImVec2(300, 350));
    if(ImGui::Button("Level 2", ImVec2(200, 100))) {
        Application::getInstance()->loadLevel(createLevelWithIndex(1));
    }
    ImGui::SetCursorPos(ImVec2(300, 500));
    if(ImGui::Button("Exit", ImVec2(200, 100))) {
        Application::getInstance()->close();
    }
    ImGui::End();
}