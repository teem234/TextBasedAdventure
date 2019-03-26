//
// Created by td on 3/9/18.
//


#include "LevelNode.h"
#include "LevelShop.h"


int LevelNode::levelcount=1;

LevelNode::LevelNode(Level *level){
    levelcount++;
    containedLevel = level;

}

LevelNode::LevelNode() {
    //std::cout << "Level " << levelcount <<" generated" << std::endl;
    levelcount++;
    int randomNum = rand() % 25 + 1;

    if (randomNum < 5) {
        containedLevel = new LevelChest();
    }
    else if (randomNum >=5 && randomNum < 13) {
        containedLevel = new LevelFight();
    }
    else if (randomNum >=13 && randomNum < 16){
        containedLevel = new LevelShop();
    }
    else {
        containedLevel = new LevelEmpty();
    }

}

Level *LevelNode::getLevel() {
    return this->containedLevel;
}