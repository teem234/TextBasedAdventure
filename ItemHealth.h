//
// Created by td on 3/18/18.
//

#ifndef MYGAME_ITEMHEALTH_H
#define MYGAME_ITEMHEALTH_H


#include "Item.h"

class ItemHealth : public Item {

public:
    ItemHealth();
    ItemHealth(int cost);
    void useItem(CombatUnit *unit);
};


#endif //MYGAME_ITEMHEALTH_H
