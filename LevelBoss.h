//
// Created by td on 3/19/18.
//

#ifndef MYGAME_LEVELBOSS_H
#define MYGAME_LEVELBOSS_H


#include "Level.h"
#include "Enemy.h"

class LevelBoss : public Level {

public:
    LevelBoss();
    void startEvent(Player *player);
private:
    std::vector<CombatUnit*> enemies;
    int enemAmount;
    void playerOptions(Player *player);
    void enemyAttack(Player *player);

};


#endif //MYGAME_LEVELBOSS_H
