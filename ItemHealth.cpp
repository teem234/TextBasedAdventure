//
// Created by td on 3/18/18.
//

#include <iostream>
#include "ItemHealth.h"

ItemHealth::ItemHealth() : Item("Health Potion") {

}
ItemHealth::ItemHealth(int cost) : Item("Health Potion", cost){

}

void ItemHealth::useItem(CombatUnit *unit) {
    std::cout<< "Healing for "<< 35 << " health" <<std::endl;
    unit->addHealth(35);
}