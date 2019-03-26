//
// Created by td on 3/9/18.
//

#ifndef MYGAME_ITEM_H
#define MYGAME_ITEM_H


#include <string>
#include "CombatUnit.h"


class Item {
public:
    Item(std::string name);
    Item(std::string name, int goldCost);
    std::string getName();
    int getCost();
    virtual void useItem(CombatUnit *unit)=0;

private:
    std::string name;
    int goldCost;

};


#endif //MYGAME_ITEM_H
