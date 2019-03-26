//
// Created by td on 3/18/18.
//

#ifndef MYGAME_LEVELCHEST_H
#define MYGAME_LEVELCHEST_H


#include "Level.h"
#include <iostream>


class LevelChest : public Level {

public:
    LevelChest();
    void startEvent(Player *player);
};


#endif //MYGAME_LEVELCHEST_H
