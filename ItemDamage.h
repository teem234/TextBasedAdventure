//
// Created by td on 3/18/18.
//

#ifndef MYGAME_ITEMDAMAGE_H
#define MYGAME_ITEMDAMAGE_H


#include "Item.h"

class ItemDamage : public Item {

public:
    ItemDamage();
    ItemDamage(int cost);
    void useItem(CombatUnit *unit);
};

#endif //MYGAME_ITEMDAMAGE_H
