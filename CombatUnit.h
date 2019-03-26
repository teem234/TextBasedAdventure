//
// Created by td on 3/9/18.
//

#ifndef MYGAME_COMBATUNIT_H
#define MYGAME_COMBATUNIT_H


#include <string>

class CombatUnit {

public:
    CombatUnit();
    CombatUnit(double health, double damage);
    void takeDamage(double amount);

    virtual void attack()=0;
    virtual void attack(CombatUnit*)=0;
    double getHealth();
    double getDamage();
    std::string getName();
    void addHealth(double amount);
    void addDamage(double amount);
    std::string name;


private:
    double health;

    double baseDamage;

};


#endif //MYGAME_COMBATUNIT_H
