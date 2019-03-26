//
// Created by td on 3/18/18.
//

#include "Level.h"

char Level::getMapSymbol() {
    return this->mapSymbol;
}

Level::Level(char symbol){
    this->mapSymbol = symbol;
}
bool Level::isCompleted() {
    return this->completed;
}

void Level::setCompleted() {
    completed = true;
}