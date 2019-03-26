//
// Created by td on 3/18/18.
//

#ifndef MYGAME_LEVELFIGHT_H
#define MYGAME_LEVELFIGHT_H

#include <algorithm>
#include "Level.h"
#include "Enemy.h"
#include <iostream>


class LevelFight : public Level{
public:
    LevelFight();
    void startEvent(Player *player);
private:
    std::vector<CombatUnit*> enemies;
    int enemAmount;
    void playerOptions(Player *player);
    void enemyAttack(Player *player);


};


#endif //MYGAME_LEVELFIGHT_H
