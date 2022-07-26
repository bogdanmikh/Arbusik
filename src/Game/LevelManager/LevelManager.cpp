#include "LevelManager.hpp"

#include "Game/Levels/FirstLevel.hpp"
#include "Game/Levels/SecondLevel.hpp"

int currentLevelIndex = 0;
// Когда добавишь еще уровни, прибавляй
const int numberOfLevels = 2;

Level* createCurrentLevel() {
    if (currentLevelIndex == 0) {
        return new FirstLevel();
    } else if (currentLevelIndex == 1) {
        return new SecondLevel();
    } else {
        // не должно происходить
        assert(false);
    }
    // else if (currentLevelIndex == 3) {
    //     return new ThirdLevel();
    // }
}

void increaseLevelNumber() {
    currentLevelIndex++;
    if (currentLevelIndex == numberOfLevels) {
        currentLevelIndex = 0;
    }
}