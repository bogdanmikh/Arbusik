#pragma once

#include "Game/Level.hpp"

Level* createCurrentLevel();

/// Прибавляет номер уровня на 1. 
/// Если текущий уровень последний - номер становится 0
void increaseLevelNumber();