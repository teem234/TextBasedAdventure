//
// Created by td on 3/9/18.
//

#ifndef MYGAME_PLAYER_H
#define MYGAME_PLAYER_H


#include <vector>


#include "ItemHealth.h"
#include "CombatUnit.h"

#include <iostream>


class Player : public CombatUnit {

public:
    Player();
    int getGold();
    void attack();
    void addGold(int amount);
    void attack(CombatUnit*);
    void heavyAttack(CombatUnit*);
    void strikeAttackMultiple(std::vector<CombatUnit*>);
    std::vector<Item*> getItems();
    std::vector<Item*> itemList;
    bool hasBeatBoss();
    bool setBeat();


private:
    bool bossBeat = false;
    int gold;


};


#endif //MYGAME_PLAYER_H
