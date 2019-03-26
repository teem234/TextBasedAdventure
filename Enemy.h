//
// Created by td on 3/9/18.
//

#ifndef MYGAME_ENEMY_H
#define MYGAME_ENEMY_H


#include "CombatUnit.h"
#include "Player.h"

class Enemy : public CombatUnit {

public:
    Enemy();
    Enemy(int health, int damage, std::string name);
    void attack();

    void attack(CombatUnit* player);
    void heavyAttack(CombatUnit* player);

private:
    //int health;



};


#endif //MYGAME_ENEMY_H
