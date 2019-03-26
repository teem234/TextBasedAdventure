//
// Created by td on 3/9/18.
//

#ifndef MYGAME_LEVELNODE_H
#define MYGAME_LEVELNODE_H


#include "Level.h"
#include "LevelChest.h"
#include "LevelFight.h"
#include "LevelEmpty.h"

class LevelNode {  //storage device for level objects

public:
    LevelNode();
    Level *getLevel();
    LevelNode(Level *level);

private:

    static int levelcount;
    bool isBeaten = false;

    Level *containedLevel;

};


#endif //MYGAME_LEVELNODE_H
