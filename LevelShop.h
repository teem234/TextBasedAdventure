//
// Created by td on 3/19/18.
//

#ifndef MYGAME_LEVELSHOP_H
#define MYGAME_LEVELSHOP_H


#include "Level.h"

class LevelShop : public Level{
public:
    LevelShop();
    void startEvent(Player *player);

private:
    std::vector<Item*> inventory;
    int itemCount;
    int healthrng;
    int dmgrng;
};


#endif //MYGAME_LEVELSHOP_H
