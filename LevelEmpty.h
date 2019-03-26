//
// Created by td on 3/19/18.
//

#ifndef MYGAME_LEVELEMPTY_H
#define MYGAME_LEVELEMPTY_H


#include "Level.h"

class LevelEmpty : public Level {

public:
    LevelEmpty();
    void startEvent(Player *player);
};


#endif //MYGAME_LEVELEMPTY_H
