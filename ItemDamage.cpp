//
// Created by td on 3/18/18.
//

#include <iostream>
#include "ItemDamage.h"

ItemDamage::ItemDamage() : Item("Damage Potion") {

}

ItemDamage::ItemDamage(int cost) : Item("Damage Potion" , cost){

}

void ItemDamage::useItem(CombatUnit *unit) {
    std::cout << "Adding " << 7 << " damage." << std::endl;
    unit->addDamage(7);
}
